#include "opcodes.hpp"
#include "functions.hpp"
#include <string>




std::string opcode_to_string(Opcode opcode)
{
    switch (opcode)
    {
        case Opcode::ADD:          return "ADD";
        case Opcode::SUB:          return "SUB";
        case Opcode::MUL:          return "MUL";
        case Opcode::DIV:          return "DIV";
        case Opcode::MOD:          return "MOD";
        case Opcode::INC:          return "INC";
        case Opcode::DEC:          return "DEC";
        case Opcode::AND:          return "AND";
        case Opcode::OR:           return "OR";
        case Opcode::XOR:          return "XOR";
        case Opcode::NOT:          return "NOT";
        case Opcode::SHL:          return "SHL";
        case Opcode::SHR:          return "SHR";
        case Opcode::CMP_EQ:       return "CMP_EQ";
        case Opcode::CMP_NEQ:      return "CMP_NEQ";
        case Opcode::CMP_LT:       return "CMP_LT";
        case Opcode::CMP_GT:       return "CMP_GT";
        case Opcode::CMP_LTE:      return "CMP_LTE";
        case Opcode::CMP_GTE:      return "CMP_GTE";
        case Opcode::PUSH:         return "PUSH";
        case Opcode::POP:          return "POP";
        case Opcode::DUP:          return "DUP";
        case Opcode::SWAP:         return "SWAP";
        case Opcode::JMP:          return "JMP";
        case Opcode::JMP_IF_TRUE:  return "JMP_IF_TRUE";
        case Opcode::JMP_IF_FALSE: return "JMP_IF_FALSE";
        case Opcode::CALL:         return "CALL";
        case Opcode::RET:          return "RET";
        case Opcode::LOAD:         return "LOAD";
        case Opcode::STORE:        return "STORE";
        case Opcode::IN:           return "IN";
        case Opcode::OUT:          return "OUT";
        case Opcode::MOV:          return "MOV";
        case Opcode::LOAD_REG:     return "LOAD_REG";
        case Opcode::STORE_REG:    return "STORE_REG";
        case Opcode::LAB:          return "LAB";
        case Opcode::SYS:          return "SYS";
        case Opcode::NOP:          return "NOP";
        case Opcode::HALT:         return "HALT";
    }
    return "UNKNOWN_OPCODE";
}

Opcode opcode_from_number(int opcode) {
    return static_cast<Opcode>(opcode);
}

std::string opstr_from_number(int operand) {
    return opcode_to_string(opcode_from_number(operand));
}