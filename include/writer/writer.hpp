//this module contains the writer class which is responsible for writing the output to the file
//it takes a stream as inpit and writes the output to the file
//it also contains the function to write the output to the file

#ifndef WRITER_HPP
#define WRITER_HPP

#include <fstream>
#include <vector>
#include <stream.hpp>

class Writer {
    public:
        Writer() = default;
        Writer(std::string path);
        void write(Stream stream);
    private:
        std::string path;
};

#endif