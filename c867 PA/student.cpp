#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>  // set spacing for print() function 
using namespace std;

// creation of student class 
student::student(string newSID, string newFN, string newLN, string newEA, int newAge, int newDIC[], DegreeProgram newdegreeProgram) {
	SetstudentID(newSID);
	SetfirstName(newFN);
	SetlastName(newLN);
	SetemailAddress(newEA);
	SetAge(newAge);
	SetDaysInCourse(newDIC);
	SetDegreeProgram(newdegreeProgram);
}

// acessors
string student::GetStudentID(){
	return studentID;
}

string student::GetFirstName(){
	return firstName;
}

string student::GetLastName(){
	return lastName;
}

string student::GetEmailAddress(){
	return emailAddress;
}

int student::GetAge(){
	return age;
}

int student::GetDaysInCourse(int days){
	return daysinCourse[days];
}

DegreeProgram student::GetDegreeProgram(){
return program;
}

// mutuators 
void student::SetstudentID(string newSID){
	this->studentID = newSID;
}

void student::SetfirstName(string newFN){
	this->firstName = newFN;
}

void student::SetlastName(string newLN){
	this->lastName = newLN;
}

void student::SetemailAddress(string newEA){
	this->emailAddress = newEA;
}

void student::SetAge(int newAge){
	this->age = newAge;
}

void student::SetDegreeProgram(DegreeProgram newdegreeProgram) {
	this->program = newdegreeProgram;
}

void student::SetDaysInCourse(int newDIC[]){
	for (int i = 0; i < courseLimit; i++){
		daysinCourse[i] = newDIC[i];
	}
}

// calculating average days in course per student 
double student::getAverageDaysInCourse(){
	int total = 0;
	for (int i = 0; i < courseLimit; ++i){
		total += daysinCourse[i];
	}
	return static_cast<double>(total) / courseLimit;
}

// validation for email address for input parameters
bool student::validateEmailAddress(){
	if (emailAddress.find("@") == string::npos) {
		return true;
	}
	if (emailAddress.find(".") == string::npos) {
		return true;
	}
	if (emailAddress.find(" ") != string::npos) {
		return true;
	}
	else {
		return false;
	};
}

// print specific student data to console 
void student::print(){
	cout << left;
	cout << setw(5) << studentID << setw(10) << firstName << setw(10) << lastName << setw(5) << age  << "{";
	for (int i = 0; i < courseLimit; ++i) {
		cout << daysinCourse[i];
		if (i < 2) cout << ", ";
	}
	cout << "}" << setw(3) << " " << intialDegreeProgram[GetDegreeProgram()] << endl;
}
