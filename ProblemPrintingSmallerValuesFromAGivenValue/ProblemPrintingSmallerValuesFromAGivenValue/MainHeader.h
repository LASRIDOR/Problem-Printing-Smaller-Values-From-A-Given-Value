#ifndef _MainHeader_H
#define _MainHeader_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include "Person.h"
#include "Heap.h"
#include "BSTree.h"
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

// Heap "selection"
// Runtime Complications: Θ(n) for building heap (Floyd algo) + Θ(k) for k times deletemin() multiply by the Θ(logn) 
// = Θ(nlogn) after calculate

Person selectHeap(Person* arr, int n, int k, int* NumComp);

// Binary Tree "Selection"
// Runtime Complications: Θ(nlogn) for n time insert Θ(logn)(height of the tree) key to the tree  + Θ(logn) for find k with algorithem of selection findk
// = Θ(nlogn)

Person BST(Person* arr, int n, int k, int* NumComp);

#endif // !_MainHeader_H
