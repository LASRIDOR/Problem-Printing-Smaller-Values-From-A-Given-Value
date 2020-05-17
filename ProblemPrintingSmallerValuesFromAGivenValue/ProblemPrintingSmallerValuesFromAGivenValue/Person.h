#define _CRT_SECURE_NO_WARNINGS
#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;


class Person {
private:
	int key;
	string name;
public:
	Person() = default;
	Person(int key, string name);
	bool operator==(const Person& other);
	friend ostream& operator<<(ostream& os, const Person& person);

	void SetKey(int key);
	void SetName(string name);

	int GetKey();
	string GetName();
	void PrintPerson();

};


#endif // !_PERSON_H