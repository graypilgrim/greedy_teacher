#ifndef TESTER_HPP_
#define TESTER_HPP_

#include "GreedyTeacher.hpp"

class Tester
{
public:
	Tester(uint64_t size, uint64_t amount)
	:testsSize(size), testsNo(amount)
	{}

	void ShowData();

private:
	uint64_t testsSize;
	uint64_t testsNo;
};

#endif
