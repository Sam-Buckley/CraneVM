#include "opcodes.hpp"
#include <functions.hpp>
//this is going to read files given a path
#include <fstream>
#include "reader.hpp"

Reader::Reader(std::string path)
{
    this->path = path;
}

std::vector<char> Reader::read() {
    // Initialize the file stream
    std::ifstream file(this->path, std::ios::binary);
    
    // Check if the file is open
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    // Determine the file size
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Initialize the vector of chars with the file size
    std::vector<char> data(size);

    // Read the entire file content into the vector
    if (!file.read(data.data(), size)) {
        throw std::runtime_error("Error reading file");
    }

    // Close the file
    file.close();

    // Return the data
    return data;
}