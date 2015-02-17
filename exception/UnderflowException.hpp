#pragma once

#include <exception>
#include <string>

class UnderflowException : public std::exception {
public:
    UnderflowException(std::string msg);

    virtual ~UnderflowException();
    virtual const char *what() const throw();

private:
    char *msg;
};