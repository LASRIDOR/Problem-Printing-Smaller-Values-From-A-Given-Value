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
Person* MakeArrFromFile(char* filename,int* k,int* size);

void CopyPersons(Person* destination,Person* source,int size);
void CheckValidInput(Person* arr,int size);

// Rand Selection
// Runtime Complications: Θ(n)

Person RandSelection(Person* arr, int n, int k, int* NumComp);
Person Select(Person* arr, int left, int right, int k, int* NumComp);
int RandomPivotPartition(Person* arr, int left, int right, int* NumComp);
int Partition(Person* arr, int left, int right, int* NumComp);

//int Partition(Person* arr, int left, int right, int* NumComp);

void SwapClass(Person& p1,Person& p2);
void SwapClass1(Person& p1, Person& p2);

// Binary search Tree
// Runtime Complications: Θ(nlogn) for n time insert Θ(logn)(height of the tree) key to the tree + Θ(k) for printing k values

int BSTPrint(Person* arr, int n, int k);

// Naive alghorithm
// Algorithm that passes the organ limb array, and copies all data with a key less than K,
// to a concatenated list as revenue is sorted and prints the list thereafter

int NaivePrint(Person* arr, int n, int k);

#endif // !_MainHeader_H