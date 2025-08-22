#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "degree.h"
using namespace std;

// Defining student class
class student {

private:

	string studentID, firstName, lastName, emailAddress;
	int age;
	int daysinCourse[courseLimit]; // array of number of days to complete each course
	DegreeProgram program;
	string intialDegreeProgram[3] = { "SECURITY", "NETWORK", "SOFTWARE" };
	// string DegreeProgram[] = {"SECURITY", "NETWORK", "SOFTWARE"};


public:
	// declaring constructor including all input parameters
	student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse[], DegreeProgram program);

	// declaring accessors
	string GetStudentID(); 
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int GetDaysInCourse(int i);
	DegreeProgram GetDegreeProgram();

	// declaring mutators
	void SetstudentID(string studentID);
	void SetfirstName(string firstName);
	void SetlastName(string lastName);
	void SetemailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(int daysinCourse[]);
	void SetDegreeProgram(DegreeProgram program);
	// print specific student data
	void print();
	// function for emailaddress valdiation
	bool validateEmailAddress();
	// function to calculate average days in course per student
	double getAverageDaysInCourse();
};

#endif // end STUDENT_H_