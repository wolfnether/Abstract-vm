#include <sstream>
#include "Operand.hpp"
#include <cinttypes>
#include "../exception/DivideByZeroException.hpp"
#include "IOperandFactory.hpp"


Operand::Operand(eOperandType type, double value) : type(type), value(value)
{
}

int Operand::getPrecision() const
{
	return (int) this->getType();
}

eOperandType Operand::getType() const
{
	return this->type;
}

double Operand::getValue() const
{
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

IOperand const* Operand::operator+(IOperand const& rhs) const
{
	eOperandType type = this->type > rhs.getType() ? this->type : rhs.getType();
	IOperandFactory factory;
	return factory.createOperand(type, this->getValue() + ((Operand&)rhs).getValue());
}

IOperand const* Operand::operator-(IOperand const& rhs) const
{
	eOperandType type = this->type < rhs.getType() ? this->type : rhs.getType();
	IOperandFactory factory;
	return factory.createOperand(type, this->getValue() - ((Operand&)rhs).getValue());
}

IOperand const* Operand::operator*(IOperand const& rhs) const
{
	eOperandType type = this->type < rhs.getType() ? this->type : rhs.getType();
	IOperandFactory factory;
	return factory.createOperand(type, this->getValue() * ((Operand&)rhs).getValue());
}

IOperand const* Operand::operator/(IOperand const& rhs) const
{
	eOperandType type = this->type < rhs.getType() ? this->type : rhs.getType();
	if (((Operand&)rhs).getValue() == 0.0f)
		throw DivideByZeroException();
	IOperandFactory factory;
	return factory.createOperand(type, this->getValue() / ((Operand&)rhs).getValue());
}

IOperand const* Operand::operator%(IOperand const& rhs) const
{
	eOperandType type = this->type < rhs.getType() ? this->type : rhs.getType();
	if (((Operand&)rhs).getValue() == 0.0f)
		throw DivideByZeroException();
	IOperandFactory factory;
	return factory.createOperand(type, fmod(this->getValue(), ((Operand&)rhs).getValue()));
}

std::string const& Operand::toString() const
{
	std::stringstream ss;
	std::string* str = new std::string();
	ss << this->type << " " << this->getValue();
	*str = ss.str();
	return *str;
}
