#pragma once
#include <list>
#include "../operand/IOperand.hpp"
#include "../parser/Token.hpp"

class VM
{
public:
	VM();
	virtual ~VM();
	void run(std::list<Token> tokenList);
private:
	std::list<const IOperand *> stack;
};