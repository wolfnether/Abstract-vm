#pragma once
#include <string>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "../exception/SyntaxException.hpp"

class IOperandFactory {
public:
    IOperand const *createOperand(eOperandType type, std::string const &value) throw(SyntaxException);

    IOperand const *createInt8(std::string const &value) throw(SyntaxException);

    IOperand const *createInt16(std::string const &value) throw(SyntaxException);

    IOperand const *createInt32(std::string const &value) throw(SyntaxException);

    IOperand const *createFloat(std::string const &value) throw(SyntaxException);

    IOperand const *createDouble(std::string const &value) throw(SyntaxException);

private:

    static IOperand const *(IOperandFactory::*aptr[5])(std::string const &);
};