#include "common.h"

extern Npc *npc;
extern Cpu *cpu;

#include <fstream>
#include <ctime>

// 简单获取日期和时间字符串
static std::string now_date() {
    time_t t = time(nullptr);
    tm *lt = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%Y-%m-%d", lt);
    return buf;
}

static std::string now_time() {
    time_t t = time(nullptr);
    tm *lt = localtime(&t);
    char buf[16];
    strftime(buf, sizeof(buf), "%H:%M:%S", lt);
    return buf;
}

void dump_performance() {
     // 覆盖写入，文件中只保留最近一次的性能数据，使用 key=value 形式便于脚本解析
     std::ofstream ofs("/home/ysyx/project/ysyx-workbench/npc/performance.txt",
                       std::ios::out | std::ios::trunc);

     double ipc     = (npc->cycs == 0) ? 0.0 : (double)npc->icount / (double)npc->cycs;
     double ifu_occ = (npc->cycs == 0) ? 0.0 : (double)npc->ifutimer / (double)(npc->cycs * 2);
     double lsu_occ = (npc->cycs == 0) ? 0.0 : (double)npc->iotimer / (double)(npc->cycs * 2);

     ofs << "date="          << now_date()            << '\n'
         << "time="          << now_time()            << '\n'
         << "end_pc=0x"      << std::hex << cpu->con.pc << std::dec << '\n'
         << "total_cycle="   << npc->cycs            << '\n'
         << "total_inst="    << npc->icount          << '\n'
         << "ipc="           << ipc                  << '\n'
         << "ifu_count="     << npc->ifucount        << '\n'
         << "ifu_time="      << npc->ifutimer        << '\n'
         << "ifu_occupied="  << ifu_occ              << '\n'
         << "lsu_count="     << npc->iocount         << '\n'
         << "lsu_time="      << npc->iotimer         << '\n'
         << "lsu_occupied="  << lsu_occ              << '\n'
         << "exu_count="     << npc->exucount        << '\n';
}

void deal_statistic() {
    printf("ended at pc = 0x%08x\n", cpu->con.pc);
    printf(COLOR_BLUE "statistic: \n" );
    printf("  total cycle: %llu\n", npc->cycs);
    printf("  total inst num: %u\n", npc->icount);
    printf("  ipc: %f\n", ((double)npc->icount / (double)npc->cycs));
    printf("  ifu count %u, time %llu, occupied %f\n", npc->ifucount, npc->ifutimer, (double)npc->ifutimer / (npc->cycs * 2));
    printf("  lsu count %u, time %llu, occupied %f\n", npc->iocount, npc->iotimer, (double) npc->iotimer / (npc->cycs * 2));
    printf("  exu count: %u\n" COLOR_RESET, npc->exucount);

    if(need_dump_perform()) {
        dump_performance();
    }
}

