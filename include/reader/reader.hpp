//this will contain the reader class, which will be used to read the input file and store the data in a vector of ints
#ifndef READER_HPP
#define READER_HPP
#include <string>
#include <vector>
class Reader {
    public:
        Reader() = default;
        Reader(std::string path);
        std::vector<char> read();
    private:
        std::string path;
};
#endif
