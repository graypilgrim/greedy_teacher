#ifndef INTEPRETER_HPP_
#define INTEPRETER_HPP_

#include "Tester.hpp"

class Interpreter
{
public:
	Interpreter(int argc, char *argv[]);
	void RunTests();

private:
	void PrintHelp();
	void RunManualTester();

	bool manual = false;
	long testsNo;
	long childrenNo;
	long maxResult;
};

#endif
