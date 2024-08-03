cmake_minimum_required(VERSION 3.10)
project(CraneVM)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add include directory
include_directories(include include/reader include/structures)

# Add source files
set(SOURCES src/main.cpp src/structs/opcodes_funcs.cpp)

# Add executable
add_executable(CraneVM ${SOURCES})
add_executable(cvm ${SOURCES}) # Alias for the executable

enable_testing()

add_executable(debug_opcodes tests/test_opcodes.cpp src/structs/opcodes_funcs.cpp)
add_executable(debug_stream tests/test_stream_init.cpp src/reader/stream.cpp src/reader/reader.cpp src/structs/opcodes_funcs.cpp)

add_test(NAME Debug_Opcodes COMMAND debug_opcodes)
add_test(NAME Debug_Stream COMMAND debug_stream)