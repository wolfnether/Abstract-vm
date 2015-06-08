#pragma once

#include <iostream>
#include <limits>
#include <string>
#include "eOperandType.hpp"
#include "IOperand.hpp"
#include "../exception/OverflowException.hpp"
#include "../exception/UnderflowException.hpp"

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
inline void testNumber(T v) throw(UnderflowException, OverflowException) {
    std::string str = std::to_string(v);
    if (v > std::numeric_limits<V>::max())
        throw OverflowException();
    if (v < std::numeric_limits<V>::min())
        throw UnderflowException();
}
