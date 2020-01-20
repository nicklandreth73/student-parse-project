#include "student.h"
#include <iostream>

using namespace std;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < courseDaysSize; i++) {
		this->courseDays[i] = 0;
	}
}
Student::Student(string studentID, string firstName, string lastName, string email, int age, int courseDays[]) {
	this->studentID = studentID;	
	this->firstName = firstName;    
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < courseDaysSize; i++) {
		this->courseDays[i] = courseDays[i];
	}
}
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setCourseDays(int courseDays[]) {
	if (this-> courseDays != nullptr) {
		delete[] this->courseDays;
		this->courseDays = nullptr;
	}
	this->courseDays = new int[courseDaysSize];
	for (int i = 0; i < courseDaysSize; i++) {
		this->courseDays[i] = courseDays[i];
	}
}

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getCourseDays() {

	return courseDays;
};



		// This function is passed it's accessors from the array of students when it is called in the print all function.
void Student::print(string firstname, string lastname, int age, int* day1, int* day2, int* day3, DegreeType degreetype) {
	cout << left << "\t" << "First Name: " << firstname;
	cout << left << "\t" << "Last Name: " << lastname;
	cout << left << "\t" << "Age: " << age;
	cout << left << "\t" << "Days in course: {" << *day1 << ", " << *day2 << ", " << *day3 << "} ";

	
}


Student::~Student() {
}
