#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
#include "opcodes.hpp"
#include <iostream>


std::string opcode_to_string(Opcode opcode);
//opcode from number
Opcode opcode_from_number(int opcode);

//operand str from number
std::string opstr_from_number(int operand);



#endif