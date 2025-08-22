#ifndef ROSTER_H_
#define ROSTER_H_
#include "student.h"
#include <string>
using namespace std;

// Defining of roster class 
class roster{

private:
	// Declaring classRosterArray pointer to acquire student data
	student* classRosterArray[5];
	const int numStudents = 5;
	

public:
	roster();
	~roster(); 
	// required functions for section E
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int dCI1, int dCI2, int dCI3, DegreeProgram degreeProgram);
	void removal(string studentID);	
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvaildEmails();
	void printDegreeProgram(DegreeProgram program);
	string getID(int ID);

};

#endif // end ROSTER_H_
