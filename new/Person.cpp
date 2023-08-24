#include "Person.h"

void Person::set_id(string id){
	this->id = id;
}
void Person::set_name(string name){
	this->name = name;
}
void Person::set_address(string address){
	this->address = address;
}
void Person::set_phone(string phone){
	this->phone = phone;
}
void Person::set_email(string email){
	this->email = email;
}
void Person::set_dob(string dob){
	this->dob = dob;
}
void Person::set_citizenship(string citizenship){
	this->citizenship = citizenship;
}

void Person::print(){
    cout<<"\nID: "<<id;
    cout<<"\nName: "<<name;
    cout<<"\nAddress: "<<address;
    cout<<"\nPhone: "<<phone;
    cout<<"\nEmail: "<<email;
    cout<<"\nDob: "<<dob;
    cout<<"\nCitizenship: "<<citizenship<<endl<<endl;
}

string Person::get_id(){
	return this->id;
}
string Person::get_name(){
	return name;
}
string Person::get_address(){
	return address;
}
string Person::get_phone(){
	return phone;
}
string Person::get_email(){
	return email;
}
string Person::get_dob(){
	return dob;
}
string Person::get_citizenship(){
	return citizenship;
}

