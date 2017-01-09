#ifndef INTEPRETER_HPP_
#define INTEPRETER_HPP_

#include "Tester.hpp"

class Interpreter
{
public:
	Interpreter(int argc, char *argv[]);
	void AnalizeCommands();
	void RunTester();

private:
	void PrintHelp();

	const long CHILDREN_LIMIT = 15000000000;

	int argumentsNo;
	char **arguments;

	bool manualTests;
	long testsNo;
	long pupilsNo;
	long maxMark;
};

#endif
