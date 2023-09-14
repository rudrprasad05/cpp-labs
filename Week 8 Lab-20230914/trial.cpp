#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

void discard_line(ifstream &in);

int main(){
	
	string str;
	int size;
	int total_records = 0;
	int *ptr;
	
	ifstream input;
	
	input.open("marks.txt", ios::in);
	
	if(!input){
		cout << "not open" << endl;
	}
	else{
		cout << "opened" << endl;
	}
	
	
	input >> str >> size;
	discard_line(input);
	discard_line(input);
	discard_line(input);
	
	ptr = new int[size];
	
	while(input>>ws && !input.eof()){
        input >> ptr[total_records];
        total_records++;
        
    }
 
    for (int i = 0; i < size; i++){
    	cout << ptr[i] << " ";
	}
	
}

void discard_line(ifstream &in)
{
    char c;

    do
		in.get(c);
    while (c!='\n');
}
