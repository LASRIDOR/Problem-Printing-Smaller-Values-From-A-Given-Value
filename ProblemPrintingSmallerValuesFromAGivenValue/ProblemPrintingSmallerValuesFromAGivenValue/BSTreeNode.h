#ifndef _BSTREENODE_H
#define _BSTREENODE_H

#include <iostream>
using namespace std;
#include "Person.h"

class BSTreeNode {
	friend class BSTree;
private:
	int key; // key is the id of the person i call it key just for tree concepts
	Person data;
	BSTreeNode* left, * right;
public:
	BSTreeNode();
	BSTreeNode(int key,const Person& data, BSTreeNode* left, BSTreeNode*right);
	BSTreeNode(const BSTreeNode& other);
	~BSTreeNode();
	int GetKey();
	void inorder();
	void PrintLowerThanKinorder(int k, int* NumCompInPrintOrder);
	void preorder();
	void postorder();
};
#endif // !_BSTREENODE_H
