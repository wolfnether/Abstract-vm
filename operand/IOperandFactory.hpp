#pragma once
#include <string>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "../exception/SyntaxException.hpp"
#include "../exception/OverflowException.hpp"
#include "../exception/UnderflowException.hpp"

class IOperandFactory {
public:
	IOperand const *createOperand(eOperandType type, std::string const &value) throw(SyntaxException, UnderflowException, OverflowException);
	IOperand const *createInt8(std::string const &value) throw(SyntaxException, UnderflowException, OverflowException);
	IOperand const *createInt16(std::string const &value) throw(SyntaxException, UnderflowException, OverflowException);
	IOperand const *createInt32(std::string const &value) throw(SyntaxException, UnderflowException, OverflowException);
	IOperand const *createFloat(std::string const &value) throw(SyntaxException, UnderflowException, OverflowException);
	IOperand const *createDouble(std::string const &value) throw(SyntaxException);

	IOperand const *createOperand(eOperandType type, double value) throw(UnderflowException, OverflowException);
	IOperand const *createInt8(double value) throw(UnderflowException, OverflowException);
	IOperand const *createInt16(double value) throw(UnderflowException, OverflowException);
	IOperand const *createInt32(double value) throw(UnderflowException, OverflowException);
	IOperand const *createFloat(double value) throw(UnderflowException, OverflowException);
	IOperand const *createDouble(double value) throw();

private:

	static IOperand const *(IOperandFactory::*aptr[5])(std::string const &);
	static IOperand const *(IOperandFactory::*aptrD[5])(double);
};