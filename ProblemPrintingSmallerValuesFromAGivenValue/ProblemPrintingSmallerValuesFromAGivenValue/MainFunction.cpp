#include "MainHeader.h"

// QuickSort ---------------------------------------------------------------------------------------------
int PrintBySort(Person* arr, int n, int k) {
	int NumComp = 0;

	QuickSort(arr, 0, n-1, &NumComp);

	for (int i = 0; i < k-1; i++) {
		arr[i].PrintPerson();
	}

	return NumComp;
}

// -----------------------------------------------------------------------------------------------------------

void QuickSort(Person* arr, int left, int right,int* NumComp) {
	int pivot;

	if (left < right) {
		pivot = Partition(arr, left,right, NumComp);
		QuickSort(arr,left,pivot-1, NumComp);
		QuickSort(arr, pivot+1, right, NumComp);
	}
}

// -----------------------------------------------------------------------------------------------------------

// Partitioning the array on the basis of values at high as pivot value.
int Partition(Person* arr, int left, int right, int* NumComp) {
	int pivot, index, i;
	index = left;
	pivot = right;
	for (i = left; i < right; i++) {
		// finding index of pivot.
		if (arr[i].GetKey() < arr[pivot].GetKey()) {
			SwapClass(arr[i], arr[index]);
			index++;
		}
		(*NumComp)++;
	}
	SwapClass(arr[pivot], arr[index]);

	return index;
}
/*
int Partition(Person* arr,int left,int right, int* NumComp) {
	int i = left + 1, j = right;
	int winning_num;
	srand((unsigned)time(NULL));
	Sleep(7 * left); // in program like this rand time will always give the same value
	winning_num = ((rand() % (right - left+ 1)) + left);
	if (winning_num != left) {
		SwapClass(arr[winning_num], arr[left]);
	}
	while (i < j) {
		while (arr[i].GetId() <= arr[left].GetId()) {
			i++;
			(*NumComp)++;
		}
		while (arr[j].GetId() > arr[left].GetId()) {
			j--;
			(*NumComp)++;
		}
		if (i < j) {
			SwapClass(arr[i], arr[j]);
		}
	}//big while
	SwapClass(arr[j],arr[left]);
	return j;
}
*/

// -----------------------------------------------------------------------------------------------------------

void SwapClass(Person& p1,Person& p2) {
	Person tmp = std::move(p1);
	p1 = std::move(p2);
	p2 = std::move(tmp);
}

void SwapClass1(Person& p1, Person& p2) {
	std::swap(p1,p2);
}

// -----------------------------------------------------------------------------------------------------------

//Binary Tree Selection --------------------------------------------------------------------------------------

int BSTPrint(Person* arr, int n, int k) {
	BSTree tree;
	for (int i = 0; i < n; i++) {
		tree.Insert(arr[i].GetKey(), arr[i]);
	}
	tree.printLowerThanK(k);
	return tree.GetNumCopm();
}

// -----------------------------------------------------------------------------------------------------------

void cleanbuffer() { // clean buffer for get function
	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
}

// -----------------------------------------------------------------------------------------------------------

Person* MakeArrFromFile(string filename,int* k,int* size) {
	Person* arr;
	ifstream file;
	int temp_id;
	string temp_name;
	file.open(filename);
	file >> *size;
	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		file >> temp_id;
		file.seekg(1,ios::cur); // skip space
		file >> temp_name;
		arr[i].SetKey(temp_id);
		arr[i].SetName(temp_name);
	}
	file >> *k;
	file.close();
	CheckValidInput(arr, *size);
	return arr;
}

// -----------------------------------------------------------------------------------------------------------

Person* MakeArrofPersons(int* k, int* size) {
	Person* arr;
	int temp_id;
	string temp_name;
	cin >> *size;

	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		cin >> temp_id;
		cin.ignore(1, ' ');
		cin >> temp_name;
		arr[i].SetKey(temp_id);
		arr[i].SetName(temp_name);
	}
	cin >> *k;
	CheckValidInput(arr, *size);
	return arr;
}

// -----------------------------------------------------------------------------------------------------------

void CheckValidInput(Person* arr, int size) {
	for (int i = 0; i < size;i++) {
		for (int j = i+1; j < size;j++) {
			if (arr[i].GetKey() == arr[j].GetKey()) {
				cout << "invalid input" << endl;
				exit(1);
			}
		}
	}
}

// -----------------------------------------------------------------------------------------------------------

void CopyPersons(Person* destination, Person* source,int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

// -----------------------------------------------------------------------------------------------------------

int NaivePrint(Person* arr, int n, int k) {
	SortingList kLowest;
	for (int i = 0; i < n; i++) {
		if (arr[i].GetKey() < k) {
			kLowest.addSortedToList(arr[i]);
		}
		kLowest.OneCompare();
	}
	cout << kLowest;
	return kLowest.getNumComp();
}

// -----------------------------------------------------------------------------------------------------------
