#include <writer.hpp>
#include <stream.hpp>
#include <functions.hpp>

// Constructor
Writer::Writer(std::string path) {
    this->path = path;
}
// Write the output to the file
void Writer::write(Stream stream) {
    std::ofstream file(this->path, std::ios::out | std::ios::binary);
    for (int i = 0; i < stream.size(); i++) {
        file.write((char*)&stream.instructions[i].opcode, sizeof(char));
        for (int j = 0; j < stream.instructions[i].operands.size(); j++) {
            file.write((char*)&stream.instructions[i].operands[j], sizeof(char));
        }
    }
    file.close();
}
