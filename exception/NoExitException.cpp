#include "NoExitException.hpp"

const char* NoExitException::what() const throw()
{
	return "This program doesn't have any exit instruction";
}

NoExitException::NoExitException()
{
}

NoExitException::~NoExitException() throw()
{
}
