
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
	NumComp = BSTPrint(testBST, size, k);
	cout << "BSTPrint:" << NumComp << " comparisons" << endl;
	//checking QuickSort
	NumComp =  PrintBySort(testRandSelection, size, k);
	cout << "QuickSort :"<< NumComp << "comparisons" << endl;
	//checking NaivePrint
	NumComp = NaivePrint(testHeap, size, k);
	cout << "NaivePrint :" << NumComp << "comparisons" << endl;


	// Delete dynamic allocation
	delete[]testBST;
	delete[]testRandSelection;
	delete[]testHeap;
}

