#include "common.h"
#include <cassert>
#include <cstdint>
#include <stdio.h>
#include <string.h>
#include <unistd.h>      // 用于 fork(), close(), dup2()
#include <sys/types.h>   // 用于 pid_t, waitpid()
#include <sys/wait.h>    // 用于 waitpid()
#include <sys/stat.h>    // 用于 open()
#include <fcntl.h>       // 用于 O_WRONLY 等文件打开标志
#include <signal.h>      // 用于 kill(), raise(), SIGSTOP, SIGCONT

#include <sys/wait.h>

Npc *npc = NULL;
Cpu *cpu = NULL;
#ifdef TRACE
Trace *trace = NULL;
pid_t fork_pid_val = 0;
#endif

void demp_wave() {
#ifdef TRACE
  if (fork_interval_is_on()) {
    if(record_isenable()) {
      trace->context->timeInc(1);
      trace->tfp->dump(trace->context->time());
    }

    if(!record_isenable() && npc->cycs % fork_interval_val() == 0) {
      pid_t old = fork_pid_val;          
      pid_t pid = fork();
      if (pid == 0) {                /* child */
          // 关闭标准输出和错误输出，避免干扰
          close(STDOUT_FILENO);
          // 重定向到 /dev/null 更安全
          int null_fd = open("/dev/null", O_WRONLY);
          dup2(null_fd, STDOUT_FILENO);
          close(null_fd);
          // FIXME 由于被杀掉的子进程也会运行一小段时间，所以可能会对这个
          // 最终的子进程的trace造成影响， 应该想办法消除这一段影响
          signal(SIGUSR2, [](int) {
              set_record_enable();  // 收到SIGUSR2后开始记录
          });
          raise(SIGSTOP);

          while(!record_isenable()) {
            pause();
          }
      } else if (pid > 0) {          /* parent */
          fork_pid_val = pid;            
          if (old) {                 
              kill(old, SIGCONT);
              usleep(10000);
              kill(old, SIGKILL);
              waitpid(old, NULL, 0);
          }
      }      
    }
  } else {
    if (npc->cycs >= record_after_val()) {
      trace->context->timeInc(1);
      trace->tfp->dump(trace->context->time());
    }
  }
#endif
}

static void exe_once() {
  npc->top->clock = 1;
  npc->top->eval();
  demp_wave();
  npc->top->clock = 0;
  npc->top->eval();
  demp_wave();
  npc->cycs += 2;

#ifdef ITRACE
  char *p = cpu->logbuf;
  p += snprintf(p, sizeof(cpu->logbuf), "0x%08x:", cpu->con.pc);
  int i;
  p += snprintf(p, 10, " %08x", cpu->inst);
  memset(p, ' ', 1);
  p += 1;
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, cpu->logbuf + sizeof(cpu->logbuf) - p, cpu->con.pc,
              (uint8_t *)(&cpu->inst), 4);
#endif
}

static int start_diff = 0;
void trace_or_diff() {
#ifdef WATCH_POINT
  exe_wp();
#endif
#ifdef MEMORY_GUARD
  check_mem_guard();
#endif
#ifdef ITRACE
  printf("%s\n", cpu->logbuf);
#endif
#ifdef DIFFTEST
  if (start_diff < 1 && cpu->valid == 1)
    start_diff++;
  if (start_diff == 1 && cpu->valid == 1) {
    diff_step();
  }

#endif
}

static void execute(unsigned int n) {
  while (n--) {
    exe_once();
    trace_or_diff();
    if (npc->state != RUNNING)
      return;
  }
}

void cpu_exec(int n) {
  switch (npc->state) {
  case STOP:
    npc->state = RUNNING;
    break;
  case END:
  case ABORT:
    printf("the npc has finished, please restart the npc\n");
    return;
    break;
  default:
    npc->state = RUNNING;
  }

  execute((unsigned int)n);

  switch (npc->state) {
  case RUNNING:
    npc->state = STOP;
    break;
  case END:
    printf("hit the good-trap\n");
    break;
  case ABORT:
    printf("hit the bad-trap\n");
    printf("ended at pc = 0x%08x\n", cpu->con.pc);
    break;
  default:
    npc->state = STOP;
  }
}

#ifdef TRACE
static volatile sig_atomic_t child_finished = 0;
static void sigusr1_handler(int sig) {
    child_finished = 1;
}
#endif

// SIGUSR1 子进程结束信号 (子进程 -> 父进程)
// SIGUSR2 子进程开始记录信号 (父进程 -> 子进程)
void tfpclose() {
#ifdef TRACE
  if(fork_interval_is_on()) {
    if(record_isenable()) {
      fprintf(stderr, "close trace file\n");
      trace->tfp->close();
      kill(getppid(), SIGUSR1);
      exit(0);
    } else {
      // 父进程不进行记录， 但是在这里唤醒子进程
      if(fork_pid_val != 0) {
        int status;
        kill(fork_pid_val, SIGCONT); 
        kill(fork_pid_val, SIGUSR2);

        struct sigaction sa;
        sa.sa_handler = sigusr1_handler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sigaction(SIGUSR1, &sa, NULL);

        while (!child_finished) {
          usleep(10000);
        }

        fork_pid_val = 0;  // 重置 PIDint status;
        waitpid(fork_pid_val, &status, WNOHANG);
        
        fork_pid_val = 0;
        child_finished = 0;
      }
    }
  } else {
    trace->tfp->close();
  }
#endif
}

void set_npc_end() {
  int sig = cpu->con.gpr[10];

  if (sig == 0) {
    npc->state = END;
  } else {
    npc->state = ABORT;
  }
  tfpclose();
}

void set_npc_quit() {
  tfpclose();
  npc->state = QUIT;
}

void set_npc_stop() { npc->state = STOP; }

void npc_diff_quit() {
  tfpclose();
  npc->state = ABORT;
}

void set_diff_pass() { 
  #ifdef DIFFTEST
  set_ref_skip();
  #endif
}
