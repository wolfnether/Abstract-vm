#include <sstream>
#include <iostream>
#include "Parser.hpp"
#include "../operand/IOperandFactory.hpp"
#include "../operand/Operand.hpp"

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
        Token token = Parser::parseInstruction(line);
        std::cout << token.getValue().toString() << std::endl;
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

    std::getline(in, value, ')');
    std::cout << "PARSE_Value |" << type << "| |" << value << "|" << std::endl;

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
    //throw new std::exception();
    return new Operand(eOperandType::Int8, 0);
}