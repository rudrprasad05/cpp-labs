#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "Student.h"

using namespace std;

const int MAX_SIZE = 10;


void discard_line(ifstream &in);
void print_students_records(Student s[], int size);

int main(){

	Student student[MAX_SIZE];
    
    int total_records;

    ifstream input;
    cout<<"This program determines the grades of students."<<endl;

    input.open("students.txt",ios::in);

    if(!input){
		cerr<<"File could not be opened"<<endl;
		system("PAUSE");
		exit(1);
	}
    
    discard_line(input);

    total_records = 0;
	string id="";
	int marktemp=0;
	
    while(input>>id >>marktemp){
    	
    	student[total_records].setId(id);
    	student[total_records].setMarks(marktemp);
        total_records++;
    }

    for (int i = 0; i < total_records; i++){
        student[i].determine_grade(student[i].getMarks());
    }

    input.close();

    print_students_records (student, total_records );
    
    system("PAUSE");
    return 0;  
}

void print_students_records(Student student[], int size){
    cout<<"\n\nstudents' records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<student[i].getId() <<", marks: "<<student[i].getMarks() <<", grade: " <<student[i].getGrade()<<endl;
        
    }
    cout<<endl;
}



void discard_line(ifstream &in)
{
    char c;

    do
	    in.get(c);
	while (c!='\n');
}

