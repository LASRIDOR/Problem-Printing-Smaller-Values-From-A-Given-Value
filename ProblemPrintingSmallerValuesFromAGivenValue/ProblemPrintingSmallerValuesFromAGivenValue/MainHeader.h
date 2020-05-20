#ifndef _MainHeader_H
#define _MainHeader_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include "Person.h"
#include "BSTree.h"
#include "List.h"
using namespace std;


void cleanbuffer();

// for reading from buffer
Person* MakeArrofPersons(int* k, int* size);

// for reading from file
Person* MakeArrFromFile(string filename,int* k,int* size);

void CopyPersons(Person* destination,Person* source,int size);
void CheckValidInput(Person* arr,int size);

// QuickSort
// Time Complexity:
// Runtime Complications: Average :Θ(nlogn)
// Worst :Θ(n^2)
// as we learned in class
// + Θ(number of persons that their key value is lower than k)


// pay attention that the array of person is changing directly
int PrintBySort(Person* arr, int n, int k);
void QuickSort(Person* arr, int left, int right, int* NumComp);
int Partition(Person* arr, int left, int right, int* NumComp);
//int Partition(Person* arr, int left, int right, int* NumComp);

void SwapClass(Person& p1,Person& p2);
void SwapClass1(Person& p1, Person& p2);

// Binary search Tree
// Time Complexity:
// Runtime Complications: Average: Θ(nlogn) for n time insert Θ(logn)(height of the tree) key to the tree
// worst case: Θ(n^2) for making chain tree
// + Θ(n) for printing k values (inorder print goes thru all the tree)

int BSTPrint(Person* arr, int n, int k);

// Naive alghorithm
// Algorithm that passes the organ limb array, and copies all data with a key less than K,
// to a concatenated list as revenue is sorted and prints the list thereafter
// Time Complexity:
// Avaerage: Θ(n^2) for insert to sorting list (list is sorted all the time)
// worst: Θ(n^2) for insert to sorting list (list is sorted all the time)
// + Θ(number of persons that their key value is lower than k)

int NaivePrint(Person* arr, int n, int k);

#endif // !_MainHeader_H