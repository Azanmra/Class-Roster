#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

int main()
{
	// Creation of student data in main function 
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Azan,Raja,araja15@wgu.edu,23,25,30,40,SOFTWARE" // Modifcation for student data to include personal information
	};

	// Printing information for coding project; stating project information and information of student who created it.
	cout << "C867: Scripting and Programming, C++" << endl;
	cout << "Azan Raja" << endl;
	cout << "Student ID: 011556294" << endl;

	// Creation of classroster to hold information of students to classroster
	roster* classroster = new roster(); 

	classroster->printAll(); 

	classroster->printInvaildEmails();

	// Print average days of course 
	cout << "\nAverage Days in Course" << endl;

	// Looping average days in course specific to student ID's
	for (int i = 0; i < 5; ++i) { 
		string studentID = classroster->getID(i); 
		classroster->printAverageDaysInCourse(studentID);
	}
	cout << endl;

	classroster->printDegreeProgram(SOFTWARE); 

	classroster->removal("A3");

	classroster->printAll();

	classroster->removal("A3");

	return 0;
}
