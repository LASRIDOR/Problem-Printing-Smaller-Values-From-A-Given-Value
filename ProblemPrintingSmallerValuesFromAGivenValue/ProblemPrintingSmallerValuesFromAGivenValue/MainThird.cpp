/*
#include "MainHeader.h"

int main() {
	int k;
	int size;
	int NumCompNaive = 0;
	int NumCompBST = 0;
	int NumCompQuickSort = 0;
	int NumCompFindKInputs = 0;
	Person* Original_arr;
	Person* testBST;
	Person* testQuickSort;
	Person* testNaive;
	Person* FindKInputs;
	Person kperson;

	Original_arr = MakeArrofPersons(&k, &size);
	//copying person arr
	FindKInputs = new Person[size];
	CopyPersons(FindKInputs, Original_arr, size);
	QuickSort(FindKInputs, 0, size - 1, &NumCompFindKInputs);

	for (int i = 0; i < 10; i++) {
		testBST = new Person[size];
		testQuickSort = new Person[size];
		testNaive = new Person[size];
		CopyPersons(testQuickSort, Original_arr, size);
		CopyPersons(testNaive, Original_arr, size);
		CopyPersons(testBST, Original_arr, size);
		if (i == 9) {// i+1 * 10 == 100 (all of the array)
			k = FindKInputs[((i + 1) * 10)-1].GetKey()+1;
		}
		else {
			k = FindKInputs[(i + 1) * 10].GetKey();
		}
		//checking NaivePrint
		NumCompNaive = NaivePrint(testNaive, size, k);
		cout << endl << endl;
		//checking BST
		NumCompBST = BSTPrint(testBST, size, k);
		cout << endl << endl;
		//checking QuickSort
		NumCompQuickSort = PrintBySort(testQuickSort, size, k);
		cout << endl << endl;

		cout << endl << "NaivePrint :" << NumCompNaive << "comparisons" << endl;
		cout << endl << "BSTPrint:" << NumCompBST << " comparisons" << endl;
		cout << endl << "QuickSort :" << NumCompQuickSort << "comparisons" << endl;

		// Delete dynamic allocation
		delete[]testBST;
		delete[]testQuickSort;
		delete[]testNaive;
	}
	delete[] Original_arr;
	delete[] FindKInputs;
}

*/