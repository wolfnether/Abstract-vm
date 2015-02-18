#include "EmptyStackException.hpp"

EmptyStackException::EmptyStackException()
{
}

const char* EmptyStackException::what() const
{
	return "EmptyStackException: message comming soon";
}

EmptyStackException::~EmptyStackException()
{
}
