#include <writer.hpp>
#include <reader.hpp>
#include <stream.hpp>

//the cli module will contain the main function and the cli interface
//it will be responsible for parsing the arguments and calling the appropriate functions
//it will also contain the help message
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <functions.hpp>
#include <opcodes.hpp>

//function to parse the arguments
//usage: Crane [options] [input file] [output file]
//options:
//  -h, --help: show the help message
//  -v, --version: show the version
//  -r, --run: run the program
//  -d, --debug: run the program in debug mode
//  -c, --compile: compile the program
//  -t, --test: run the tests
//  -w, --write: write the output to the file
//  -p, --print: print the output to the console
//  -s, --step: step through the program
//  -l, --list: list the instructions
//  -i, --info: show the info
//  -a, --assemble: assemble the program
//  -b, --disassemble: disassemble the program
void print_help() {
    std::cout << "Usage: Crane [options] [input file] [output file]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help        Show the help message" << std::endl;
    std::cout << "  -v, --version     Show the version" << std::endl;
    std::cout << "  -r, --run         Run the program" << std::endl;
    std::cout << "  -d, --debug       Run the program in debug mode" << std::endl;
    std::cout << "  -c, --compile     Compile the program" << std::endl;
    std::cout << "  -t, --test        Run the tests" << std::endl;
    std::cout << "  -w, --write       Write the output to the file" << std::endl;
    std::cout << "  -p, --print       Print the output to the console" << std::endl;
    std::cout << "  -s, --step        Step through the program" << std::endl;
    std::cout << "  -l, --list        List the instructions" << std::endl;
    std::cout << "  -i, --info        Show the info" << std::endl;
    std::cout << "  -a, --assemble    Assemble the program" << std::endl;
    std::cout << "  -b, --disassemble Disassemble the program" << std::endl;
}
void parse_args(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Crane: missing file operand" << std::endl;
        std::cout << "Try 'Crane --help' for more information." << std::endl;
        print_help();
        exit(1);
    }

    std::string arg = argv[1];

    if (arg == "-h" || arg == "--help") {
        print_help();
        exit(0);
    } else if (arg == "-v" || arg == "--version") {
        std::cout << "Crane version 0.1" << std::endl;
        exit(0);
    } else if (arg == "-r" || arg == "--run") {
        // run the program
    } else if (arg == "-d" || arg == "--debug") {
        // run the program in debug mode
    } else if (arg == "-c" || arg == "--compile") {
        // compile the program
    } else if (arg == "-t" || arg == "--test") {
        // run the tests
    } else if (arg == "-w" || arg == "--write") {
        // write the output to the file
        if (argc < 4) {
            std::cout << "Crane: missing file operand" << std::endl;
            std::cout << "Try 'Crane --help' for more information." << std::endl;
            exit(1);
        }
        std::string input_file = argv[2];
        std::string output_file = argv[3];
        Stream stream = Stream(input_file);
        stream.read();
        Writer writer = Writer(output_file);
        writer.write(stream);
    } else if (arg == "-p" || arg == "--print") {
        Stream stream = Stream("test.cb");
        stream.read();
        stream.print();
    } else if (arg == "-s" || arg == "--step") {
        // step through the program
    } else if (arg == "-l" || arg == "--list") {
        // list the instructions
    } else if (arg == "-i" || arg == "--info") {
        // show the info
    } else if (arg == "-a" || arg == "--assemble") {
        // assemble the program
    } else if (arg == "-b" || arg == "--disassemble") {
        // disassemble the program
    } else {
        std::cout << "Crane: invalid option -- '" << arg << "'" << std::endl;
        std::cout << "Try 'Crane --help' for more information." << std::endl;
        exit(1);
    }
}



int main(int argc, char* argv[]) {
    //write \0 \5\ \10 to test.cb
    //open test.cb with fstream
    auto file = std::fstream("test.cb", std::ios::out | std::ios::binary);
    file.write("\0\5\10", 3);
    file.close();
    parse_args(argc, argv);
    return 0;
}