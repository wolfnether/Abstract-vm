#include "VM.h"
#include <iostream>
#include "../exception/NoExitException.hpp"
#include "../exception/UnknownInstructionException.hpp"
#include "../operand/Operand.hpp"


VM::VM()
{
}


VM::~VM()
{
}

void VM::run(std::list<Token> tokenList) throw(EmptyStackException, AssertNoTrueException, UnderflowException, OverflowException)
{
	for (Token& token : tokenList)
	{
		IOperand const* operand1;
		IOperand const* operand2;
		switch (token.getInstruction())
		{
		case Instruction::PUSH:
			stack.push_front(token.getValue());
			break;
		case Instruction::POP:
			if (stack.empty())
				throw EmptyStackException();
			stack.pop_front();
			break;
		case Instruction::DUMP:
			std::cout << "=== DUMP ===" << std::endl;
			for (IOperand const* operand : stack)
				std::cout << operand->toString() << std::endl;
			std::cout << "=== END ===" << std::endl;
			break;
		case Instruction::PRINT:
			if (stack.empty())
				throw EmptyStackException();
			if ((*stack.begin())->getType() != eOperandType::Int8)
				throw AssertNoTrueException();
			std::cout << (char)((Operand*)*stack.begin())->getValue();
			break;
		case Instruction::ADD:
			if (stack.size() < 2)
				throw EmptyStackException();
			operand1 = *stack.begin();
			stack.pop_front();
			operand2 = *stack.begin();
			stack.pop_front();
			stack.push_front(*operand2 + *operand1);
			delete operand1;
			delete operand2;
			break;
		case Instruction::EXIT:
			return;
		case Instruction::SUB:
			if (stack.size() < 2)
				throw EmptyStackException();
			operand1 = *stack.begin();
			stack.pop_front();
			operand2 = *stack.begin();
			stack.pop_front();
			stack.push_front(*operand2 - *operand1);
			delete operand1;
			delete operand2;
			break;
		case Instruction::MUL:
			if (stack.size() < 2)
				throw EmptyStackException();
			operand1 = *stack.begin();
			stack.pop_front();
			operand2 = *stack.begin();
			stack.pop_front();
			stack.push_front(*operand2 * *operand1);
			delete operand1;
			delete operand2;
			break;
		case Instruction::DIV:
			if (stack.size() < 2)
				throw EmptyStackException();
			operand1 = *stack.begin();
			stack.pop_front();
			operand2 = *stack.begin();
			stack.pop_front();
			stack.push_front(*operand2 / *operand1);
			delete operand1;
			delete operand2;
			break;
		case Instruction::MOD:
			if (stack.size() < 2)
				throw EmptyStackException();
			operand1 = *stack.begin();
			stack.pop_front();
			operand2 = *stack.begin();
			stack.pop_front();
			stack.push_front(*operand2 % *operand1);
			delete operand1;
			delete operand2;
			break;
		case Instruction::ASSERT:
			if (((Operand*)token.getValue())->getValue() != ((Operand*)*stack.begin())->getValue())
				throw AssertNoTrueException();
			if (token.getValue()->getType() != (*stack.begin())->getType())
				throw AssertNoTrueException();
			break;
		default:
			throw UnknownInstructionException();
		}
	}
	throw NoExitException();
}
