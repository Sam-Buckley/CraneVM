cmake_minimum_required(VERSION 3.10)
project(CraneVM)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add include directory
include_directories(include include/reader include/structures include/writer)

# Add source files
set(SOURCES src/main.cpp src/structs/opcodes_funcs.cpp src/reader/stream.cpp src/reader/reader.cpp src/writer/writer.cpp) 

# Add executable
add_executable(Crane ${SOURCES})

enable_testing()

# Tests

# add_executable(debug_opcodes tests/test_opcodes.cpp src/structs/opcodes_funcs.cpp)
# add_executable(debug_stream tests/test_stream_init.cpp src/reader/stream.cpp src/reader/reader.cpp src/structs/opcodes_funcs.cpp)
# add_executable(debug_write tests/test_write.cpp src/reader/stream.cpp src/reader/reader.cpp src/structs/opcodes_funcs.cpp src/writer/writer.cpp)

# #add_test(NAME Debug_Opcodes COMMAND debug_opcodes)
# add_test(NAME Debug_Stream COMMAND debug_stream)
# add_test(NAME Debug_Write COMMAND debug_write)