#include <iostream>
#include <fstream>
#include <typeinfo>
#include "parser/Parser.hpp"

int main(int i, char **arg) {
    std::istream *in;
    Parser parser;

    if (i == 1)
        in = &std::cin;
    else {
        std::ifstream *file = new std::ifstream(arg[1]);
        if (!file->is_open()) {
            std::cerr << "Cannont open " << arg[1] << std::endl;
            return 1;
        }
        in = file;
    }
    try {
        std::list<Token> &tokenList = parser.parse(*in);
        for (Token &token:tokenList)
            std::cout << token.toString() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error !! : " << e.what() << std::endl;
        return -1;
    }

    return 0;
}