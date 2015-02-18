#pragma once

#include "../parser/Instruction.hpp"
#include <exception>
#include <string>

class UnknownInstructionException : public std::exception {
public:
    UnknownInstructionException(std::string const &msg);
	UnknownInstructionException(Instruction type);
	
    virtual ~UnknownInstructionException();
    virtual const char *what() const throw();

private:
    char *msg;
};