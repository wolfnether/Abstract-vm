#ifndef TOPIC_HPP
#define TOPIC_HPP

#include "../operand/IOperand.hpp"
#include "Instruction.hpp"

class Token {
public:
    Token();

    Token(Token const &cpy);

    virtual ~Token();

    Token &operator=(Token const &cpy);

    IOperand &getValue();

    Instruction getInstruction() const;

    void setInstruction(Instruction ins);

private:
    Instruction instruction;
    IOperand value;
};

#endif