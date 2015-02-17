#pragma once

#include <exception>

class OverflowException : public std::exception {
public:
    virtual const char *what() const throw();
};