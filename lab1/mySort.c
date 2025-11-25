/*
 * Name: Isaac Zheng
 * Student ID: 501263130
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: mySort code using insertion sort
*/

void mySort(int d[], unsigned int n)
{
	
	//Insertion sort
	for (int i = 1; i < n; i++){
        int key = d[i];    //Copy current key element to insert into array
        int j = i - 1;  //Compare index of previous element

        while (j >= 0 && d[j] > key){
            d[j+1] = d[j];  //Moves the element one index ahead
            j = j - 1;  //Shift back to previous element to continue comparing the left
        }
        d[j+1] = key;  //Places the value in its correct sorted position
    }
	
}
