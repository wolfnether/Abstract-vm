#pragma once

#include <ostream>
#include <string>

enum class eOperandType {
    Int8, Int16, Int32, Float, Double
};

std::ostream &operator<<(std::ostream &os, const eOperandType type);