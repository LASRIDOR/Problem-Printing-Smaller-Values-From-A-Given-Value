
#include "MainHeader.h"

int main() {
	int k;
	int size;
	int num_of_files;
	int NumComp = 0;
	Person* testBST;
	Person* testRandSelection;
	Person* testHeap;
	Person kperson;
	char** filename;
	cout << "this program compares between BST & RandSelection & Heap to find the best solution for selection problem" << endl ;
	cout << "This Program gets files of the type .txt that first gives the size of the arr of persons "
		<< endl<<"and then every person in a single line first id and then the name "
		<<endl<<"and in the end gives the the k person that he want to find" << endl;
	cout << "please enter the number of file that you are about to enter :" << endl;
	cin >> num_of_files;

	filename = new char* [num_of_files];


	for (int i = 0; i < num_of_files; i++) {
		filename[i] = new char[50];
		// Getting the name of the file and make a person arr
		cout << endl << "File no." << i + 1 << ":"; // get name of file
		if (i == 0) {
			cleanbuffer();
		}
		cin.getline(filename[i], 50);
		testBST = MakeArrFromFile(filename[i], &k, &size);
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

}
