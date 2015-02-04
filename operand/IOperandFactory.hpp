#pragma once
#include <string>
#include "IOperand.hpp"
#include "eOperandType.hpp"

class IOperandFactory {
public:
    IOperand const *createOperand(eOperandType type, std::string const &value);

    IOperand const *createInt8(std::string const &value);

    IOperand const *createInt16(std::string const &value);

    IOperand const *createInt32(std::string const &value);

    IOperand const *createFloat(std::string const &value);

    IOperand const *createDouble(std::string const &value);

private:

    static IOperand const *(IOperandFactory::*aptr[5])(std::string const &);
};