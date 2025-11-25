Name: Isaac Zheng
Student ID: 501263130
Professor: Dr. Yasaman Ahmadiadli
TA: Majd Alber
Course: COE428 P2025 Lab 1
Submitted: 2025/06/30

~Description of Code:~

The main parts of this lab is that of mySort.c and sortMain2.c. The first part is to write a sorting algorithm for mySort.c, this was completed using the insertion sort method. This is requirement 1 and is completely met and runs smoothly. 

The next requirement is to implement the given code of sortMain, and edit it as sortMain2. If a command line argument was provided, If (argc > 1), then the arguments are converted to integer values and sorted. If no arguments were provided, Else, it will print the default "test data" that was provided in the skeleton code. Requirement 2 is met and runs smoothly with no issues.

Using both codes, it is made into an executable file testSort.o that runs with the command "testSort".

~Questions:~

1. If given an object module must be invoked with the signature, betterSort(int data[], first, last):, the mySort() function could be written to use the better sorting function. This can be done by just calling the function within mySort with the correct paramteres. See code below.

void mySort(int d[], unsigned int n){
	betterSort(int data[], 0, n-1);
}

This works because the first to last index of the portion in the array is to be sorted. That means that the first element would be index 0, first = 0. The variable n = the size of the array (# of elements). Therefore the parameter would have last = n-1, because the the index of an array starts at 0, so the last index would be 1 less than the size of the array.
