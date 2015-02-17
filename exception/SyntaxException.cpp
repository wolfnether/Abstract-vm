#include "SyntaxException.hpp"

SyntaxException::SyntaxException(std::string const &msg) : msg(msg) {
}

const char *SyntaxException::what() const throw() {
    return ("SyntaxException:" + msg).c_str();
}