#pragma once
#include <exception>

class AssertNoTrueException :
	public std::exception
{
public:
	AssertNoTrueException();
	virtual ~AssertNoTrueException();
	virtual const char *what() const throw();
};

