#ifndef PARSER_HPP
#define PARSER_HPP

#include <list>
#include <istream>
#include "Token.hpp"
#include "IOperand.hpp"

class Parser {
public:
    Parser();

    ~Parser();

    static std::list<Token *> &parse(std::istream &in);

private:
    static Token &parseInstruction(std::istream &in);

    static IOperand &parseValue(std::istream &in);
};

#endif