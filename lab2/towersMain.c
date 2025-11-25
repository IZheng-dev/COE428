/*
 * Name: Isaac Zheng
 * Student ID: 501263130
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Edited towersMain file to fix bugs specified in requirement 2
 */

#include <stdlib.h>
#include "towers.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    
    //Initializing the variables
    int n;
    int from;
    int dest;
    
    //If no arguments (== 1 to account for file name)
    if (argc == 1) {
		n = 3;
		from = 1;
		dest = 2;
	}
    
    //Else provided arguments
    else {
		
		//Verify invalid disks
		n = atoi(argv[1]);
		if (n < 1){
			fprintf(stderr, "Error, Disks Must be an Integer > 0!\n");
			exit(1); //Exit with error
		}
    
		//If provided 1 argument
		if (argc == 2) {
			from = 1;
			dest = 2;
		}
		
		//Else if provided 3 arguments
		else if (argc == 4){
			from = atoi(argv[2]);
			dest = atoi(argv[3]);
			
			//Verify arguments
			//Check if from or dest is 1, 2, or 3
			if (from < 1 || from > 3 || dest < 1 || dest > 3){
				fprintf(stderr, "Error, The Tower ID's Must be Either 1, 2, or 3!\n");
				exit(1);
			}
			
			//Check if from and dest share same ID
			if (from == dest){
				fprintf(stderr, "Error, The Tower IDs Must be Different!\n");
				exit(1);
			}
			
		}
		
		//Else provided invalid arguments
		else {
			fprintf(stderr, "Error, Invalid Input!\n");
			exit(1);
		}
		
	}
	
    towers(n, from, dest);
    exit(0); //Exit program with no errors
    
}
