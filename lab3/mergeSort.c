/*
 * Name: Isaac Zheng
 * Student ID: 501263130
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Merge sort code
 */

#include "mySort.h"

//Merge function
void myMerge(int array[], unsigned int first, unsigned mid, unsigned int last) {

    //Declare left and right arrays
    int leftArray[mid-first+1], rightArray[last-mid];

    //Split array for left array
    for (int i = 0; i < (mid-first+1); i++)
        myCopy(&array[first+i], &leftArray[i]);

    //Split array for right array
    for (int i = 0; i < (last-mid); i++)
        myCopy(&array[mid+1+i], &rightArray[i]);

    //Merge the left and right array
    int x = 0, y = 0, z = first;

    while (x < (mid-first+1) && y < (last-mid)){
      if (myCompare(leftArray[x], rightArray[y]) <= 0){
            myCopy(&leftArray[x], &array[z]);
            x++;
      }
      else{
            myCopy(&rightArray[y], &array[z]);
            y++;
      }
      z++;
    }

    //Depending on the original array, it is possible that leftArray or rightArray will be empty and other is not
    //Append or copy the final values for the leftArray
    while (x < (mid-first+1)){
        myCopy(&leftArray[x], &array[z]);
        x++;
        z++;
    }

    //Append or copy final values for the rightArray
    while (y < (last-mid)){
        myCopy(&rightArray[y], &array[z]);
        y++;
        z++;
    }
    
}

//Merge sort function
void mySort(int array[], unsigned int first, unsigned int last) {
	
	if (first < last){
       int mid = (first + last) / 2;

       //Divide and Conquer Recursively
       mySort(array, first, mid);
       mySort(array, mid+1, last);

       //Combine array
       myMerge(array, first, mid, last);
    }
    
}
