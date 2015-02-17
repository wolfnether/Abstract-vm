#pragma once

#include "../operand/IOperand.hpp"
#include "Instruction.hpp"

class Token {
public:
    Token();

    Token(Token const &cpy);

    virtual ~Token();

    Token &operator=(Token const &cpy);

    IOperand const &getValue() const;
    void setValue(IOperand const *value);

    Instruction getInstruction() const;

    void setInstruction(Instruction ins);

    std::string &toString();

private:
    Instruction instruction;
    IOperand const *value;

};