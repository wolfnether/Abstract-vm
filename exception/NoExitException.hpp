#pragma once

#include <exception>

class NoExitException : public std::exception {
public:
    virtual const char *what() const throw();
};