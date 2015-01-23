#include <sstream>
#include <iostream>
#include <w32api/msxml.h>
#include <w32api/d2d1helper.h>
#include "Parser.hpp"
#include "../operand/IOperandFactory.hpp"

Parser::Parser() {
}

Parser::~Parser() {
}

std::list<Token *> &Parser::parse(std::istream &in) {
    std::list<Token *> *tokenList = new std::list<Token *>();
    std::stringstream line;
    std::string buf;

    while (!in.eof()) {
        std::getline(in, buf);

        if (buf.compare(";;") == 0 && in == std::cin)
            break;
        else if (buf.compare("") == 0 || buf[0] == ';')
            continue;
        try {
            line << buf;
            Parser::parseInstruction(line);
        } catch (std::exception e) {
            throw e;
        }
    }
    return *tokenList;
}

Token &Parser::parseInstruction(std::istream &in) {
    Token *token = new Token();
    std::string buf;

    std::getline(in, buf, ' ');
    try {
        if (buf.compare("push") == 0) {
            token->setInstruction(Instruction::PUSH);
            token->getValue() = Parser::parseValue(in);
        }
    } catch (std::exception e) {
        throw e;
    }

    return *token;
}

IOperand &Parser::parseValue(std::istream &in) {
    IOperandFactory operandFactory;
    std::string type;
    std::string value;

    std::getline(in, type, '(');
    std::getline(in, value, ')');

    if(type.compare("int8") == 0)
        return operandFactory.createOperand(eOperandType::Int8 , value);
    if(type.compare("int16") == 0)
        return operandFactory.createOperand(eOperandType::Int16 , value);
    if(type.compare("int32") == 0)
        return operandFactory.createOperand(eOperandType::Int32 , value);
    if(type.compare("float") == 0)
        return operandFactory.createOperand(eOperandType::Float , value);
    if(type.compare("double") == 0)
        return operandFactory.createOperand(eOperandType::Double , value);
    //throw error
}