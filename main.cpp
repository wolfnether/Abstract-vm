#include <iostream>
#include <fstream>
#include <typeinfo>
#include "parser/Parser.hpp"
#include "vm/VM.h"

int main(int i, char** arg)
{
	std::istream* in;
	Parser parser;
	VM vm;

	if (i == 1)
		in = &std::cin;
	else
	{
		std::ifstream* file = new std::ifstream(arg[1]);
		if (!file->is_open())
		{
			std::cerr << "Cannont open " << arg[1] << std::endl;
			return 1;
		}
		in = file;
	}
	try
	{
		std::list<Token>& tokenList = parser.parse(*in);
		vm.run(tokenList);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error !! : " << e.what() << std::endl;
		return -1;
	}

	return 0;
}
