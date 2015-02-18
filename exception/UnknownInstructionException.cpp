#include "UnknownInstructionException.hpp"
#include <sstream>

UnknownInstructionException::UnknownInstructionException(std::string const& msg)
{
	std::string tmp;
	tmp = "UnknownInstructionExeption: " + msg;
	this->msg = new char[tmp.size() + 1];
	memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}

UnknownInstructionException::~UnknownInstructionException()
{
	delete(msg);
}

const char* UnknownInstructionException::what() const throw()
{
	return msg;
}

UnknownInstructionException::UnknownInstructionException(Instruction type)
{
	std::stringstream ss;
	std::string tmp;

	ss << type;
	ss >> tmp;
	tmp = "UnknownInstructionExeption: " + tmp;
	this->msg = new char[tmp.size() + 1];
	memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}
