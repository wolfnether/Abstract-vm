#include <sstream>
#include <iostream>
#include "Parser.hpp"
#include "../operand/IOperandFactory.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

std::list<Token>& Parser::parse(std::istream& in) throw(SyntaxException, UnknownInstructionException, UnderflowException, OverflowException, NoExitException)
{
	std::list<Token>* tokenList = new std::list<Token>();
	std::string buf;

	while (!in.eof())
	{
		std::getline(in, buf);

		if (buf.compare(";;") == 0 && &in == &std::cin)
			break;
		else if (buf.compare("") == 0 || buf[0] == ';')
			continue;
		std::stringstream line;
		line << buf;
		Token& token = Parser::parseInstruction(line);
		std::string tmp;
		line >> tmp;
		if (tmp.size() != 0)
		{
			throw SyntaxException("Unexpected charaters : " + tmp);
		}
		tokenList->push_back(token);
	}
	return *tokenList;
}

Token& Parser::parseInstruction(std::istream& in) throw(SyntaxException, UnknownInstructionException, UnderflowException, OverflowException)
{
	Token* token = new Token();
	std::string buf;

	std::getline(in, buf, ' ');
	if (buf.compare("push") == 0)
	{
		token->setInstruction(Instruction::PUSH);
		token->setValue(Parser::parseValue(in));
	}
	else if (buf.compare("pop") == 0)
	{
		token->setInstruction(Instruction::POP);
	}
	else if (buf.compare("dump") == 0)
	{
		token->setInstruction(Instruction::DUMP);
	}
	else if (buf.compare("assert") == 0)
	{
		token->setInstruction(Instruction::ASSERT);
		token->setValue(Parser::parseValue(in));
	}
	else if (buf.compare("add") == 0)
	{
		token->setInstruction(Instruction::ADD);
	}
	else if (buf.compare("sub") == 0)
	{
		token->setInstruction(Instruction::SUB);
	}
	else if (buf.compare("mul") == 0)
	{
		token->setInstruction(Instruction::MUL);
	}
	else if (buf.compare("div") == 0)
	{
		token->setInstruction(Instruction::DIV);
	}
	else if (buf.compare("mod") == 0)
	{
		token->setInstruction(Instruction::MOD);
	}
	else if (buf.compare("print") == 0)
	{
		token->setInstruction(Instruction::PRINT);
	}
	else if (buf.compare("exit") == 0)
	{
		token->setInstruction(Instruction::EXIT);
	}
	else
		throw UnknownInstructionException(buf + " isn't an instruction");
	return *token;
}

IOperand const* Parser::parseValue(std::istream& in) throw(SyntaxException, UnderflowException, OverflowException)
{
	IOperandFactory operandFactory;
	std::string type;
	std::string value;

	std::getline(in, type, '(');
	std::getline(in, value, ')');

	if (type.compare("int8") == 0)
		return operandFactory.createOperand(eOperandType::Int8, value);
	else if (type.compare("int16") == 0)
		return operandFactory.createOperand(eOperandType::Int16, value);
	else if (type.compare("int32") == 0)
		return operandFactory.createOperand(eOperandType::Int32, value);
	else if (type.compare("float") == 0)
		return operandFactory.createOperand(eOperandType::Float, value);
	else if (type.compare("double") == 0)
		return operandFactory.createOperand(eOperandType::Double, value);

	throw SyntaxException(type + " is an unknown type");
}
