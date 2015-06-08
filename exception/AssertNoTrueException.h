#pragma once
#include <exception>

class AssertNoTrueException :
	public std::exception
{
public:
	AssertNoTrueException();
	virtual ~AssertNoTrueException() throw();
	virtual const char *what() const throw();
};

