#pragma once

#include <exception>

class NoExitException : public std::exception {
public:
    NoExitException();

    virtual ~NoExitException();

    virtual const char *what() const throw();
};