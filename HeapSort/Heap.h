#pragma once
class Heap
{
public:
	int elements, CAP;
	int* mHeap;

	Heap(int CAPACITY);
	bool Empty();
	bool Full();
	void InsertItem(int item);
	int RetrieveMaxItem();
	void DeleteMaxItem();
	void PrintHeap();
	int Size();

	// Heapsort Method
	void HeapSort();

	~Heap();
};

