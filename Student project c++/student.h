#pragma once
#include <string>
#include "degreeType.h"


using std::string;

class Student
{
public:

	const static int courseDaysSize = 3;
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int courseDays[]);
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string Email);
	void setAge(int age);
	void setCourseDays(int courseDays[]);




	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getCourseDays();
	virtual DegreeType getDegreeType() = 0;
	// This function is passed it's accessors from the array of students when it is called in the print all function.
	virtual void print(string firstname, string lastname, int age, int* day1, int* day2, int* day3, DegreeType degreetype) = 0;


	~Student();




protected:
	string firstName;
	string lastName;
	string studentID;
	string email;
	int age;
	int* courseDays;
	DegreeType degreeType;

};