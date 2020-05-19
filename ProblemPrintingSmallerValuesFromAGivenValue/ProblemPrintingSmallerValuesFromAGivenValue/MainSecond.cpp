/*
#include "MainHeader.h"

int main() {
	int k;
	int size;
	int NumCompNaive = 0;
	int NumCompBST = 0;
	int NumCompQuickSort = 0;
	Person* testBST;
	Person* testQuickSort;
	Person* testNaive;
	Person kperson;

	testBST = MakeArrofPersons(&k, &size);
	//copying person arr
	testQuickSort = new Person[size];
	testNaive = new Person[size];
	CopyPersons(testQuickSort, testBST, size);
	CopyPersons(testNaive, testBST, size);

	//checking NaivePrint
	NumCompNaive = NaivePrint(testNaive, size, k);
	cout << endl << endl;
	//checking BST
	NumCompBST = BSTPrint(testBST, size, k);
	cout << endl<< endl;
	//checking QuickSort
	NumCompQuickSort =  PrintBySort(testQuickSort, size, k);
	cout << endl << endl;

	cout << endl << "NaivePrint :" << NumCompNaive << "comparisons" << endl;
	cout << endl << "BSTPrint:" << NumCompBST << " comparisons" << endl;
	cout << endl << "QuickSort :" << NumCompQuickSort << "comparisons" << endl;

	// Delete dynamic allocation
	delete[]testBST;
	delete[]testQuickSort;
	delete[]testNaive;
}

*/