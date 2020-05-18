#include "Node.h"

Node::Node(Person person, Node* nextnode) : person(person){
    this->next = nextnode;
}

ostream& operator<<(ostream& os, const Node& node) {
    os << node.person;
    if (node.next != nullptr) {
        os << *node.next;
    }
    return os;
}

Person Node::getPerson() const {
    return this->person;
}

int Node::getPersonKey() {
    return this->person.GetKey();
}

Node *Node::DeleteAfter() {
    Node *temp = next;
    if (next == nullptr){
        return nullptr;
    }
    next = temp->next;
    return temp;
}

void Node::insertAfter(Node* newNode) {
    newNode->next = this->next;
    next = newNode;
}

void Node::printNode() {
    this->person.PrintPerson();
    if (this->next != nullptr) {
        cout << endl;
        this->next->printNode();
    }
}

Node *Node::getNext() const {
    return next;
}
