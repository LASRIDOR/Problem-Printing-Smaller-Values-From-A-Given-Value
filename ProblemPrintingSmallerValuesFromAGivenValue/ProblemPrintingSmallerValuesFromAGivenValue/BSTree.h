#ifndef _BSTREE_H
#define _BSTREE_H

#include "BSTreeNode.h"

class BSTree {
private:
	BSTreeNode* root;
	int NumComp;
public:
	BSTree();
	~BSTree();

	BSTreeNode* Find(int key);
	void Insert(int key, Person item);
	void Delete(int id);
	BSTreeNode* FindMaxInRoot(BSTreeNode* node);
	Person Min(void);
	Person Max(void);
	bool IsEmpty();
	void MakeEmpty();
	void PrintTree(void);
	int GetNumCopm();
	void SwapClass(BSTreeNode& p1, BSTreeNode& p2);
	void printLowerThanK(int i_K);
	void printLowerThanK(BSTreeNode* i_Node,int i_K);
};

#endif // !_BSTREE_H
