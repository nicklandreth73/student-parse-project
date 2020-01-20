#include "networkStudent.h"
#include <iostream>
using std::cout;
using std::endl;
using std::left;


networkStudent::networkStudent() :Student()
{
	this->degreeType = NETWORK;
}
networkStudent::networkStudent(string studentID, string firstName, string lastName, string email, int age, int courseDays[], DegreeType degreetype) : Student(studentID, firstName, lastName, email, age, courseDays)
{

	this->degreeType = NETWORK;
}
DegreeType networkStudent::getDegreeType()
{
	return degreeType;
}
void networkStudent::print(string firstname, string lastname, int age, int* day1, int* day2, int* day3, DegreeType degreetype)
{
	// This function is passed it's accessors from the array of students when it is called in the print all function.
	this->Student::print(firstname, lastname, age, day1, day2, day3, degreetype);
	cout << left << "\t" << "Degree Program: " << DegreeTypeString[degreetype] << endl;
}
networkStudent::~networkStudent()
{
	Student::~Student();
}
