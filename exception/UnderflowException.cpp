#include "UnderflowException.hpp"

UnderflowException::UnderflowException(std::string msg)
{
	std::string tmp;
	tmp = "UnderflowException: " + msg;
	this->msg = new char[tmp.size() + 1];
	memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}

UnderflowException::~UnderflowException()
{
	delete msg;
}

const char* UnderflowException::what() const throw()
{
	return msg;
}
