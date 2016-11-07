#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "GreedyTeacher.hpp"
#include <chrono>
#include <ctime>

class Tester
{
public:
	Tester();
	Tester(size_t suiteSize, size_t childrenNo, size_t maxResult);
	void RunManualTests();
	void RunAutomaticTests();

private:
	long MeasureSolvingTime(GreedyTeacher &gt);
	void RunAutomaticRandomTest();
	long CalculateDelta();

	size_t testsNo;
	size_t testSize;
	size_t maxMark;

};

#endif
