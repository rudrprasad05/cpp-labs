#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;


char determine_grade(int smarks);
void discard_line(ifstream &in);
void print_students_records(string sdate[], int stemp[], int shumidity[],int size);

int main()
{
    
    ifstream input;
    
    int total_records;
    int choice;
    char response;
    
    int size;
    string discard_str;
    
    string *date;
    int *temp;
    int *humidity;

    cout<<"This program determines the grades of students."<<endl;

    input.open("new.txt",ios::in);

    if(!input){
		cerr<<"File could not be opened"<<endl;
		system("pause");
        return 0;
	}

	input >> discard_str >> size;
	date = new string[size];
	temp = new int[size];
	humidity = new int[size];

    //ignore a line from the current position of the ifstream cursor
    discard_line(input);
    discard_line(input);
	discard_line(input);

    total_records = 0;

    while(input>>ws && !input.eof()){
        input >> date[total_records];
        input >> temp[total_records];
        input >> humidity[total_records];
        total_records++;
    }

//    for (int i = 0; i < total_records; i++){
//        grade[i] = determine_grade(marks[i]);
//    }

    input.close();

    print_students_records(date, temp, humidity, total_records);


    system("PAUSE");
    return 0;
}

void print_students_records(string sdate[], int stemp[], int shumidity[],int size){
    cout<<"\n\n Weather records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"date: "<<sdate[i]<<", temp: "<<stemp[i]<<", humidity: "<<shumidity[i]<<endl;
    }
    cout<<endl;
}

char determine_grade(int smarks){
     char sgrade;

     if (smarks >= 80)
        sgrade = 'A';
     else if(smarks >= 65)
        sgrade = 'B';
     else if(smarks >= 50)
        sgrade = 'C';
     else
        sgrade = 'D';

     return sgrade;
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}

void outlook(int temp[]){
	
}
