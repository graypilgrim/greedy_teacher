#ifndef GREEDY_TEACHER_HPP_
#define GREEDY_TEACHER_HPP_

#include <iostream>
#include <vector>

typedef std::vector<size_t> vector64_t;

class GreedyTeacher
{
public:
	GreedyTeacher(size_t pupilsNo);
	void AddPupil(size_t mark);
	void CountCoockies();
	size_t GetCoockies();
	void PrintMarks();
	void PrintCoockies();

private:
	size_t FindLocalMin(size_t begin);
	size_t GiveCoockies(size_t begin);
	size_t GiveCoockiesReverse(size_t rbegin, size_t rend);
	bool VerifyPupilsNo();

	const size_t pupilsNo;
	bool calculated;
	long coockies;
	vector64_t pupilsMarks;
	vector64_t pupilsCoockies;
};

#endif
