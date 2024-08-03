#include <writer.hpp>
#include <stream.hpp>
#include <reader.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <opcodes.hpp>
#include <functions.hpp>

void test_write () {
    Stream stream = Stream("test_read.cb");
    stream.read();
    Writer writer = Writer("test_write.cb");
    writer.write(stream);
    Stream stream2 = Stream("test_write.cb");
    stream2.read();
    if (stream.size() != stream2.size()) {
        std::cout << "Write test failed - Stream uneven" << std::endl;
        exit(1);
    }
    for (int i = 0; i < stream.size(); i++) {
        for (int j = 0; j < stream.instructions[i].operands.size(); j++) {
            if (stream.instructions[i].operands[j] != stream2.instructions[i].operands[j]) {
                std::cout << "Write test failed" << std::endl;
                exit(1);
            }
        }
    }
    std::cout << "Write test passed" << std::endl;
}

void write_data (std::string path, std::vector<char> data) {
    std::ofstream file(path + ".cb", std::ios::out | std::ios::binary);
    file.write(data.data(), data.size());
    file.close();
}

int main () {
    std::vector<char> data = {
        0, //ADD
        10, 5, //args
        38, 0 //halt code 0
    };
    write_data("test_read", data);
    test_write();
    return 0;
}