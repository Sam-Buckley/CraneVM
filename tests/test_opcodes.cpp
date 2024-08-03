#include <functions.hpp>
#include <iostream>
#include <string>
#include <opcodes.hpp>

void opcode_from_int_test() {
    //there are 37 opcodes in the Opcode enum, let's test them all
    auto i = 0;
    auto max = 37;
    while (i < max) {
        auto opcode = opcode_from_number(i);
        if (opcode != Opcode::NOP) {
            std::cout << "Opcode number " << i << " is " << opcode_to_string(opcode) << std::endl;
        }
        i++;
    }
}

int main() {
    opcode_from_int_test();
    printf("All tests passed!\n");
    return 0;
}