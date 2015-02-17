#pragma once

#include <list>
#include <istream>
#include "Token.hpp"
#include "../exception/SyntaxException.hpp"
#include "../exception/UnknownInstructionException.hpp"
#include "../exception/UnderflowException.hpp"
#include "../exception/OverflowException.hpp"

class Parser {
public:
    Parser();

    ~Parser();

    static std::list<Token *> &parse(std::istream &in) throw(SyntaxException, UnknownInstructionExeption, UnderflowException, OverflowException);

private:
    static Token &parseInstruction(std::istream &in) throw(SyntaxException, UnknownInstructionExeption, UnderflowException, OverflowException);

    static IOperand const *parseValue(std::istream &in) throw(SyntaxException, UnderflowException, OverflowException);
};