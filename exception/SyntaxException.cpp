#include "SyntaxException.hpp"

SyntaxException::SyntaxException(std::string const &msg) {
    std::string tmp;
    tmp = "SyntaxException: " + msg;
    this->msg = new char[tmp.size() + 1];
    memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}

SyntaxException::~SyntaxException() {
    delete msg;
}

const char *SyntaxException::what() const throw() {
    return msg;
}