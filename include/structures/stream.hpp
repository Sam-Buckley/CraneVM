//this file will contain the stream class, which is a glorified vector of Instructions
//it will be used to store the instructions and provide a way to read them
#ifndef STREAM_HPP
#define STREAM_HPP
#include <vector>
#include <iostream>
#include <fstream>
#include <functions.hpp>
#include <opcodes.hpp>
#include <reader.hpp>

class Stream {
    public:
        Stream () = default;
        Stream (std::string path);
        void read();
        void print();
        int size();
        std::vector<Instruction> instructions;
    private:
        Reader reader;
};

#endif