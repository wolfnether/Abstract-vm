#pragma once

#include <list>
#include <istream>
#include "Token.hpp"

class Parser {
public:
    Parser();

    ~Parser();

    static std::list<Token *> &parse(std::istream &in);

private:
    static Token &parseInstruction(std::istream &in);

    static IOperand const *parseValue(std::istream &in);
};