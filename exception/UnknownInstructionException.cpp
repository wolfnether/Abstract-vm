#include "UnknownInstructionException.hpp"
#include <sstream>

UnknownInstructionException::UnknownInstructionException()
{
}

UnknownInstructionException::~UnknownInstructionException() throw()
{
}

const char* UnknownInstructionException::what() const throw()
{
	return "UnknownInstructionException: this word isn't in my dictionnary";
}
