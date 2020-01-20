#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class roster {
private:
	int lastIndex;
	int capacity;
	Student** students;
public:
	roster();
	roster(int capacity);

	Student* getStudentAt(int index);
	void parseCreate(string datarow);
	void add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeType degreeType);
	void print_all();
	bool remove(string studentID);
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printTitle();
public:
	void printByDegreeProgram(DegreeType b);
	~roster();


};
