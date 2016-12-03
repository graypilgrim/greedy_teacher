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
	void CountCoockiesBrute();
	void CountCoockies();
	size_t GetCoockies();
	void PrintMarks();
	void PrintCoockies();
	size_t GetPupilsNo();

private:
	size_t FindLocalMin(size_t begin);
	bool CorrectPupilsNo();
	bool IsLocalMinimum(size_t index);

	const size_t pupilsNo;
	long coockies;
	vector64_t pupilsMarks;
	vector64_t pupilsCoockies;
};

#endif
