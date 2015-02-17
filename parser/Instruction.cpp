#include "Instruction.hpp"

std::ostream &operator<<(std::ostream &os, const Instruction type) {
    if (type == Instruction::POP)
        os << "POP";
    else if (type == Instruction::DUMP)
        os << "DUMP";
    else if (type == Instruction::ADD)
        os << "ADD";
    else if (type == Instruction::SUB)
        os << "SUB";
    else if (type == Instruction::MUL)
        os << "MUL";
    else if (type == Instruction::DIV)
        os << "DIV";
    else if (type == Instruction::MOD)
        os << "MOD";
    else if (type == Instruction::PRINT)
        os << "PRINT";
    else if (type == Instruction::EXIT)
        os << "EXIT";
    else if (type == Instruction::PUSH)
        os << "PUSH";
    else if (type == Instruction::ASSERT)
        os << "ASSERT";
    return os;
}