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
	void PrintMarks();
	void PrintCoockies();

private:
	uint64_t FindLocalMin(uint64_t begin);
	uint64_t GiveCoockies(uint64_t begin);
	uint64_t GiveCoockiesReverse(uint64_t rbegin, uint64_t rend);
	bool VerifyPupilsNo();

	const uint64_t pupilsNo;
	vector64_t pupilsMarks;
	vector64_t pupilsCoockies;
};

#endif
