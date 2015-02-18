#include "OverflowException.hpp"

OverflowException::OverflowException(std::string msg)
{
	std::string tmp;
	tmp = "OverflowException: " + msg;
	this->msg = new char[tmp.size() + 1];
	memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}

OverflowException::~OverflowException()
{
	delete msg;
}

const char* OverflowException::what() const throw()
{
	return msg;
}
