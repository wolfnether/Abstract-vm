#include "eOperandType.hpp"

std::ostream& operator<<(std::ostream& os, const eOperandType type)
{
	if (type == eOperandType::Int8)
		os << "Int8";
	else if (type == eOperandType::Int16)
		os << "Int16";
	else if (type == eOperandType::Int32)
		os << "Int32";
	else if (type == eOperandType::Float)
		os << "Float";
	else if (type == eOperandType::Double)
		os << "Double";
	return os;
}
