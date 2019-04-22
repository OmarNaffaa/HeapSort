#include "stdafx.h"
#include "Heap.h"
#include <iostream>

Heap::Heap(int CAPACITY)
{
	elements = 0;
	CAP = CAPACITY;
	mHeap = new int[CAPACITY];
}

bool Heap::Empty()
{
	return (elements == 0);
}

bool Heap::Full()
{
	return (elements == CAP);
}

void Heap::InsertItem(int item)
{
	// Check if the heap is full
	if (Full())
	{
		std::cout << "The Heap is full...";
		return;
	}
	else
	{
		// ** Using Perlocate Up Algorithm ** //
		elements++;
		mHeap[elements] = item;

		int loc, parent;
		loc = elements;
		parent = loc / 2;

		while (parent > 0 && mHeap[loc] > mHeap[parent])
		{
			// Swap mHeap[loc] and mHeap[parent]
			int temp = mHeap[loc];
			mHeap[loc] = mHeap[parent];
			mHeap[parent] = temp;

			// set loc = parent and parent = (loc - 1) / 2
			loc = parent;
			parent = (loc - 1) / 2;
		}
	}
}

int Heap::RetrieveMaxItem()
{
	return mHeap[1];
}

void Heap::DeleteMaxItem()
{
	// replace the root with the rightmost leaf;
	// creates a semi-heap
	mHeap[1] = mHeap[elements];
	elements--;

	// ** Perlocate Down Algorithm ** //
	int r = 1;               
	int leftChild = 2 * r;

	while (r <= CAP)
	{
		// If r has 2 children and the right child is larger, make the leftChild the rightChild
		if (leftChild < CAP && mHeap[leftChild] < mHeap[leftChild + 1])
		{
			leftChild++;
		}

		// Swap node and largest child if necessary, and move down to the next subtree
		if (mHeap[r] < mHeap[leftChild])
		{
			// Swap mHeap[r] and mHeap[leftChild]
			int temp = mHeap[r];
			mHeap[r] = mHeap[leftChild];
			mHeap[leftChild] = temp;
		}

		r = leftChild;
		leftChild = 2 * leftChild;
	}
}

void Heap::PrintHeap()
{
	std::cout << "  Heap:\n    ";
	for (int i = 1; i < elements + 1; i++)
		std::cout << "  " << mHeap[i];
}

int Heap::Size()
{
	return CAP;
}

void Heap::HeapSort()
{
	int tmp, r, leftChild;

	for (int i = elements; i > 1; i--)
	{
		// root leaf interchange
		tmp = mHeap[1];
		mHeap[1] = mHeap[i];
		mHeap[i] = tmp;

		// prune the leaf and perlocate down

		// ** Perlocate Down Algorithm ** //
		r = 1;
		leftChild = 2 * r;

		while (r < i / 2)
		{
			// If r has 2 children and the right child is larger, make the leftChild the rightChild
			if (leftChild < i && mHeap[leftChild] < mHeap[leftChild + 1])
			{
				leftChild++;
			}

			// Swap node and largest child if necessary, and move down to the next subtree
			if (mHeap[r] < mHeap[leftChild])
			{
				// Swap mHeap[r] and mHeap[leftChild]
				int temp = mHeap[r];
				mHeap[r] = mHeap[leftChild];
				mHeap[leftChild] = temp;
			}

			r = leftChild;
			leftChild = 2 * leftChild;
		}
	}

	// final swap - 2 values left
	if (mHeap[1] > mHeap[2])
	{
		// swap without using a temporary variable
		mHeap[1] = mHeap[1] * mHeap[2];
		mHeap[2] = mHeap[1] / mHeap[2];
		mHeap[1] = mHeap[1] / mHeap[2];
	}
}

Heap::~Heap()
{
	delete[] mHeap;
}