#pragma once
#include <list>
#include "../operand/IOperand.hpp"
#include "../parser/Token.hpp"
#include "../exception/UnderflowException.hpp"
#include "../exception/OverflowException.hpp"
#include "../exception/EmptyStackException.hpp"
#include "../exception/AssertNoTrueException.h"

class VM
{
public:
	VM();
	virtual ~VM();

	void run(std::list<Token> tokenList) throw(EmptyStackException, AssertNoTrueException, UnderflowException, OverflowException);
private:
	std::list<const IOperand *> stack;
};