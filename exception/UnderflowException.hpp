#pragma once

#include <exception>
#include <string>

class UnderflowException : public std::exception {
public:
    UnderflowException();

    virtual ~UnderflowException() throw();
    virtual const char *what() const throw();
};
