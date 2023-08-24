#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
	public:
		Student(); //Constructor
		~Student(); //Destructor\
		
//		void set_id(std::string id);
		void setMarks(int marks);
		void setGrade(char grade);
		
//		string get_id();
		int getMarks();
		char getGrade();
		
		void determine_grade(int marks);
		
	private:
		string id;
		int marks;
		char grade;
};

#endif

