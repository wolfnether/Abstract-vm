#include "SyntaxException.hpp"

SyntaxException::SyntaxException()
{
}

SyntaxException::~SyntaxException() throw()
{
}

const char* SyntaxException::what() const throw()
{
	return "SyntaxException: Please revise your grammar";
}
