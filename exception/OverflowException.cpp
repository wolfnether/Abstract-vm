#include "OverflowException.hpp"

OverflowException::OverflowException()
{
}

OverflowException::~OverflowException() throw()
{
}

const char* OverflowException::what() const throw()
{
	return "OverflowException: a overflow is breaking the vm apart";
}
