// File path: bytecode_vm/opcodes.h

#ifndef OPCODES_H
#define OPCODES_H

#include <vector>
#include <string>

//define macros for opcodes
#define OPCODES_MAP(XX) \
    XX(ADD)            \
    XX(SUB)            \
    XX(MUL)            \
    XX(DIV)            \
    XX(MOD)            \
    XX(INC)            \
    XX(DEC)            \
    XX(AND)            \
    XX(OR)             \
    XX(XOR)            \
    XX(NOT)            \
    XX(SHL)            \
    XX(SHR)            \
    XX(CMP_EQ)         \
    XX(CMP_NEQ)        \
    XX(CMP_LT)         \
    XX(CMP_GT)         \
    XX(CMP_LTE)        \
    XX(CMP_GTE)        \
    XX(PUSH)           \
    XX(POP)            \
    XX(DUP)            \
    XX(SWAP)           \
    XX(JMP)            \
    XX(JMP_IF_TRUE)    \
    XX(JMP_IF_FALSE)   \
    XX(CALL)           \
    XX(RET)            \
    XX(LOAD)           \
    XX(STORE)          \
    XX(IN)             \
    XX(OUT)            \
    XX(MOV)            \
    XX(LOAD_REG)       \
    XX(STORE_REG)      \
    XX(LAB)            \
    XX(SYS)            \
    XX(NOP)            \
    XX(HALT)


enum class Opcode {
    // Arithmetic Operations
    ADD,            // Addition
    SUB,            // Subtraction
    MUL,            // Multiplication
    DIV,            // Division
    MOD,            // Modulus
    INC,            // Increment
    DEC,            // Decrement

    // Logical Operations
    AND,            // Logical AND
    OR,             // Logical OR
    XOR,            // Logical XOR
    NOT,            // Logical NOT
    SHL,            // Shift Left
    SHR,            // Shift Right

    // Comparison Operations
    CMP_EQ,         // Compare Equal
    CMP_NEQ,        // Compare Not Equal
    CMP_LT,         // Compare Less Than
    CMP_GT,         // Compare Greater Than
    CMP_LTE,        // Compare Less Than or Equal
    CMP_GTE,        // Compare Greater Than or Equal

    // Stack Manipulation
    PUSH,           // Push to stack
    POP,            // Pop from stack
    DUP,            // Duplicate top of stack
    SWAP,           // Swap top two elements of stack

    // Control Flow
    JMP,            // Unconditional Jump
    JMP_IF_TRUE,    // Jump if true
    JMP_IF_FALSE,   // Jump if false
    CALL,           // Call subroutine
    RET,            // Return from subroutine

    // Memory Operations
    LOAD,           // Load from memory
    STORE,          // Store to memory

    // Input/Output Operations
    IN,             // Input
    OUT,            // Output

    // Register Operations
    MOV,            // Move data between registers
    LOAD_REG,       // Load from register
    STORE_REG,      // Store to register

    // Function Operations
    LAB,           // Declare a label

    // System Operations
    SYS,            // System call

    // Miscellaneous
    NOP,            // No Operation
    HALT            // Halt execution
};

//structure for Instruction, opcodes may have 0, 1 or 2 operands
struct Instruction {
    Opcode opcode;
    std::vector<int> operands;
    Instruction() = default;
    Instruction(Opcode op, const std::vector<int> ops)
        : opcode(op), operands(ops) {}
};
 //function to convert opcode to string

#endif // OPCODES_H
