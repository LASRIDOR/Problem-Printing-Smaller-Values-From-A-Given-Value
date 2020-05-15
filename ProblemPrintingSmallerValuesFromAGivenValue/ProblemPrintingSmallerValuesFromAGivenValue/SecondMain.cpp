
//for checking and making table

/*

#include "MainHeader.h"
#include <fstream>

int main() {
	int k;
	int size;
	int NumComp = 0;
	Person* testBST;
	Person* testRandSelection;
	Person* testHeap;
	Person kperson;
	char filename[10][12];
	char nametestfile[50];
	ofstream testfile;

	for (int i = 0; i < 10; i++) {
		cout << endl << "File no." << i + 1 << ":"; // get name of file
		//cleanbuffer();
		cin.getline(filename[i], 12);
		cout << endl << "Name the test file (max name 49 size)" << ":"; // get name of file
		//cleanbuffer();
		cin.getline(nametestfile, 50);
		testfile.open(nametestfile);
		testfile << "BST" << "," << "," << "," << "RandSelection" << "," << "," << "," << "selectHeap" << endl;
		for (int j = 0; j < 40; j++) {
			testBST = MakeArrFromFile(filename[i], &k, &size);
			testRandSelection = new Person[size];
			testHeap = new Person[size];
			CopyPersons(testRandSelection, testBST, size);
			CopyPersons(testHeap, testBST, size);
			NumComp = 0;
			kperson = BST(testBST, size, k, &NumComp);
			cout << "BST:" << endl;
			testfile << kperson.GetName() << "," << kperson.GetId() << "," << NumComp << ",";
			kperson.PrintPerson();
			cout << "NumComp:" << NumComp << endl << endl;
			NumComp = 0;
			kperson = RandSelection(testRandSelection, size, k, &NumComp);
			testfile << kperson.GetName() << "," << kperson.GetId() << "," << NumComp << ",";
			cout << "RandSelection :" << endl;
			kperson.PrintPerson();
			cout << "NumComp:" << NumComp << endl << endl;
			NumComp = 0;
			cout << "selectHeap :" << endl;
			kperson = selectHeap(testHeap, size, k, &NumComp);
			testfile << kperson.GetName() << "," << kperson.GetId() << "," << NumComp << endl;
			kperson.PrintPerson();
			cout << "NumComp:" << NumComp << endl << endl;
			delete[]testBST;
			delete[]testRandSelection;
			delete[]testHeap;
		}
		testfile.close();
	}

}
*/