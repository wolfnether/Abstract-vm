#pragma once

#include <exception>

class AssertNoTrue : public std::exception {
public:
    AssertNoTrue();

    virtual ~AssertNoTrue();
    virtual const char *what() const throw();
};