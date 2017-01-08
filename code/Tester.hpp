#ifndef TESTER_HPP_
#define TESTER_HPP_

#include <chrono>
#include <ctime>

#include "GreedyTeacher.hpp"

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
	void PrintFormatedResult(GreedyTeacher &gt, long solvingTime, size_t testNo);
	void CheckCorrectness(GreedyTeacher &gt, GreedyTeacher &gtBrute);

	size_t testsNo;
	size_t testSize;
	size_t maxMark;

};

#endif
