#include <stringstream>

#include "IOperandFactory.hpp"
#include "OperandDouble.hpp"
#include "OperandFloat.hpp"
#include "OperandInt32.hpp"
#include "OperandInt16.hpp"
#include "OperandInt8.hpp"

IOperand const * IOperandFactory::createOperand(eOperandType type, std::string const &value) const {
    return aptr[type];
}

IOperand const * IOperandFactory::createDouble(std::string const& value) const {
    std::stringstream ss;
    double v;

    ss << value;
    ss >> v;
    return new OperandDouble(v);
}

IOperand const * IOperandFactory::createFloat(std::string const &value) const {
    std::stringstream ss;
    float v;

    ss << value;
    ss >> v;
    return new OperandFloat(v);
}

IOperand const * IOperandFactory::createInt32(std::string const &value) const {
    std::stringstream ss;
    int32_t v;

    ss << value;
    ss >> v;
    return new OperandInt32(v);
}

IOperand const * IOperandFactory::createInt16(std::string const &value) const {
    std::stringstream ss;
    int16_t v;

    ss << value;
    ss >> v;
    return new OperandInt16(v);
}

IOperand const * IOperandFactory::createInt8(std::string const &value) const {
    std::stringstream ss;
    int8_t v;

    ss << value;
    ss >> v;
    return new OperandInt8(v);
}

IOperandFactory::aptr = {
        IOperandFactory::createInt8,
        IOperandFactory::createInt16,
        IOperandFactory::createInt32,
        IOperandFactory::createFloat,
        IOperandFactory::createDouble
};