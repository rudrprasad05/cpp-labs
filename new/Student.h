#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {
	public:
		Student(); //Constructor
		~Student(); //Destructor\
		
		void setId(std::string id);
		void setMarks(int marks);
		void setGrade(char grade);
		
		string getId();
		int getMarks();
		char getGrade();
		
		void determine_grade(int marks);
		
	private:
		string id;
		int marks;
		char grade;
};

#endif

