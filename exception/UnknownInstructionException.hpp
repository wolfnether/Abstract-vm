#pragma once

#include <exception>
#include <string>

class UnknownInstructionExeption : public std::exception {
public:
    UnknownInstructionExeption(std::string const &msg);

    virtual const char *what() const throw();

private:
    std::string const &msg;
};