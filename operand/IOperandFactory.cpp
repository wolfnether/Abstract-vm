#include <sstream>

#include "IOperandFactory.hpp"
#include "Operand.hpp"

IOperand const *IOperandFactory::createOperand(eOperandType type, std::string const &value) {
    return (this->*aptr[(int) type])(value);
}

IOperand const *IOperandFactory::createDouble(std::string const &value) {
    std::stringstream ss;
    double v;

    ss << value;
    ss >> v;

    return new Operand(eOperandType::Double, v);
}

IOperand const *IOperandFactory::createFloat(std::string const &value) {
    std::stringstream ss;
    float v;

    ss << value;
    ss >> v;

    return new Operand(eOperandType::Float, v);
}

IOperand const *IOperandFactory::createInt32(std::string const &value) {
    std::stringstream ss;
    int32_t v;

    ss << value;
    ss >> v;

    return new Operand(eOperandType::Int32, v);
}

IOperand const *IOperandFactory::createInt16(std::string const &value) {
    std::stringstream ss;
    int16_t v;

    ss << value;
    ss >> v;

    return new Operand(eOperandType::Int16, v);
}

IOperand const *IOperandFactory::createInt8(std::string const &value) {
    std::stringstream ss;
    int8_t v;

    ss << value;
    ss >> v;

    return new Operand(eOperandType::Int8, v);
}

IOperand const *(IOperandFactory::*IOperandFactory::aptr[5])(std::string const &) = {
        &IOperandFactory::createInt8,
        &IOperandFactory::createInt16,
        &IOperandFactory::createInt32,
        &IOperandFactory::createFloat,
        &IOperandFactory::createDouble
};
