#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

char determine_grade(int smarks[], int cw[], int i);
void discard_line(ifstream &in);
void print_students_records(string sid[],int assessmentMarks[MAX_SIZE][5], int smarks[], int mst[MAX_SIZE],char sgrades[], int size, int cw[MAX_SIZE]);
int total_failed_students(int smarks[], int size);
void course_work(int mst[], int assessment[][5], int size, int cw[MAX_SIZE]);

int main()
{
    string id[MAX_SIZE];
    int marks[MAX_SIZE];
    int assessmentMarks[MAX_SIZE][5];
    int mst[MAX_SIZE];
    char grade[MAX_SIZE];
    int total_records;
    int choice;
    char response;
    int cw[MAX_SIZE];

    ifstream input;

    cout<<"This program determines the grades of students."<<endl;

    cout<<"Program menu:"<<endl
        <<"(1) Read data from file"<<endl
        <<"(2) Read data from standard input"<<endl;
    cout<<"Enter the number of your choice: ";
    cin>>choice;

    cout<<endl;

    if (choice == 1){
        input.open("students.txt",ios::in);

        discard_line(input);

        total_records = 0;

        while(!input.eof())
        {    
            input >> id[total_records]; // id

            for(int i = 0; i < 5; i++)
            {
                input >> assessmentMarks[total_records][i]; // assessment marks
            }
            input >> mst[total_records]; // mst mark
            input >> marks[total_records]; // final exam
            input >> ws;
            

            total_records++;
            
        }
    }

    else if (choice ==2){
        total_records = 0;
        do{
            cout<<"Enter student ID: ";
            cin>>id[total_records];

            cout<<"Enter marks gained: ";
            cin>>marks[total_records];

            cout<<"\nPress y or Y to enter another record.";
            cin>>response;
            cout<<endl;
            total_records++;
        }while((response == 'y' || response == 'Y') && (total_records < MAX_SIZE));
    }
    else{
        cout<<"ERROR! incorrect choice"<<endl;
        system("PAUSE");
        exit(1);
    }



    input.close();

    print_students_records (id, assessmentMarks, marks,mst, grade, total_records, cw);

    cout<<"\n\nTotal students failed the course are: "
        <<total_failed_students(marks, total_records)<<endl;

    return 0;
}

void print_students_records(string sid[],int assessmentMarks[MAX_SIZE][5] ,int smarks[],int mst[MAX_SIZE], char sgrades[],int size, int cw[MAX_SIZE]){
    cout<<"\nstudents records"<<endl<<endl;
    cout << setw(7) << "ID" << setw(20) << "Assignment" << setw(10) << "MST" << setw(10) << "Final" << setw(7) << "CW" << "Grade" << setw(7) << endl;
    for (int i = 0; i < size; i++){
        cout << setw(7) << sid[i] ; 
        for (int j = 0; j < 5; j++)
        {
            cout << setw(4) << assessmentMarks[i][j];
        }
        
        cout << setw(7)<< mst[i] ;
        cout << setw(7)<< smarks[i];
        course_work(mst, assessmentMarks, i, cw);
        cout << setw(7)<< determine_grade(smarks, cw, i) << endl;
        
        
    }
}

void course_work(int mst[], int assessment[][5], int size, int cw[MAX_SIZE]){
    int ass_sum = 0;
    
    for (int j = 0; j < 5; j++)
    {
        ass_sum += assessment[size][j];
        
    }
    ass_sum += mst[size];
    
    cout << setw(7) << ass_sum;
    cw[size] = ass_sum;
}

int total_failed_students(int smarks[], int size){
    int failures;
    failures = 0;

    for (int i = 0; i < size; i++){
        if (smarks[i] < 50)
            failures++;
    }

    return failures;
}

char determine_grade(int smarks[], int cw[], int i){
     char sgrade;
     smarks[i] += cw[i];

     if (smarks[i] >= 80)
        sgrade = 'A';
     else if(smarks[i] >= 65)
        sgrade = 'B';
     else if(smarks[i] >= 50)
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
