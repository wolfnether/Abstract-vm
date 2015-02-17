#pragma once

#include <exception>

class DivideByZero : public std::exception {
public:
    DivideByZero();

    virtual ~DivideByZero();
    virtual const char *what() const throw();
};