#include "GreedyTeacher.hpp"
#include <algorithm>

GreedyTeacher::GreedyTeacher(size_t pupilsNo)
	:pupilsNo(pupilsNo)
{
	pupilsMarks.reserve(pupilsNo);
	pupilsCoockies.reserve(pupilsNo);
}

void GreedyTeacher::AddPupil(size_t mark)
{
	pupilsMarks.push_back(mark);
	pupilsCoockies.push_back(1);
}

void GreedyTeacher::CountCoockiesBrute()
{
	pupilsCoockies[0] = 1;

	for (size_t i = 1; i < pupilsNo; ++i)
	{
		if (pupilsMarks[i] > pupilsMarks[i - 1])
			pupilsCoockies[i] = pupilsCoockies[i - 1] + 1;

		if (pupilsMarks[i] == pupilsMarks[i - 1])
			pupilsCoockies[i] = pupilsCoockies[i - 1];

		if (pupilsMarks[i] < pupilsMarks[i - 1])
		{
			pupilsCoockies[i] = 1;

			for (long it = i - 1; it >= 0; --it)
			{
				if (pupilsCoockies[it] == pupilsCoockies[it + 1] && pupilsMarks[it] > pupilsMarks[it + 1])
					++pupilsCoockies[it];

				if (pupilsMarks[it] == pupilsMarks[it + 1])
					pupilsCoockies[it] = pupilsCoockies[it + 1];
			}
		}
	}

	coockies = 0;
	for (auto i : pupilsCoockies)
		coockies += i;
}

void GreedyTeacher::CountCoockies()
{
	coockies = 0;

	for (size_t i = 1; i < pupilsNo; ++i)
	{
		if (pupilsMarks[i] > pupilsMarks[i-1])
			pupilsCoockies[i] = pupilsCoockies[i-1] + 1;

		if (pupilsMarks[i] == pupilsMarks[i-1])
			pupilsCoockies[i] = pupilsCoockies[i-1];
	}

	for (size_t i = pupilsNo - 2; i >= 0; --i)
	{
		if (pupilsMarks[i] > pupilsMarks[i+1])
			pupilsCoockies[i] = std::max(pupilsCoockies[i], pupilsCoockies[i+1] + 1);

		if (pupilsMarks[i] == pupilsMarks[i+1])
			pupilsCoockies[i] = pupilsCoockies[i+1];

		if (i == 0)
			break;

		coockies += pupilsCoockies[i];
	}
}

size_t GreedyTeacher::GetCoockiesNo()
{
	if (coockies != 0)
		return coockies;

	CountCoockies();
	return coockies;
}

vec GreedyTeacher::GetCoockies()
{
	return pupilsCoockies;
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

bool GreedyTeacher::CorrectPupilsNo()
{
	if (pupilsMarks.size() != pupilsNo) {
		std::cerr << "Invalid marks number!" << std::endl;
		return false;
	}

	return true;
}
