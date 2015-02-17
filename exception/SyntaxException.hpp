#pragma once

#include <exception>
#include <string>

class SyntaxException : public std::exception {
public:
    SyntaxException(std::string const &msg);

    virtual ~SyntaxException();
    virtual const char *what() const throw();

private:
    char *msg;
};