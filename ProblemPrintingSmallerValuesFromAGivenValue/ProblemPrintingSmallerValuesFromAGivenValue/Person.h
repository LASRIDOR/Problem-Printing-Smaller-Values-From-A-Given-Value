#define _CRT_SECURE_NO_WARNINGS
#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;


class Person {
private:
	int id;
	string name;
public:
	Person() = default;
	Person(int id, string name);

	void SetId(int id);
	void SetName(string name);

	int GetId();
	string GetName();
	void PrintPerson();
};


#endif // !_PERSON_H