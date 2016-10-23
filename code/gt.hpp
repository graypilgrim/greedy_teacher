#ifndef GREEDY_TEACHER_HPP_
#define GREEDY_TEACHER_HPP_

#include <iostream>
#include <vector>

typedef std::vector<uint64_t> vector64_t;

class GreedyTeacher
{
public:
	GreedyTeacher(uint64_t pupilsNo);
	void AddPupil(uint64_t mark);
	uint64_t CountCoockies();

private:
	uint64_t FindFirstLocalMin();

	const uint64_t pupilsNo;
	vector64_t pupilsMarks;
	vector64_t pupilsCoockies;
};

#endif
