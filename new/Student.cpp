#include "Student.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

Student::Student(){
	id = "";
	marks = 0;
	grade = 'a';
//	cout << "Student Constructor Called" << endl;
}

//Destructor
Student::~Student()
{ 
//	cout << "Student Destructor Called" << endl; 
}


//Setter methods

//void Student::set_id(string id)
//{
//	this->id = id;
//}
void Student::setMarks(int mark)
{
	this->marks = mark;
}
void Student::setGrade(char grade)
{
	this->grade = grade;
}

void Student::determine_grade(int marks){
	if (marks >= 80)
		grade = 'A';
	else if(marks >= 65)
		grade = 'B';
	else if(marks >= 50)
		grade = 'C';
	else
		grade = 'D';
		
	this->setGrade(grade);
}


//Getter methods

//string Student::get_id()
//{
//	return id;
//}
int Student::getMarks()
{
	return marks;
}

char Student::getGrade()
{
	
	return this->grade;
	 
}


