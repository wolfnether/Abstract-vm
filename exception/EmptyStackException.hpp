#pragma once

#include <exception>

class EmptyStackException : public std::exception {
public:
    EmptyStackException();

    virtual ~EmptyStackException();
    virtual const char *what() const throw();
};