#pragma once

#include <exception>

class UnderflowException : public std::exception {
public:
    virtual const char *what() const throw();
};