#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

// Creation of roster class
roster::roster() {

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Azan,Raja,araja15@wgu.edu,23,25,30,40,SOFTWARE" // Modificaiton for student data table to hold personal information 
	};

	// Loop initialization
	for (int i = 0; i < numStudents; i++){
		classRosterArray[i] = nullptr;
	}

	// Loop initalization for parsing data below
	for (int i = 0; i < numStudents; i++){

		size_t rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string emailAddress = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int dCI1 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int dCI2 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int dCI3 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string dS = studentData[i].substr(lhs, rhs - lhs);

		DegreeProgram degreeProgram = DegreeProgram::NETWORK;
		if (dS == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (dS == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
		
		add(studentID, firstName, lastName, emailAddress, age, dCI1, dCI2, dCI3, degreeProgram);
	}
};

// Destructor for roster class
roster::~roster(){
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int dIC1, int dIC2, int dIC3, DegreeProgram degreeProgram){
	int daysinCourse[] = { dIC1, dIC2, dIC3 };
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new student(studentID, firstName, lastName, emailAddress, age, daysinCourse, degreeProgram);
			return;
		}
	}
}

void roster::removal(string studentID){
	bool validstudentID = false;
	cout << "Removing " << studentID;
	for (int i = 0; i < numStudents; ++i){
		if (classRosterArray[i] == nullptr){
		}
		else {
			if (classRosterArray[i]->GetStudentID() == studentID){
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				validstudentID = true;
			}
		}
	}
	if (validstudentID == false){
		cout  << endl << studentID << " student was not found. " << endl;
	}
}
void roster::printAll(){
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void roster::printInvaildEmails() {
	cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->validateEmailAddress() == true) {
			cout << "Invalid email: " << classRosterArray[i]->GetEmailAddress() << endl;
		}
	}
}

void roster::printAverageDaysInCourse(string studentID){
	int tempID{};
	for (int i = 0; i < numStudents; ++i){
		if (classRosterArray[i]->GetStudentID() == studentID) {
			tempID = i; 
		}
	}
	cout <<  classRosterArray[tempID]->GetStudentID() << ": " << classRosterArray[tempID]->getAverageDaysInCourse() << endl;
}

string roster::getID(int ID) {
	if (classRosterArray[ID] != nullptr) { 
		return classRosterArray[ID]->GetStudentID();
	}
}
void roster::printDegreeProgram(DegreeProgram program){
	cout << "degree program" << endl;
	for (int i = 0; i < numStudents; ++i){
		if (classRosterArray[i]->GetDegreeProgram() == program){
			classRosterArray[i]->print();
		}
	}
}