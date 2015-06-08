#include "EmptyStackException.hpp"

EmptyStackException::EmptyStackException()
{
}

const char *EmptyStackException::what() const throw()
{
	return "EmptyStackException: the stack is empty try to fill it";
}

EmptyStackException::~EmptyStackException() throw()
{
}
