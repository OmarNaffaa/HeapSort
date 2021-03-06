// HeapSort.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Heap.h"

#include <iostream>
using namespace std;

int main()
{
	// Create a heap object with 10 items
	Heap mHeap(10);

	cout << "Is the heap empty: " << boolalpha << mHeap.Empty();

	// Insert elements into the heap
	cout << "\n\nInserting Elements...";
	mHeap.InsertItem(60);
	mHeap.InsertItem(15);
	mHeap.InsertItem(41);
	mHeap.InsertItem(55);
	mHeap.InsertItem(50);
	mHeap.InsertItem(50);
	mHeap.InsertItem(70);
	
	// Print the heap for verification purposes
	cout << "\n\nIs the heap empty: " << boolalpha << mHeap.Empty();
	cout << "\n\nPrinting out the heap for verification:\n";
	mHeap.PrintHeap();

	// Output the max value of the heap
	cout << "\n\nMax value of heap: " << mHeap.RetrieveMaxItem();

	// Remove the max value from the heap
	cout << "\n\nRemoving max value from the heap...";
	mHeap.DeleteMaxItem();
	cout << "\n\nPrinting out the heap for verification:\n";
	mHeap.PrintHeap();

	// Perform HeapSort
	cout << "\n\nPerforming HeapSort...";
	mHeap.HeapSort();
	cout << "\n\nPrinting out the heap for verification:\n";
	mHeap.PrintHeap();

	cout << "\n" << endl;
    return 0;
}