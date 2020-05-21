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
	cout << endl ;
	//checking BST
	NumCompBST = BSTPrint(testBST, size, k);
	cout << endl;
	//checking QuickSort
// pay attention that the testQuickSort array of person is changing directly
	NumCompQuickSort =  PrintBySort(testQuickSort, size, k);
	cout << endl ;

	cout << "NaivePrint: " << NumCompNaive << " comparisons" << endl;
	cout << "BSTPrint : " << NumCompBST << " comparisons" << endl;
	cout << "QuickSort : " << NumCompQuickSort << " comparisons" << endl;

	// Delete dynamic allocation
	delete[]testBST;
	delete[]testQuickSort;
	delete[]testNaive;
}
*/