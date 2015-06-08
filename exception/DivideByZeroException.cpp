#include "DivideByZeroException.hpp"

DivideByZeroException::DivideByZeroException()
{
}

const char *DivideByZeroException::what() const throw()
{
	return "A division by zero is impossible";
}

DivideByZeroException::~DivideByZeroException() throw()
{
}
