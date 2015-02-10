#include <sstream>
#include <iostream>
#include <limits>

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
    int buf;
    int64_t buf2;
    double v;

    ss << value;
    ss >> v;
    ss >> buf2;
    buf = v;

    /*std::cout << buf << " " << buf2;
    if (v > 0 && buf != buf2)
        std::cout << "overflow" << std::endl;
    if (v < 0 && buf != buf2)
        std::cout << "underflow" << std::endl;

    ::testNumber<double, float>(v);*/

    return new Operand(eOperandType::Float, v);
}

IOperand const *IOperandFactory::createInt32(std::string const &value) {
    std::stringstream ss;
    int64_t v;

    ss << value;
    ss >> v;

    testNumber<int64_t, int32_t>(v);

    return new Operand(eOperandType::Int32, v);
}

IOperand const *IOperandFactory::createInt16(std::string const &value) {
    std::stringstream ss;
    int v;

    ss << value;
    ss >> v;

    testNumber<int32_t, int16_t>(v);

    return new Operand(eOperandType::Int16, v);
}

IOperand const *IOperandFactory::createInt8(std::string const &value) {
    std::stringstream ss;
    int v;

    ss << value;
    ss >> v;

    testNumber<int32_t, int8_t>(v);

    return new Operand(eOperandType::Int8, v & 0xff);
}

IOperand const *(IOperandFactory::*IOperandFactory::aptr[5])(std::string const &) = {
        &IOperandFactory::createInt8,
        &IOperandFactory::createInt16,
        &IOperandFactory::createInt32,
        &IOperandFactory::createFloat,
        &IOperandFactory::createDouble
};
