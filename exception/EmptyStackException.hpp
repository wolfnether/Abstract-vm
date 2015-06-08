#pragma once

#include <exception>

class EmptyStackException : public std::exception {
public:
    EmptyStackException();

    virtual ~EmptyStackException() throw();
    virtual const char *what() const throw();
};
