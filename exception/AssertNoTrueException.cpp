#include "AssertNoTrueException.h"


AssertNoTrueException::AssertNoTrueException()
{
}


AssertNoTrueException::~AssertNoTrueException()
{
}

const char* AssertNoTrueException::what() const
{
	return "AssertNoTrueException: message comming soon";
}
