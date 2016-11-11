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

	const size_t CHILDREN_LIMIT = 15000000000;

	int argumentsNo;
	char **arguments;

	bool manualTests;
	size_t testsNo;
	size_t pupilsNo;
	size_t maxMark;
};

#endif
