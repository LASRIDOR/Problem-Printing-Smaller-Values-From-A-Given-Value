
#include "MainHeader.h"

int main() {
	int k;
	int size;
	int NumComp = 0;
	Person* testBST;
	Person* testRandSelection;
	Person* testHeap;
	Person kperson;

	testBST = MakeArrofPersons(&k, &size);
	//copying person arr
	testRandSelection = new Person[size];
	testHeap = new Person[size];
	CopyPersons(testRandSelection, testBST, size);
	CopyPersons(testHeap, testBST, size);
	//checking BST
	NumComp = 0;
	kperson = BST(testBST, size, k, &NumComp);
	cout << "BST:" << endl;
	kperson.PrintPerson();
	cout << "NumComp:" << NumComp << endl << endl;
	//checking Randselection
	NumComp = 0;
	kperson = RandSelection(testRandSelection, size, k, &NumComp);
	cout << "RandSelection :" << endl;
	kperson.PrintPerson();
	cout << "NumComp:" << NumComp << endl << endl;
	//checking Heap
	NumComp = 0;
	cout << "selectHeap :" << endl;
	kperson = selectHeap(testHeap, size, k, &NumComp);
	kperson.PrintPerson();
	cout << "NumComp:" << NumComp << endl << endl;
	// Delete dynamic allocation
	delete[]testBST;
	delete[]testRandSelection;
	delete[]testHeap;
}

