#pragma once

#include <list>
#include <istream>
#include "Token.hpp"
#include "../exception/SyntaxException.hpp"
#include "../exception/UnknownInstructionException.hpp"

class Parser {
public:
    Parser();

    ~Parser();

    static std::list<Token *> &parse(std::istream &in) throw(SyntaxException,UnknownInstructionExeption);

private:
    static Token &parseInstruction(std::istream &in) throw(SyntaxException,UnknownInstructionExeption);

    static IOperand const *parseValue(std::istream &in) throw(SyntaxException);
};