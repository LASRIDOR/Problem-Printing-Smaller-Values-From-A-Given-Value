
#include "List.h"

SortingList::SortingList() {
    this->NumComp = 0;
    MakeEmptyList();
}

void SortingList::MakeEmptyList() {
    head = tail = nullptr;
}

SortingList::SortingList(const SortingList& other) {
    head = tail = nullptr;
    Node* itemToCopyFromList = other.head;
    while(itemToCopyFromList) {
        addToTail(itemToCopyFromList->person);
        itemToCopyFromList = itemToCopyFromList->next;
    }
}

void SortingList::addToTail(Person person) {
    Node* newNode = new Node(person, nullptr);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

SortingList::SortingList(SortingList&& other) {
    head = other.head;
    tail = other.tail;

    other.head = nullptr;
    other.tail = nullptr;
}

SortingList::~SortingList() {
    Node* itemToDeleteInList = head;
    Node* nextItem;
    while(itemToDeleteInList) {
        nextItem = itemToDeleteInList->next;
        delete itemToDeleteInList;
        itemToDeleteInList = nextItem;
    }
}

const SortingList& SortingList::operator=(const SortingList& other) {
    if (this != &other) {
        Node* itemInListOther = other.head;
        while (itemInListOther) {
            addToTail(itemInListOther->person);
            itemInListOther = itemInListOther->next;
        }
    }
    else {
        return *this;
    }
}

bool SortingList::isEmpty() const {
    return head == nullptr;
}

/**
 * Adds a new computer to the end of the list. Creates a node from the computer. Overloads the other addToTail.
 * @param computer
 */
void SortingList::addSortedToList(Person person) {
    Node* newNode = new Node(person, nullptr);
    Node* currInList = this->head;
    Node* placeToInsertAfter = nullptr; // functioning as prev in the while
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        while (currInList != nullptr) {
            this->NumComp++;
            if (currInList->getPersonKey() >= person.GetKey()) {
                break;
            }
            placeToInsertAfter = currInList;
            currInList = currInList->next;
        }
        if (placeToInsertAfter == nullptr) {
            Node* temp = head;
            this->head = newNode;
            newNode->next = temp;
        }
        else if (placeToInsertAfter == nullptr) { // curr is tail of list
            tail->next = newNode;
            tail = newNode;
        }
        else {
            placeToInsertAfter->insertAfter(newNode);
        }
    }
}

void SortingList::deleteNode(Person personToDelete) {
    if (isEmpty()) {
        cout << "Error: QUEUE EMPTY\n";
        exit(1);
    }
    Node* temp = head;
    if (temp->getPerson() == personToDelete) {
        head = temp->next;
        delete[] temp;
    }
    else {
        while (temp != nullptr)
        {
            if (temp->next->getPerson() == personToDelete) {
                temp->DeleteAfter();
            }
        }
    }
}


/**
 * Finds computerToFind in the list by traversing the list.
 * @param computerToFind
 * @return Found computer, returns null if not found.
 */
Node* SortingList::find(Person personToFind) {
    Node *NodeInList = head;
    while (NodeInList) {
        if(NodeInList->person == personToFind) {
            return NodeInList;
        }
        NodeInList = NodeInList->next;
    }
    return nullptr;
}

void SortingList::printList() const {
    if (head != nullptr) {
        head->printNode();
    }
}

Node * SortingList::getHead() const {
    return head;
}

int SortingList::getNumComp() const {
    return this->NumComp;
}

ostream &operator<<(ostream &os, const SortingList&list) {
    if (list.head != nullptr) {
        os << *list.head;
    }
    return os;
}

void SortingList::OneCompare() {
    this->NumComp++;
}