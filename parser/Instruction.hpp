#pragma once

#include <ostream>

enum class Instruction {
    POP, DUMP, ADD, SUB, MUL, DIV, MOD, PRINT, EXIT, PUSH, ASSERT
};

std::ostream &operator<<(std::ostream &os, const Instruction type);