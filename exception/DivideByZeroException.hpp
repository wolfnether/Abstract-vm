#pragma once

#include <exception>

class DivideByZeroException : public std::exception {
public:
	DivideByZeroException();

	virtual ~DivideByZeroException() throw();
    virtual const char *what() const throw();
};
