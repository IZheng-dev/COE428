/*
 * Name: Isaac Zheng
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Implements the functions addHeap, heapDelete, heapSize and getHeap
 */
 
#include <stdio.h>
 
//Define the variables
static int count = 0;
static int heap[100];
 
//Swap function to make swapping easier and neat
static void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
	if (count == 0){
		fprintf(stderr, "Error! Unable to delete an empty heap\n");
		return -1;
	}
	
	int max = heap[0];
	
	heap[0] = heap[count - 1];
	count--;
	
	//Initialize the index at 0
	int i = 0;
	
	while (1){
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largestInt = i;
		
		if (left < count && heap[left] > heap[largestInt])
			largestInt = left;
			
		if (right < count && heap[right] > heap[largestInt])
			largestInt = right;
			
		if (largestInt == i)
			break;
			
		swap(&heap[i], &heap[largestInt]);
		i = largestInt;
	}
	return max;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	if (count >= 100){
		fprintf(stderr, "Error! Cannot add heap on a full heap\n");
		return;
	}
	
	int index = count++;
	heap[index] = thing2add;
	
	while (index > 0){
		int parentNode = (index - 1) / 2;
		if (heap[parentNode] >= heap[index])
			break;
		swap(&heap[parentNode], &heap[index]);
		index = parentNode;
	}
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return count;
}

int getHeap(int index){
	if (index >= count || index < 0){
		fprintf(stderr, "Error! Cannot get heap, index out of range\n");
		return -1;
	}
	return heap[index];
}

