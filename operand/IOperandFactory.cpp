#include <sstream>
#include <iostream>
#include <limits>
#include "../exception/SyntaxException.hpp"
#include "eOperandType.hpp"
#include "IOperand.hpp"
#include "IOperandFactory.hpp"
#include "Operand.hpp"
#include <cinttypes>

void checkZ(std::string const& value) throw(SyntaxException)
{
	std::string::const_iterator it = value.begin();
	if (*it == '-')
		it++;
	if ('0' <= *it && *it <= '9')
		it++;
	else
		throw SyntaxException(value + " isn't a float number");
	for (; it != value.end(); ++it)
		if (!('0' <= *it && *it <= '9'))
			break;
	if (it != value.end() && *it == '.')
		it++;
	else
		throw SyntaxException(value + " isn't a float number");
	if ('0' <= *it && *it <= '9')
		it++;
	else
		throw SyntaxException(value + " isn't a float number");
	for (; it != value.end(); ++it)
		if (!('0' <= *it && *it <= '9'))
			break;
	if (it == value.end())
		return;
}

void checkN(std::string const& value) throw(SyntaxException)
{
	std::string::const_iterator it = value.begin();
	if (*it == '-')
		it++;
	if ('0' <= *it && *it <= '9')
		it++;
	else
		throw SyntaxException(value + " isn't an integer number");
	for (; it != value.end(); ++it)
		if (!('0' <= *it && *it <= '9'))
			break;
	if (it == value.end())
		return;
	else
		throw SyntaxException(value + " isn't an integer number");
}

IOperand const* IOperandFactory::createOperand(eOperandType type, std::string const& value) throw(SyntaxException, UnderflowException, OverflowException)
{
	return (this ->* aptr[(int) type])(value);
}

IOperand const* IOperandFactory::createDouble(std::string const& value) throw(SyntaxException)
{
	std::stringstream ss;
	double v;

	checkZ(value);
	ss << value;
	ss >> v;

	return new Operand(eOperandType::Double, v);
}

IOperand const* IOperandFactory::createOperand(eOperandType type, double value)
{
	return (this ->* aptrD[(int)type])(value);
}

IOperand const* IOperandFactory::createInt8(double value)
{
	testNumber<double, int8_t>(value);
	return new Operand(eOperandType::Int8, value);
}

IOperand const* IOperandFactory::createInt16(double value)
{
	testNumber<double, int16_t>(value);
	return new Operand(eOperandType::Int32, value);
}

IOperand const* IOperandFactory::createInt32(double value)
{
	testNumber<double, int32_t>(value);
	return new Operand(eOperandType::Int32, value);
}

IOperand const* IOperandFactory::createFloat(double value)
{
	testNumber<double, float>(value);
	return new Operand(eOperandType::Float, value);
}

IOperand const* IOperandFactory::createDouble(double value)
{
	return new Operand(eOperandType::Double, value);
}

IOperand const* IOperandFactory::createFloat(std::string const& value) throw(SyntaxException, UnderflowException, OverflowException)
{
	std::stringstream ss;
	double v;

	checkZ(value);
	ss << value;
	ss >> v;

	return new Operand(eOperandType::Float, v);
}

IOperand const* IOperandFactory::createInt32(std::string const& value) throw(SyntaxException, UnderflowException, OverflowException)
{
	std::stringstream ss;
	int64_t v;

	checkN(value);
	ss << value;
	ss >> v;

	testNumber<int64_t, int32_t>(v);

	return new Operand(eOperandType::Int32, v);
}

IOperand const* IOperandFactory::createInt16(std::string const& value) throw(SyntaxException, UnderflowException, OverflowException)
{
	std::stringstream ss;
	int v;

	checkN(value);
	ss << value;
	ss >> v;

	testNumber<int32_t, int16_t>(v);

	return new Operand(eOperandType::Int16, v);
}

IOperand const* IOperandFactory::createInt8(std::string const& value) throw(SyntaxException, UnderflowException, OverflowException)
{
	std::stringstream ss;
	int v;

	checkN(value);
	ss << value;
	ss >> v;

	testNumber<int32_t, int8_t>(v);

	return new Operand(eOperandType::Int8, v & 0xff);
}

IOperand const*(IOperandFactory::*IOperandFactory::aptr[5])(std::string const&) = {
	&IOperandFactory::createInt8,
	&IOperandFactory::createInt16,
	&IOperandFactory::createInt32,
	&IOperandFactory::createFloat,
	&IOperandFactory::createDouble
};

IOperand const*(IOperandFactory::*IOperandFactory::aptrD[5])(double) = {
	&IOperandFactory::createInt8,
	&IOperandFactory::createInt16,
	&IOperandFactory::createInt32,
	&IOperandFactory::createFloat,
	&IOperandFactory::createDouble
};
