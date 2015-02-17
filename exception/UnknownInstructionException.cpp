#include "UnknownInstructionException.hpp"

UnknownInstructionExeption::UnknownInstructionExeption(std::string const &msg) : msg(msg) {
}

const char *UnknownInstructionExeption::what() const throw() {
    return ("UnknownInstructionExeption:" + msg).c_str();
}