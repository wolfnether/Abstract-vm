#include "DivideByZeroException.hpp"

DivideByZeroException::DivideByZeroException()
{
}

const char* DivideByZeroException::what() const
{
	return "";
}

DivideByZeroException::~DivideByZeroException()
{
}
