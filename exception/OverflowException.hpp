#pragma once

#include <exception>
#include <string>

class OverflowException : public std::exception {
public:
    OverflowException();

    virtual ~OverflowException() throw();
    virtual const char *what() const throw();

};
