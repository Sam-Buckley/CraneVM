#ifndef MEM_HPP
#define MEM_HPP

#include <cstddef>

// Constants for memory sizes
const std::size_t PROGRAM_MEM_SIZE = 4 * 1024; // 4 KB - This includes registers, constants, program args, etc.
const std::size_t STACK_SIZE = 16 * 1024;      // 16 KB
const std::size_t HEAP_SIZE = 64 * 1024;       // 64 KB

// Struct to represent a memory block
struct Block {
    std::size_t start;
    std::size_t end;
    // Add other necessary data members here
};

// Struct to represent the memory
struct Memory {
    // Program memory
    Block program;
    // Stack memory
    Block stack;
    // Heap memory
    Block heap;
    // Add other necessary data members here
    char *mem;
    Memory() {
        mem = new char[PROGRAM_MEM_SIZE + STACK_SIZE + HEAP_SIZE];
        program.start = 0;
        program.end = PROGRAM_MEM_SIZE - 1;
        stack.start = PROGRAM_MEM_SIZE;
        stack.end = PROGRAM_MEM_SIZE + STACK_SIZE - 1;
        heap.start = PROGRAM_MEM_SIZE + STACK_SIZE;
        heap.end = PROGRAM_MEM_SIZE + STACK_SIZE + HEAP_SIZE - 1;
    }
    ~Memory() {
        delete[] mem;
    }
    // Add other necessary member functions here
    void write(std::size_t addr, char *data, std::size_t size) {
        for (std::size_t i = 0; i < size; i++) {
            mem[addr + i] = data[i];
        }
    }
    void read(std::size_t addr, char *data, std::size_t size) {
        for (std::size_t i = 0; i < size; i++) {
            data[i] = mem[addr + i];
        }
    }

    /*
        STACK
    */
   bool stack_empty() {
       return stack.start == stack.end;
    }
    void stack_push(char *data, std::size_t size) {
        if (stack.start + size > stack.end) {
            // Stack overflow
            return;
        }
        write(stack.start, data, size);
        stack.start += size;
    }
    void stack_pop(char *data, std::size_t size) {
        if (stack.start - size < stack.start) {
            // Stack underflow
            return;
        }
        stack.start -= size;
        read(stack.start, data, size);
    }
    void stack_swap() {
        if (stack.start - 2 < stack.start) {
            // Stack underflow
            return;
        }
        char temp[2];
        stack_pop(temp, 2);
        stack_push(temp, 2);
    }
};

#endif // MEM_HPP