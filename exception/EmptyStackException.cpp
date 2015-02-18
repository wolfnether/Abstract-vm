#include "EmptyStackException.hpp"

EmptyStackException::EmptyStackException()
{
}

const char *EmptyStackException::what() const throw()
{
	return "EmptyStackException: message comming soon";
}

EmptyStackException::~EmptyStackException()
{
}
