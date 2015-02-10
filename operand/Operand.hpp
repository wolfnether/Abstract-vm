#pragma once

#include <iostream>
#include <limits>
#include <string>
#include "eOperandType.hpp"
#include "IOperand.hpp"

class Operand : public IOperand {
public:
    Operand(eOperandType type, double value);

    int getPrecision(void) const;

    eOperandType getType(void) const;

    double getValue(void) const;

    IOperand const *operator+(IOperand const &rhs) const;

    IOperand const *operator-(IOperand const &rhs) const;

    IOperand const *operator*(IOperand const &rhs) const;

    IOperand const *operator/(IOperand const &rhs) const;

    IOperand const *operator%(IOperand const &rhs) const;

    std::string const &toString(void) const;

private:
    Operand() {
    };

    Operand(Operand const &cpy);

    Operand const *operator=(Operand const &rhs) const;

    eOperandType type;
    double value;
};

template<typename T, typename V>
inline void testNumber(T v) {
    if (v > std::numeric_limits<V>::max())
        std::cout << "error overflow" << std::endl;
    if (v < std::numeric_limits<V>::min())
        std::cout << "error underflow" << std::endl;
}