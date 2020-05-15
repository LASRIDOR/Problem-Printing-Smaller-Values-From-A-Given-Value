#define _CRT_SECURE_NO_WARNINGS
#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;


class Person {
private:
	int id;
	char* name;
public:
	Person();
	Person(int id,char* name);
	Person(const Person& other);
	Person(Person&& other);
	~Person();
	const Person& operator=(const Person& other);

	void SetId(int id);
	void SetName(char* name);

	int GetId();
	char* GetName();
	void PrintPerson();
};


#endif // !_PERSON_H