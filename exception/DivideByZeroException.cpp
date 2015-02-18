#include "DivideByZeroException.hpp"

DivideByZeroException::DivideByZeroException()
{
}

const char *DivideByZeroException::what() const throw()
{
	return "";
}

DivideByZeroException::~DivideByZeroException()
{
}
