#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "GreedyTeacher.hpp"
#include <chrono>

class Tester
{
public:
	Tester();
	Tester(size_t size, size_t amount);
	void RunManualTests();

private:
	long MeasureSolvingTime(GreedyTeacher &gt);

	size_t testsNo;
	size_t testsSize;

};

#endif
