#include "GreedyTeacher.hpp"
#include <algorithm>

GreedyTeacher::GreedyTeacher(size_t pupilsNo)
	:pupilsNo(pupilsNo), calculated(false)
{
	pupilsMarks.reserve(pupilsNo);
	pupilsCoockies.reserve(pupilsNo);
}

void GreedyTeacher::AddPupil(size_t mark)
{
	pupilsMarks.push_back(mark);
	pupilsCoockies.push_back(0);
}

void GreedyTeacher::CountCoockies()
{
	GiveCoockies();
	GiveCoockiesReverse();

	coockies = 0;

	for (auto i : pupilsCoockies)
		coockies += i;

	calculated = true;
}

void GreedyTeacher::GiveCoockies()
{
	pupilsCoockies[0] = 1;

	for (size_t i = 1; i < pupilsNo; ++i)
	{
		if (IsLocalMinimum(i))
		{
			pupilsCoockies[i] = 1;
			continue;
		}

		if (pupilsMarks[i] > pupilsMarks[i-1])
			pupilsCoockies[i] = pupilsCoockies[i-1] + 1;

		if (pupilsMarks[i] == pupilsMarks[i-1])
			pupilsCoockies[i] = pupilsCoockies[i-1];

		if (pupilsMarks[i] < pupilsMarks[i-1])
			pupilsCoockies[i] = std::max(pupilsCoockies[i-1] - 1, (size_t)1);
	}
}

void GreedyTeacher::GiveCoockiesReverse()
{
	for (size_t i = pupilsNo - 2; i >= 0; --i)
	{
		if (IsLocalMinimum(i))
		{
			pupilsCoockies[i] = 1;

			if (i != 0)
				continue;
			else
				break;
		}

		size_t tempCoockies;

		if (pupilsMarks[i] > pupilsMarks[i+1])
			tempCoockies = pupilsCoockies[i+1] + 1;

		if (pupilsMarks[i] == pupilsMarks[i+1])
			tempCoockies = pupilsCoockies[i+1];

		if (pupilsMarks[i] < pupilsMarks[i+1])
			tempCoockies = std::max(pupilsCoockies[i+1] - 1, (size_t)1);

		pupilsCoockies[i] = std::max(tempCoockies, pupilsCoockies[i]);

		if (i == 0)
			break;
	}
}

size_t GreedyTeacher::GetCoockies()
{
	if (calculated)
		return coockies;

	CountCoockies();
	return coockies;
}

void GreedyTeacher::PrintMarks()
{
	if (!CorrectPupilsNo())
		return;

	for (auto it : pupilsMarks)
		std::cout << it << " ";

	std::cout << std::endl;
}

void GreedyTeacher::PrintCoockies()
{
	if (!CorrectPupilsNo())
		return;

	for (auto it : pupilsCoockies)
		std::cout << it << " ";

	std::cout << std::endl;
}

size_t GreedyTeacher::GetPupilsNo()
{
	return pupilsNo;
}

size_t GreedyTeacher::FindLocalMin(size_t begin)
{
	if (begin == 0 && pupilsMarks[begin] < pupilsMarks[begin + 1])
		return begin;

	for (size_t i = begin; i < pupilsNo; ++i)
		if (pupilsMarks[i] < pupilsMarks[i + 1] && pupilsMarks[i] <= pupilsMarks[i - 1])
			return i;

	return pupilsNo;
}

bool GreedyTeacher::CorrectPupilsNo()
{
	if (pupilsMarks.size() != pupilsNo) {
		std::cerr << "Invalid marks number!" << std::endl;
		return false;
	}

	return true;
}

bool GreedyTeacher::IsLocalMinimum(size_t index)
{
	if (index == 0 && pupilsMarks[index] < pupilsMarks[index + 1])
		return true;

	if (index == (pupilsNo - 1) && pupilsMarks[index] <= pupilsMarks[index - 1])
		return true;

	if (pupilsMarks[index] < pupilsMarks[index + 1] && pupilsMarks[index] < pupilsMarks[index - 1])
		return true;

	return false;
}
