
#ifndef ECOMMERCE_ITEMLIST_H
#define ECOMMERCE_ITEMLIST_H

#include <iostream>
#include "Node.h"

class SortingList {
private:
    int NumComp;
    Node* head;
    Node* tail;
public:
    void MakeEmptyList();
    void addSortedToList(Person person);
    void deleteNode(Person personToDelete);
    bool isEmpty()   const;
    void printList() const;
    Node *getHead()  const;
    int getNumComp() const;
    Node *find(Person personToFind);

public:
    SortingList();
    ~SortingList();
    SortingList(const SortingList& other);
    SortingList(SortingList&& other);

    const SortingList& operator=(const SortingList& other);
    friend ostream &operator<<(ostream &os, const SortingList&list);
private:
    void addToTail(Person person);
};


#endif //ECOMMERCE_ITEMLIST_H
