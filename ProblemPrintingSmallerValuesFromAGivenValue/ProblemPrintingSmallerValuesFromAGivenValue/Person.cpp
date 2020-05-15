#include "Person.h"


Person::Person(){
	this->id = -1;
	this->name = nullptr;
}
//-----------------------------------------------------------------------------------------
Person::Person(int id, char* name){
	SetId(id);
	SetName(name);
}
//-----------------------------------------------------------------------------------------
Person::Person(const Person& other) {
//	cout << "in person(copy)" << endl; //just for check 
	this->name = nullptr;
	*this = other;
}
//-----------------------------------------------------------------------------------------
Person::Person(Person&& other) {
//	cout << "in person(move)" << endl; //just for check 
	this->name = other.name;
	other.name = nullptr;
	this->id = other.id;
}
//-----------------------------------------------------------------------------------------
const Person& Person::operator=(const Person& other) {
	if (this != &other) {
		id = other.id;
		delete []name;
		name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
Person::~Person() {
	delete name;
}
//-----------------------------------------------------------------------------------------
void Person::SetId(int id) {
	this->id = id;
}
//-----------------------------------------------------------------------------------------
void Person::SetName(char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
//-----------------------------------------------------------------------------------------

int Person::GetId() {
	return this->id;
}
//-----------------------------------------------------------------------------------------
char* Person::GetName() {
	return this->name;
}

void Person::PrintPerson() {
	cout <<"Person :"<< endl << "Name:"<< this->name<< endl << "Id:"<< this->id << ' ' << endl;
}
//end of cpp item