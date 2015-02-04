#include <sstream>
#include "Operand.hpp"

Operand::Operand(eOperandType type, double value) : type(type), value(value) {
}

int Operand::getPrecision() const {
    return (int) this->getType();
}

eOperandType Operand::getType() const {
    return this->type;
}

double Operand::getValue() const {
    if (this->type == eOperandType::Int8)
        return (int8_t) this->value;
    else if (this->type == eOperandType::Int16)
        return (int16_t) this->value;
    else if (this->type == eOperandType::Int32)
        return (int32_t) this->value;
    else if (this->type == eOperandType::Float)
        return (float) this->value;
    return this->value;
}

IOperand const *Operand::operator+(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *Operand::operator-(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *Operand::operator*(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *Operand::operator/(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

IOperand const *Operand::operator%(IOperand const &rhs) const {
    (void) rhs;
    return this;
}

std::string const &Operand::toString() const {
    std::stringstream ss;
    std::string *str = new std::string();
    ss << this->type << " " << this->getValue();
    ss >> *str;
    return *str;
}