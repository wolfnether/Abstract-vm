#include "Token.hpp"

Token::Token() {
}

Token::~Token() {
}

Token::Token(Token const &cpy) {
    this->operator=(cpy);
}

Token &Token::operator=(Token const &cpy) {
    this->instruction = cpy.instruction;
    this->value = cpy.value;
    return *this;
}

Instruction Token::getInstruction() const {
    return this->instruction;
}

IOperand &Token::getValue() {
    return this->value;
}

void Token::setInstruction(Instruction ins) {
    this->instruction = ins;
}