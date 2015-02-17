#pragma once

#include <exception>
#include <string>

class OverflowException : public std::exception {
public:
    OverflowException(std::string msg);

    virtual ~OverflowException();
    virtual const char *what() const throw();

private:
    char *msg;
};