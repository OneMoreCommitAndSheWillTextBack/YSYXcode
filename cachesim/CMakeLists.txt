cmake_minimum_required(VERSION 3.15)
project(CacheSim VERSION 1.0.0 LANGUAGES CXX)

# 指定使用 g++ 编译器
set(CMAKE_CXX_COMPILER "g++")

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# g++ 编译选项
add_compile_options(-Wall -Wextra -Wpedantic)

# 源文件
add_executable(cachesim
    src/main.cpp
    src/Cache.cpp
    src/Itraceparser.cpp
)

# 包含目录
target_include_directories(cachesim PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# 设置输出目录
set_target_properties(cachesim PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)