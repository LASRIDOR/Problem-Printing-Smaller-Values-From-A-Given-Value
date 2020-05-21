#include "MainHeader.h"

// QuickSort ---------------------------------------------------------------------------------------------
// get array of person and change them directly to be sorted according to their key
int PrintBySort(Person* arr, int n, int k) {
	int NumComp = 0;

	QuickSort(arr, 0, n-1, &NumComp);

	int index = 0;
	while (arr[index].GetKey() < k && index < n) {
		arr[index].PrintPerson();
		index++;
		NumComp++;
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
			(*NumComp)++;
			index++;
		}
	}
	SwapClass(arr[pivot], arr[index]);
	return index;
}

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
// this func makes a brand new tree every procedure and makes a search binary tree
// and then prints the only person that their key is lowest then k
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
// this func makes arr of person from file
Person* MakeArrFromFile(string filename,int* k,int* size) {
	Person* arr;
	ifstream file;
	int temp_id;
	string temp_fname;
	string temp_lname;
	file.open(filename);
	file >> *size;
	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		string full_name;
		file >> temp_id;
		file.seekg(1,ios::cur); // skip space
		cin >> temp_fname;
		cin >> temp_lname;
		full_name.append(temp_fname + ' ' + temp_lname);
		arr[i].SetKey(temp_id);
		arr[i].SetName(full_name);
	}
	file >> *k;
	file.close();
	CheckValidInput(arr, *size);
	return arr;
}

// -----------------------------------------------------------------------------------------------------------
// this func makes arr of person from the console
Person* MakeArrofPersons(int* k, int* size) {
	Person* arr;
	int temp_id;
	string temp_fname;
	string temp_lname;
	cin >> *size;

	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		string full_name;
		cin >> temp_id;
		cin.ignore(1, ' '); // for space
		cin >> temp_fname;
		cin >> temp_lname;
		full_name.append(temp_fname+' '+ temp_lname);
		arr[i].SetKey(temp_id);
		arr[i].SetName(full_name);
	}
	cin >> *k;
	CheckValidInput(arr, *size);
	return arr;
}

// -----------------------------------------------------------------------------------------------------------
// checks if the values are valid
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
