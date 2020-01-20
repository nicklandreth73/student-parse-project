#pragma once
#include <string>
#include "student.h"


class softwareStudent : public Student
{
public:
	softwareStudent();
	softwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string email,
		int age,
		int courseDays[],
		DegreeType degreetype
	);
	DegreeType getDegreeType();
	// This function is passed it's accessors from the array of students when it is called in the print all function.
	void print(string firstname, string lastname, int age, int* day1, int* day2, int* day3, DegreeType degreetype);
	~softwareStudent();
};

