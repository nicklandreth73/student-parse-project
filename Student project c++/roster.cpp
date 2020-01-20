#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

roster::roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}
roster::roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student*[capacity];
}
void roster::printTitle() {
	
	cout << "This program was designed by Nick Landreth using C++ for the Scripting and Programming - Applications course." << endl; 
	cout << "Nick Landreth's Student ID is #000559411" << endl << endl;
}
Student * roster::getStudentAt(int index)
{
	return students[index];
}
void roster::parseCreate(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		DegreeType degreeType;
		if (row.back() == 'Y') degreeType = SECURITY;
		else if (row.back() == 'E') degreeType = SOFTWARE;
		else if (row.back() == 'K') degreeType = NETWORK;
		else
		{
			cerr << "Not a valid degree type. Exiting\n";
			exit(-1);

		}
		int rhs = row.find(",");
		string studentID = row.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string firstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string email = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));


		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int days3 = stoi(row.substr(lhs, rhs - lhs));





		add(studentID, firstName, lastName, email, age, days1, days2, days3, degreeType);

	}
	else {
		cerr << "Error too many students!" << endl;
		exit(-1);
	}
}

void roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeType degreeType)
{
	int studentDays[Student::courseDaysSize];
	studentDays[0] = days1;
	studentDays[1] = days2;
	studentDays[2] = days3;

	if (degreeType == SOFTWARE) {
		students[lastIndex] = new softwareStudent(studentID, firstName, lastName, email, age, studentDays, degreeType);
	}
	else if (degreeType == SECURITY) {
		students[lastIndex] = new securityStudent(studentID, firstName, lastName, email, age, studentDays, degreeType);
	}
	else {
		students[lastIndex] = new networkStudent(studentID, firstName, lastName, email, age, studentDays, degreeType);
	}
}
void roster::print_all(){
	for (int i = 0; i <= this->lastIndex; i++) {
		
		// takes accsessor functions and passes them to the print method, which is looped in order to show all students in the array of students.
		this->students[i]->print(this->students[i]->getFirstName(),this->students[i]->getLastName(), this->students[i]->getAge(), this->students[i]->getCourseDays(), (this->students[i]->getCourseDays())+1, (this->students[i]->getCourseDays())+2, this->students[i]->getDegreeType());
	}
}
bool roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getStudentID() == studentID) {
			found = true;
			delete this->students[i];
			this->students[i] = this->students[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void roster::printDaysInCourse(string studentID) {
	bool found = false;
	
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->students[i]->getStudentID()==studentID) {
			found = true;
			int* k = students[i]->getCourseDays();
			cout << "The average days student " << studentID << " has left in each course is: " << (k[0] + k[1] + k[2]) / 3 << endl;
		}
	}
}
void roster::printInvalidEmails() {
	cout << "Displaying ID of all students with invalid email addresses." << endl;
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		string k = students[i]->getEmail();
		if ((k.find("@") == string::npos) || (k.find(".") == string::npos) || (k.find(" ") != string::npos)) {
			any = true;
			cout << "This ID: " << students[i]->getStudentID() << " is assosciated with the following invalid email address" << k << endl;
		}
	}
	if (!any) {
		cout << "All addresses provided were valid" << endl;
	}
}
void roster::printByDegreeProgram(DegreeType b) {
	cout << "Printing students pursuing degrees in " << DegreeTypeString[b] << endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->students[i]->getDegreeType() == b) this->students[i]->print(this->students[i]->getFirstName(), this->students[i]->getLastName(), this->students[i]->getAge(), this->students[i]->getCourseDays(), (this->students[i]->getCourseDays()) + 1, (this->students[i]->getCourseDays()) + 2, this->students[i]->getDegreeType());
	}
	cout << endl;
}
roster::~roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->students[i];
	}
	delete students;
}
int main()
{
	int numStudents = 5;

	string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nick,Landreth,Nicklandreth75@gmail.com,31,15,15,15,SOFTWARE"
	};
	roster* rost = new roster(numStudents);
	rost->printTitle();
	cout << "Parse should be starting now" << endl;
	for (int i = 0; i < numStudents; i++) {
		rost->parseCreate(studentData[i]);
	}
	cout << "Parsing complete. List will display below" << endl;
	rost->print_all();
	cout << "Removing student A3: " << endl;
	if (rost->remove("A3")) {
		rost->print_all();
		numStudents--;
	}
	else {
		cout << "Student ID not found" << endl;
	}
	cout << "Removing student A3: " << endl;
	if (rost->remove("A3")) {
		rost->print_all();
		numStudents--;
	}
	else {
		cout << "Student ID not found" << endl;
	}
	cout << "Printing average days in each course for each student" << endl;
	for (int i = 0; i < numStudents; i++) {
		rost->printDaysInCourse(rost->getStudentAt(i)->getStudentID());
	}
	rost->printInvalidEmails();

	
	rost->printByDegreeProgram((DegreeType)SOFTWARE);


	system("pause");
	return 0;
}