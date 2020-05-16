
#ifndef ECOMMERCE_ITEMLIST_H
#define ECOMMERCE_ITEMLIST_H

#include <iostream>
#include "Node.h"

class SortingList {
private:
    Node* head;
    Node* tail;
public:
    void addToTail(Person person);
    void deleteNode(Person personToDelete);
    bool isEmpty()   const;
    void printList() const;
    Node *getHead()  const;
    Node *find(Person personToFind);

public:
    SortingList();
    ~SortingList();
    SortingList(const SortingList& other);
    SortingList(SortingList&& other);

    const SortingList& operator=(const SortingList& other);
    friend ostream &operator<<(ostream &os, const SortingList&list);
    void MakeEmptyList();
};


#endif //ECOMMERCE_ITEMLIST_H
