#include "UnderflowException.hpp"

UnderflowException::UnderflowException()
{
}

UnderflowException::~UnderflowException() throw()
{
}

const char* UnderflowException::what() const throw()
{
	return "UnderflowException: A underflow is breaking the vm apart";
}
