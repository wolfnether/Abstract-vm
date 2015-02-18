#include "AssertNoTrueException.h"


AssertNoTrueException::AssertNoTrueException()
{
}


AssertNoTrueException::~AssertNoTrueException()
{
}

const char *AssertNoTrueException::what() const throw()
{
	return "AssertNoTrueException: message comming soon";
}
