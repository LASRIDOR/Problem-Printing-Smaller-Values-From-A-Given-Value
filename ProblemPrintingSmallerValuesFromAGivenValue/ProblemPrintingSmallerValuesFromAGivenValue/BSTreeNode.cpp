#include "BSTreeNode.h"

BSTreeNode::BSTreeNode() {
    this->key = 0;
	this->left = nullptr;
	this->right = nullptr;
}

//------------------------------------------------------------------------------------------------------------

BSTreeNode::BSTreeNode(int key,const Person& data, BSTreeNode* left, BSTreeNode* right) : data(data) {
    this->key = key;
	this->left = left;
	this->right = right;
}

//------------------------------------------------------------------------------------------------------------

BSTreeNode::BSTreeNode(const BSTreeNode& other) {
    key = other.key;
    this->data = other.data;
    this->left = other.left;
    this->right = other.right;
}

//------------------------------------------------------------------------------------------------------------

BSTreeNode::~BSTreeNode() {
    if (this->left != nullptr) {
        delete left;
    }
    if (this->right != nullptr) {
        delete right;
    }
}

//-----------------------------------------------------------------------------------

int BSTreeNode::GetKey() {
    return this->key;
}

//-----------------------------------------------------------------------------------

void BSTreeNode::inorder() {
    /* first recur on left child */
    if (left != nullptr) {
        left->inorder();
    }
    /* then print the data of node */
    this->data.PrintPerson();

    /* now recur on right child */
    if (right != nullptr) {
        right->inorder();
    }
}

//-----------------------------------------------------------------------------------

void BSTreeNode::preorder() {
    /* then print the data of node */
    this->data.PrintPerson();
    /* first recur on left child */
    if (left != nullptr) {
        left->inorder();
    }
    if (right != nullptr) {
        right->inorder();
    }
}

//-----------------------------------------------------------------------------------

void BSTreeNode::postorder() {
    /* first recur on left child */
    if (left != nullptr) {
        left->inorder();
    }
    /* now recur on right child */
    if (right != nullptr) {
        right->inorder();
    }
    /* then print the data of node */
    this->data.PrintPerson();
}

//-----------------------------------------------------------------------------------

void BSTreeNode::PrintLowerThanKinorder(int k,int* NumCompInPrintOrder) {
    /* first recur on left child */
    if (left != nullptr) {
        left->PrintLowerThanKinorder(k,NumCompInPrintOrder);
    }
    /* then print the data of node */
    *(NumCompInPrintOrder)++;
    if (this->key < k) {
        this->data.PrintPerson();
    }
    else { // (this->key >= k)
        return;
    }

    /* now recur on right child */
    if (right != nullptr) {
        right->PrintLowerThanKinorder(k, NumCompInPrintOrder);
    }
}