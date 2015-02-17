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

IOperand  const &Token::getValue() const{
    return *this->value;
}

void Token::setValue(IOperand const *value){
    this->value = value;
}

void Token::setInstruction(Instruction ins) {
    this->instruction = ins;
}