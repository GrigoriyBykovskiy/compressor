cmake_minimum_required(VERSION 3.15)
project(compressor_tmp C)

set(CMAKE_C_STANDARD 11)

add_executable(compressor_tmp HuffmanCode.c HUFFMAN.c HUFFMAN.h)