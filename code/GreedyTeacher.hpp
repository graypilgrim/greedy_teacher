#ifndef GREEDY_TEACHER_HPP_
#define GREEDY_TEACHER_HPP_

#include <iostream>
#include <vector>

typedef std::vector<size_t> vec;

class GreedyTeacher
{
public:
	GreedyTeacher(size_t pupilsNo);
	void AddPupil(size_t mark);
	void CountCoockiesBrute();
	void CountCoockies();
	size_t GetCoockiesNo();
	vec GetCoockies();
	void PrintMarks();
	void PrintCoockies();
	size_t GetPupilsNo();

private:
	bool CorrectPupilsNo();

	const size_t pupilsNo;
	long coockies;
	vec pupilsMarks;
	vec pupilsCoockies;
};

#endif
