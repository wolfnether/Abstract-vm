#include "UnknownInstructionException.hpp"

UnknownInstructionExeption::UnknownInstructionExeption(std::string const &msg) {
    std::string tmp;
    tmp = "UnknownInstructionExeption: " + msg;
    this->msg = new char[tmp.size() + 1];
    memcpy(this->msg, tmp.c_str(), tmp.size() + 1);
}

UnknownInstructionExeption::~UnknownInstructionExeption() {
    delete(msg);
}

const char *UnknownInstructionExeption::what() const throw() {
    return msg;
}