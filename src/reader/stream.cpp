//define constructor for stream class
#include "stream.hpp"
#include <iostream>
#include <vector>
#include <functions.hpp>
#include <opcodes.hpp>
#include <fstream>
//define the amount of operands for each opcode in an array
const int operands_amount[] = {
    2, 2, 2, 2, 2, // ADD, SUB, MUL, DIV, MOD
    1, 1,          // INC, DEC
    2, 2, 2, 1,    // AND, OR, XOR, NOT
    2, 2,          // SHL, SHR
    2, 2, 2, 2, 2, 2, // CMP_EQ, CMP_NEQ, CMP_LT, CMP_GT, CMP_LTE, CMP_GTE
    1, 1,          // PUSH, POP
    0, 0,          // DUP, SWAP
    1, 1, 1, 1,    // JMP, JMP_IF_TRUE, JMP_IF_FALSE, CALL
    0,             // RET
    2, 2,          // LOAD, STORE
    1, 1,          // IN, OUT
    2, 2, 2,       // MOV, LOAD_REG, STORE_REG
    1,             // LAB
    0, 0,          // SYS, NOP
    1              // HALT
};
Stream::Stream(std::string path) {
    //initialize the reader with the path
    this->reader = Reader(path);
}

int Stream::size() {
    //return the size of the instructions vector
    return this->instructions.size();
}

void Stream::read() {
    //read the file and store the data in a vector of chars
    std::vector<char> data = this->reader.read();
    //read the data directly into data
    for (int i = 0; i < data.size(); i++) {
        //create a new instruction
        Instruction instruction;
        //set the opcode to the current char
        instruction.opcode = static_cast<Opcode>(data[i]);
        //check if the opcode is valid
        if (instruction.opcode < Opcode::ADD || instruction.opcode > Opcode::HALT) {
            //if it is not, print an error message and return
            std::cerr << "Invalid opcode: " << static_cast<int>(data[i]) << std::endl;
            return;
        }
        //get the amount of operands for the opcode
        int amount = operands_amount[static_cast<char>(instruction.opcode)];
        //read the operands
        for (int j = 0; j < amount; j++) {
            //add the operand to the operands vector
            i++;
            instruction.operands.push_back(data[i]);
        }
        //log the length of the operands vector
        //add the instruction to the instructions vector
        this->instructions.push_back(instruction);
    }
}

void Stream::print() {
    //print the instructions
    for (int i = 0; i < this->instructions.size(); i++) {
        //get the current instruction
        Instruction instruction = this->instructions[i];
        //print the opcode
        std::cout << opcode_to_string(instruction.opcode) << " ";
        //print the operands
        for (int j = 0; j < instruction.operands.size(); j++) {
            std::cout << static_cast<int>(instruction.operands[j]) << " ";
        }
        std::cout << std::endl;
    }
}