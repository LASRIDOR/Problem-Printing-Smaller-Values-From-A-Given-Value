#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
#include "Person.h"

using namespace std;
#pragma warning (disable: 4996)


class Node {
    friend class SortingList;
public:
    Node(Person person, Node* nextnode);
    friend ostream& operator<<(ostream& os, const Node& node);

    Person getPerson() const;
    int getPersonKey();
    Node* getNext() const;
    Node* DeleteAfter();
    void insertAfter(Node* newNode);
    void printNode();

private:
    Person person;
    Node* next;
};

#endif // !__NODE_H