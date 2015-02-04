#include <sstream>
#include <iostream>
#include "Parser.hpp"
#include "../operand/IOperandFactory.hpp"

Parser::Parser() {
}

Parser::~Parser() {
}

std::list<Token *> &Parser::parse(std::istream &in) {
    std::list<Token *> *tokenList = new std::list<Token *>();
    std::string buf;

    while (!in.eof()) {
        std::getline(in, buf);
        std::cout << "PARSE " << buf << std::endl;

        if (buf.compare(";;") == 0 && in == std::cin)
            break;
        else if (buf.compare("") == 0 || buf[0] == ';')
            continue;
        std::stringstream line;
        line << buf;
        std::cout << line.tellg() << " " << line.tellp() << std::endl;
        Parser::parseInstruction(line);
    }
    return *tokenList;
}

Token &Parser::parseInstruction(std::istream &in) {
    Token *token = new Token();
    std::string buf;

    std::getline(in, buf, ' ');
    std::cout << "PARSE_INSTRUCTION |" << buf << "|" << std::endl;
    if (buf.compare("push") == 0) {
        token->setInstruction(Instruction::PUSH);
        token->setValue(Parser::parseValue(in));
    }

    return *token;
}

IOperand const *Parser::parseValue(std::istream &in) {
    IOperandFactory operandFactory;
    std::string type;
    std::string value;

    std::getline(in, type, '(');
    //if (in.eof())
    //    throw new std::exception();

    std::getline(in, value, ')');
    //if (value.size() == 0)
    //    throw new std::exception();
    std::cout << "PARSE_Value |" << type << "| | " << value << "|" << std::endl;

    if(type.compare("int8") == 0)
        return operandFactory.createOperand(eOperandType::Int8 , value);
    else if(type.compare("int16") == 0)
        return operandFactory.createOperand(eOperandType::Int16 , value);
    else if(type.compare("int32") == 0)
        return operandFactory.createOperand(eOperandType::Int32 , value);
    else if(type.compare("float") == 0)
        return operandFactory.createOperand(eOperandType::Float , value);
    else if(type.compare("double") == 0)
        return operandFactory.createOperand(eOperandType::Double , value);

    std::cout << "Error !!" << std::endl;
    throw new std::exception();
}