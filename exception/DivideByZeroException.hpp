#pragma once

#include <exception>

class DivideByZero : public std::exception {
public:
    virtual const char *what() const throw();
};