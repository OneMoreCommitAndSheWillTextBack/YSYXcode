// main.cpp
#include "Cache.h"
#include "Itraceparser.h"
#include <iostream>
#include <iomanip>
#include <string>

int main(int argc, char* argv[]) {
    // 默认值：参照 Verilog 中的 icache 配置
    // INDEX_LEN = 3, OFFSET_LEN = 2
    std::string trace_file = "itrace-log.txt";
    uint32_t block_size = 16;      // 2^OFFSET_LEN = 2^2 = 4 字节
    uint32_t line_num = 8;        // 2^INDEX_LEN = 2^3 = 8 个缓存行
    
    // 简单的命令行参数解析
    if (argc > 1) trace_file = argv[1];
    if (argc > 2) block_size = std::stoul(argv[2]);
    if (argc > 3) line_num = std::stoul(argv[3]);
    
    try {
        cachesim::CacheConfig config;
        config.cache_type = cachesim::CacheConfig::CacheTypeEnum::DirectMapped;
        config.block_size = block_size;
        config.line_num = line_num;
        
        cachesim::Cache cache(config);
        cachesim::ItraceParser parser(trace_file);
        
        if (!parser.is_open()) {
            std::cerr << "Error: Cannot open file: " << trace_file << std::endl;
            return 1;
        }

        cache.print_config();
        
        std::cout << "Processing " << trace_file << "..." << std::endl;
        
        uint64_t instruction_count = 0;
        parser.parse([&cache, &instruction_count](uint32_t pc) {
            cache.access(pc);
            ++instruction_count;
            
            // 每处理 10000 条指令输出一次进度（可选）
            if (instruction_count % 10000 == 0) {
                std::cout << "  Processed " << instruction_count << " instructions..." << std::endl;
            }
        });
        
        std::cout << "\n=== Cache Simulation Results ===" << std::endl;
        std::cout << "Total instructions: " << instruction_count << std::endl;
        std::cout << "Cache hits: " << cache.get_hit_time() << std::endl;
        std::cout << "Cache misses: " << cache.get_miss_time() << std::endl;
        std::cout << "Hit rate: " << std::fixed << std::setprecision(2)
                  << (1.0 - cache.get_miss_rate()) * 100.0 << "%" << std::endl;
        std::cout << "Miss rate: " << std::fixed << std::setprecision(2)
                  << cache.get_miss_rate() * 100.0 << "%" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}