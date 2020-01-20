#include "softwareStudent.h"
#include <iostream>
using std::cout;
using std::endl;
using std::left;

softwareStudent::softwareStudent() :Student()
{
	this->degreeType = SOFTWARE;
}
softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string email, int age, int courseDays[], DegreeType degreetype) : Student(studentID, firstName, lastName, email, age, courseDays)
{
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < courseDaysSize; i++) {
		this->courseDays[i] = courseDays[i];
	}
	this->degreeType = SOFTWARE;
}
DegreeType softwareStudent::getDegreeType()
{
	return degreeType;
}
void softwareStudent::print(string firstname, string lastname, int age, int* day1, int* day2, int*day3, DegreeType degreetype)
{
	// This function is passed it's accessors from the array of students when it is called in the print all function in the roster.cpp.
	this->Student::print(firstname, lastname, age, day1, day2, day3, degreetype);
	cout << left << "\t" << "Degree Program: " << DegreeTypeString[degreetype] << endl;
}
softwareStudent::~softwareStudent()
{
	Student::~Student();
}
