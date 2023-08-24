#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "Student.h"
#include "Person.h"

using namespace std;

const int MAX_SIZE = 10;


void discard_line(ifstream &in);
void print_students_records(Student s[], int size);
void print_info(Student &s);
void fill_info(Student &s);

		

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
    	
    	student[total_records].Person::set_id(id);
    	student[total_records].setMarks(marktemp);
        total_records++;
    }

    for (int i = 0; i < total_records; i++){
        student[i].determine_grade(student[i].getMarks());
    }

    input.close();

    print_students_records (student, total_records );
    
    system("PAUSE");
    
    fill_info(student[1]);
    print_info(student[1]);
    return 0;  
}

void print_students_records(Student student[], int size){
    cout<<"\n\nstudents' records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<student[i].Person::get_id() <<", marks: "<<student[i].getMarks() <<", grade: " <<student[i].getGrade()<<endl;
        
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


void print_info(Student &s){
	string name, address, phone, email, dob, citizenship;
	
	name = s.get_name();
	address = s.get_address();
	phone = s.get_phone();
	email = s.get_email();
	dob = s.get_dob();
	citizenship = s.get_citizenship();
	
	cout << name << address << phone << email << dob << citizenship;
}

void fill_info(Student &s){
	string name, address, phone, email, dob, citizenship;
	
	cout << "Enter name: ";
	cin >> name;
	s.set_name(name);
	
	cout << "Enter address: ";
	cin >> address;
	s.set_address(address);
	
	cout << "Enter phone: ";
	cin >> phone;
	s.set_phone(phone);
	
	cout << "Enter email: ";
	cin >> email;
	s.set_email(email);
	
	cout << "Enter dob: ";
	cin >> dob;
	s.set_dob(dob);
	
	cout << "Enter citizenship: ";
	cin >> citizenship;
	s.set_dob(citizenship);
}

