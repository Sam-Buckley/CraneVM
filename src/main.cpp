//include opcodes.h
#include "opcodes.hpp"
#include <iostream>
#include <functions.hpp>
#define ln std::cout << std::endl;
#define line "\n"
using namespace std;

int main() {
    printf("Hello, World!\n");
    cout << opcode_to_string(Opcode::ADD); ln;
    return 0;
}