#pragma once

#include <exception>

class AssertNoTrue : public std::exception {
public:
    virtual const char *what() const throw();
};