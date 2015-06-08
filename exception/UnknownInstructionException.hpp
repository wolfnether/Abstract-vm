#pragma once

#include "../parser/Instruction.hpp"
#include <exception>
#include <string>

class UnknownInstructionException : public std::exception {
public:
    UnknownInstructionException();
	
    virtual ~UnknownInstructionException() throw();
    virtual const char *what() const throw();

};
