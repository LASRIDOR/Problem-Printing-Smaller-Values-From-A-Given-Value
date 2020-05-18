#include "BSTree.h"

BSTree::BSTree() {
	root = nullptr;
	NumComp = 0;
}

//-----------------------------------------------------------------------------------

BSTree::~BSTree() {
	delete root;
}

//-----------------------------------------------------------------------------------

BSTreeNode* BSTree::Find(int key) {
	BSTreeNode* temp = root;
	while (temp != nullptr) {
		if (key == temp->key){
			return temp;
			NumComp++;
		}
		else if (key < temp->key) {
			temp = temp->left;
			NumComp++;
		}
		else{ //key > temp->key
			temp = temp->right;
			NumComp++;
		}
	}
	return nullptr;
}

//-----------------------------------------------------------------------------------

void BSTree::Insert(int key,Person item) {
	// already checked in the main for duplicate id
	/*
	if (Find(key) != nullptr) {
		cout << "Error: key already exist";
		return;
	}
	*/
	BSTreeNode* temp = root; // cuur node in tree
	BSTreeNode* parent = nullptr; // parent of temp
	BSTreeNode* newnode; // new allocated node

	while (temp != nullptr) { // find parent of node
		parent = temp;
		if (key < temp->key) {
			temp = temp->left;
			NumComp++;
		}
		else {
			temp = temp->right;
			NumComp++;
		}
	}
	newnode = new BSTreeNode(key,item,nullptr,nullptr); // memory for node
	if (parent == nullptr) { // insert node as root
		root = newnode;
	}
	else if (key < parent->key) { // insert node as left child
		parent->left = newnode;
		NumComp++;
	}
	else {// insert node as right child
		parent->right = newnode;
		NumComp++;
	}
}

//-----------------------------------------------------------------------------------

void BSTree::Delete(int id) {
	BSTreeNode* v = Find(id);
	if (v == nullptr) {
		cout << "Error: Person Doesnt exist";
		return;
	}
	BSTreeNode* temp = root; // cuur node in tree
	BSTreeNode* parent = nullptr; // parent of temp

	while (temp != nullptr) { // find parent of node
		if (temp->left->key == v->key || temp->right->key == v->key) {
			parent = temp;
			NumComp++;
		}
		if (id < temp->key) {
			temp = temp->left;
			NumComp++;
		}
		else {
			temp = temp->right;
			NumComp++;
		}
	}
	// v has no children
	if (v->left != nullptr && v->right != nullptr) {
		if (parent->left->key == v->key) {
			parent->left = nullptr;
		}
		else {//(parent->right->key == v->key)
			parent->right = nullptr;
		}
		delete v;
	}
	// v has only one child
	else if (v->left != nullptr && v->right == nullptr) {
		if (parent->left->key == v->key) {
			parent->left = v->left;
		}
		else {//(parent->right->key == v->key)
			parent->right = v->left;
		}
		delete v;
	}
	else if (v->left == nullptr && v->right != nullptr) {
		if (parent->left->key == v->key) {
			parent->left = v->right;
		}
		else {//(parent->right->key == v->key)
			parent->right = v->right;
		}
		delete v;
	}
	//v has 2 children
	else if (v->left != nullptr && v->right != nullptr) {
		BSTreeNode* max_in_left = FindMaxInRoot(v->left);
		SwapClass(*max_in_left,*v);
		Delete(max_in_left->key);
	}
}

//-----------------------------------------------------------------------------------

BSTreeNode* BSTree::FindMaxInRoot(BSTreeNode* node) {
	if (node->right != nullptr) {
		return node;
	}
	else {
		return FindMaxInRoot(node->right);
	}
}

//-----------------------------------------------------------------------------------

Person BSTree::Min(void) {
	return root->data;
}

//-----------------------------------------------------------------------------------

Person BSTree::Max(void) {
	return FindMaxInRoot(root)->data;
}

//-----------------------------------------------------------------------------------

bool BSTree::IsEmpty() {
	if (root == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//-----------------------------------------------------------------------------------

void BSTree::MakeEmpty() {
	delete root;
}

//-----------------------------------------------------------------------------------

void BSTree::PrintTree(void) {
	if (root != nullptr) {
		root->inorder();
	}
}

//-----------------------------------------------------------------------------------

int BSTree::GetNumCopm() {
	return NumComp;
}

//-----------------------------------------------------------------------------------

void BSTree::SwapClass(BSTreeNode& p1, BSTreeNode& p2) {
	BSTreeNode temp(p1);
	temp = p1;
	p1 = p2;
	p2 = temp;
}

//-----------------------------------------------------------------------------------

void BSTree::printLowerThanK(int i_K) {
	int recNumComp = 0;
	this->root->PrintLowerThanKinorder(i_K,&recNumComp);
	this->NumComp = recNumComp + this->NumComp;
}