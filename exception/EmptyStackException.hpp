#pragma once

#include <exception>

class EmptyStackException : public std::exception {
public:
    virtual const char *what() const throw();
};