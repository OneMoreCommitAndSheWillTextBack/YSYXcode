#include "common.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string rl_gets() {
  std::string cmd;
  std::cout << "(npc) ";
  std::getline(std::cin, cmd);
  return cmd;
}

int cmd_help(const std::string &args);
int cmd_c(const std::string &args);
int cmd_q(const std::string &args);
int cmd_si(const std::string &args);
int cmd_info(const std::string &args);
int cmd_x(const std::string &args);

struct Command {
  const std::string name;
  const std::string description;
  int (*handler)(const std::string &args);
};

const Command cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NPC", cmd_q},
    {"si", "Run the program N steps, default is 1", cmd_si},
    {"info", "arg r to print reg, arg w to print watchpoint", cmd_info},
    // Add more commands here
};

#define NR_CMD sizeof(cmd_table) / sizeof(cmd_table[0])

int cmd_help(const std::string &args) {
  if (args.empty()) {
    for (const auto &cmd : cmd_table) {
      std::cout << cmd.name << " - " << cmd.description << std::endl;
    }
  } else {
    for (const auto &cmd : cmd_table) {
      if (cmd.name == args) {
        std::cout << cmd.name << " - " << cmd.description << std::endl;
        return 0;
      }
    }
    std::cout << "Unknown command '" << args << "'" << std::endl;
  }
  return 0;
}

int cmd_c(const std::string &args) {
  cpu_exec(-1);
  return 0;
}

int cmd_q(const std::string &args) {
  set_npc_quit();
  return -1;
}

int cmd_si(const std::string &args) {
  int times = 1;
  if (!args.empty()) {
    times = std::stoi(args);
    if (times <= 0) {
      times = -1;
    }
  }
  cpu_exec(times);
  return 0;
}

int cmd_info(const std::string &args) {
  if (args == "r") {
    // api to print reg
    display_reg();
  } else {
    // not implement
  }
  return 0;
}

int cmd_x(const std::string &args) {
  std::vector<std::string> arr;
  std::stringstream ss(args);
  std::string item;
  while (std::getline(ss, item, ' ')) {
    arr.push_back(item);
  }

  if (arr.size() != 2) {
    std::cout << "[error] get a invaild args: " << args << std::endl;
    return 0;
  }

  int times = std::stoi(arr[0], nullptr);
  if (times <= 0) {
    std::cout << "[error] get a invalid args: " << args << std::endl;
  }

  int addr = std::stoi(arr[1], nullptr, 16);
  for (int i = 0; i < times; i++) {
    std::cout << "0x" << std::hex << std::setfill('0') << std::setw(8) << addr
              << ' ';
    for (int j = 0; j < 4; j++) {
      int ret = pmem_read(addr, 1);
      std::cout << std::hex << std::setw(2) << std::setfill('0') << ret << ' ';
    }
    std::cout << std::dec << std::endl;
  }
  return 0;
}

void sdb_main() {
  while (true) {
    std::string str = rl_gets();
    if (str.empty()) {
      continue;
    }

    // Split the input string into command and arguments
    size_t space_pos = str.find(' ');
    std::string cmd =
        (space_pos == std::string::npos) ? str : str.substr(0, space_pos);
    std::string args =
        (space_pos == std::string::npos) ? "" : str.substr(space_pos + 1);

    size_t i = 0;
    for (i = 0; i < NR_CMD; ++i) {
      if (cmd_table[i].name == cmd) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      std::cout << "Unknown command '" << cmd << "'" << std::endl;
    }
  }
}
