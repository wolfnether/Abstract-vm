#pragma once

#include <exception>
#include <string>

class SyntaxException : public std::exception {
public:
    SyntaxException();

    virtual ~SyntaxException() throw();
    virtual const char *what() const throw();
};
