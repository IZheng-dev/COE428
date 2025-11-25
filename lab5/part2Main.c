/*
 * Name: Isaac Zheng
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Acts as main function to read stdin and implements the heap tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Declare the functions in the intStack file
extern int pop();
extern void push(int);
extern int isEmpty(void);

//Declare the functions from the intHeap file
extern void addHeap(int thing2add);
extern int heapDelete(void);
extern int heapSize(void);
extern int getHeap(int index); //Access heap to print XML

//Method to print the heap recursively
static void printHeapNode(int index, int size){
	
	if (index >= size)
		return;
		
	int id = getHeap(index);
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	
	printf("<node id=\"%d\">", id);
	
	if (left < size)
		printHeapNode(left, size);
	
	if (right < size)
		printHeapNode(right, size);
		
	printf("</node>");
	
}

int main(int argc, char * argv[])
{
  int value;
  
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    addHeap(value);
  }
  
  int size = heapSize();
  
  if (size > 0){
	  printHeapNode(0, size);
	  printf("\n");
  }
  
  while (heapSize() > 0){
	  int removed = heapDelete();
	  printf("%d\n", removed);
	  push(removed);
  }
  
  while (!isEmpty()){
	  int popValue = pop();
	  printf("%d\n", popValue);
  }
  
  exit(0);
  
}

