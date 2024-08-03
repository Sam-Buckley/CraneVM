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

/*void Writer::write(Stream stream) {
    std::ofstream file(this->path, std::ios::out | std::ios::binary);

    // Calculate the total number of bytes to be written
    size_t total_size = stream.size(); // Number of instructions
    for (const auto& instruction : stream.instructions) {
        total_size += instruction.operands.size(); // Add the number of operands
    }

    // Allocate a buffer to hold all the data
    std::vector<char> buffer(total_size);
    size_t index = 0;

    // Copy the opcodes and operands into the buffer
    for (const auto& instruction : stream.instructions) {
        buffer[index++] = static_cast<char>(instruction.opcode);
        for (const auto& operand : instruction.operands) {
            buffer[index++] = static_cast<char>(operand);
        }
    }

    // Write the buffer to the file in one operation
    file.write(buffer.data(), buffer.size());
    file.close();
}*/