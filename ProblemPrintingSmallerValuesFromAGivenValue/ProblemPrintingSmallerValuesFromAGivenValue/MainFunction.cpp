#include "MainHeader.h"


// Rand Selection ---------------------------------------------------------------------------------------------
Person RandSelection(Person* arr,int n, int k, int* NumComp) { // return k'th element in A
	return Select(arr, 0,n-1,k,NumComp);
}

Person Select(Person* arr, int left, int right,int k, int* NumComp) {// return k'th element in arr
	int pivot; // location of pivot
	int leftPart; // size of part left yo pivot (including pivot)

	pivot = RandomPivotPartition(arr,left,right,NumComp);
	leftPart = pivot - left +1;
	if (k == leftPart) {
		return arr[pivot];
	}
	if (k < leftPart) {
		return Select(arr,left,pivot-1,k, NumComp);
	}
	else {
		return Select(arr, pivot + 1, right, k - leftPart, NumComp);
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
		if (arr[i].GetId() < arr[pivot].GetId()) {
			SwapClass(arr[i], arr[index]);
			(*NumComp)++;
			index++;
		}
	}
	SwapClass(arr[pivot], arr[index]);
	return index;
}
int RandomPivotPartition(Person* arr, int left, int right, int* NumComp) {
	// Random selection of pivot.
	int winning_num, n, temp;
	n = rand();
	winning_num = left + n % (right - left + 1); // Randomizing the pivot value from sub-array.
	SwapClass(arr[right], arr[winning_num]);
	return Partition(arr, left, right,NumComp);
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

//Heap Selection ---------------------------------------------------------------------------------------------

Person selectHeap(Person* arr,int n, int k, int* NumComp) {
	Heap kLowest(arr,n);
	Person kPerson;
	kPerson =kLowest.SelectionHeap(k);
	*NumComp = kLowest.GetNumCopm();
	return kPerson;
}

// -----------------------------------------------------------------------------------------------------------

//Binary Tree Selection --------------------------------------------------------------------------------------

Person BST(Person* arr,int n, int k, int* NumComp) {
	BSTree tree;
	for (int i = 0; i < n;i++) {
		tree.Insert(arr[i].GetId(),arr[i]);
	}
	Person klowest;
	klowest = tree.SelectionBST(k);
	*NumComp = tree.GetNumCopm();
	return klowest;
}

// -----------------------------------------------------------------------------------------------------------

void cleanbuffer() { // clean buffer for get function
	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');
}

// -----------------------------------------------------------------------------------------------------------

Person* MakeArrFromFile(char* filename,int* k,int* size) {
	Person* arr;
	ifstream file;
	int temp_id;
	char temp_name[80];
	file.open(filename);
	file >> *size;
	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		file >> temp_id;
		file.seekg(1,ios::cur); // skip space
		file.getline(temp_name, 80);
		arr[i].SetId(temp_id);
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
	char temp_name[128];
	cin >> *size;

	arr = new Person[*size];
	for (int i = 0; i < *size; i++) {
		cin >> temp_id;
		cin.ignore(1, ' ');
		cin.getline(temp_name, 80);
		arr[i].SetId(temp_id);
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
			if (arr[i].GetId() == arr[j].GetId()) {
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

int BSTPrint(Person* arr, int n, int k) {
	BSTree tree;
	for (int i = 0; i < n; i++) {
		tree.Insert(arr[i].GetId(), arr[i]);
	}
	tree.printLowerThanK(k);
	return tree.GetNumCopm();
}

// -----------------------------------------------------------------------------------------------------------