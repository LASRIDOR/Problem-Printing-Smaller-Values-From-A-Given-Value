
#include "List.h"

SortingList::SortingList() {
    MakeEmptyList();
}

void SortingList::MakeEmptyList() {
    head = tail = nullptr;
}

SortingList::SortingList(const SortingList& other) {
    head = tail = nullptr;
    Node* itemToCopyFromList = other.head;
    while(itemToCopyFromList) {
        Node* CopiedNode = new Node(*itemToCopyFromList);
        CopiedNode->next = nullptr;
        addToTail(CopiedNode);
        itemToCopyFromList = itemToCopyFromList->next;
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
            Node* copyOfItemInListOther = new Node(*itemInListOther);
            copyOfItemInListOther->next = nullptr;
            addToTail(copyOfItemInListOther);
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
void SortingList::addToTail(Person person) {
    Node* newNode = new Node(person, nullptr);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void SortingList::deleteNode(Person personToDelete) {
    if (isEmpty()) {
        cout << "Error: QUEUE EMPTY\n";
        exit(1);
    }
    Node* temp = head;
    if (temp->getPerson == personToDelete) {
        head = temp->next;
        delete[] temp;
    }
    else {
        while (temp != nullptr)
        {
            if (temp->next->getPerson == personToDelete) {
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
        if(NodeInList->getPerson == personToFind) {
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

ostream &operator<<(ostream &os, const SortingList&list) {
    Node *currentNode = list.head;
    while (currentNode) {
        os << currentNode->printNode << "->";
        currentNode = currentNode->getNext();
    }
    return os;
}
