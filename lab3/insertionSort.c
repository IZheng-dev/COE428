/*
 * Name: Isaac Zheng
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Insertion sort code
 */

#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
		
	//Declaring variables
	int i, j, key;

	for (i = first + 1; i <= last; i++){
		key = array[i]; //Key is a temporary copy of the current array element
		j = i - 1; 
		
		while (myCompare(array[j], key) > 0 && j >= first){
			myCopy(&array[j], &array[j+1]); //Moves element one index ahead using the copy function
			j = j - 1; //Move back to previous element to continue to compare with left value
		}
			
		myCopy(&key, &array[j+1]);  //Inserts the value in right position
	}
		
}
