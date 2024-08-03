//define constructor for stream class
#include "stream.hpp"
#include <iostream>
#include <vector>
#include <functions.hpp>
#include <opcodes.hpp>
#include <fstream>
//define the amount of operands for each opcode in an array
const int operands_amount[] = {
    2, //ADD
    2, //SUB
    2, //MUL
    2, //DIV
    2, //MOD
    1, //INC
    1, //DEC
    2, //AND
    2, //OR
    2, //XOR
    1, //NOT
    2, //SHL
    2, //SHR
    2, //CMP_EQ
    2, //CMP_NEQ
    2, //CMP_LT
    2, //CMP_GT
    2, //CMP_LTE
    2, //CMP_GTE
    1, //PUSH
    1, //POP
    0, //DUP
    0, //SWAP
    1, //JMP
    1, //JMP_IF_TRUE
    1, //JMP_IF_FALSE
    1, //CALL
    0, //RET
    2, //LOAD
    2, //STORE
    1, //IN
    1, //OUT
    2, //MOV
    2, //LOAD_REG
    2, //STORE_REG
    1, //LAB
    0, //SYS
    0, //NOP
    1  //HALT
};

Stream::Stream(std::string path) {
    //initialize the reader with the path
    this->reader = Reader(path);
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