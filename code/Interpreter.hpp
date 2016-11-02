#ifndef INTEPRETER_HPP_
#define INTEPRETER_HPP_

#include "Tester.hpp"

class Interpreter
{
public:
	Interpreter(int argc, char *argv[])
	:argumentsNo(argc), arguments(argv)
	{}

private:
	int argumentsNo;
	char **arguments;
};

#endif
