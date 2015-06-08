#include "AssertNoTrueException.h"


AssertNoTrueException::AssertNoTrueException()
{
}


AssertNoTrueException::~AssertNoTrueException() throw()
{
}

const char *AssertNoTrueException::what() const throw()
{
	return "AssertNoTrueException: the assertion is not true";
}
