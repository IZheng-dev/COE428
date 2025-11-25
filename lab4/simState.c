/*
 * Name: Isaac Zheng
 * Student ID: 501263130
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: State machine code that responds to commands
 * State Machine:
 * A A C
 * B E A
 * C F D
 * D B E
 * E G F
 * F D H
 * G H B
 * H A G
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 6
#define NUM_STATES 8 //There are 8 states from A-H

//Define the structure of the state machine (to group related data)
typedef struct {
	char stateName;
	char nextState0;
	char nextState1;
	int isDeleted; //0 = false 1 = true (acts as boolean)
} State;

//Intialize the state machine as an array
//Format: {stateName, nextState0, nextState1, isDeleted}
State stateMachine[NUM_STATES] = {
	{'A', 'A', 'C', 0},
	{'B', 'E', 'A', 0},
	{'C', 'F', 'D', 0},
	{'D', 'B', 'E', 0},
	{'E', 'G', 'F', 0},
	{'F', 'D', 'H', 0},
	{'G', 'H', 'B', 0},
	{'H', 'A', 'G', 0}
};

//Initialize the current state (given)
char currentState = 'B';

//Get index method
int getIndex(char state){
	for (int i = 0; i < NUM_STATES; i++){
		if (stateMachine[i].stateName == state){
			return i;
		}
	}
	return -1; //Returns -1 if cannot get index
}

//Processes 0 or 1 Command
void nextState(int input) {
	int index = getIndex(currentState);
	if (index != -1){
		if (input == 0){
			currentState = stateMachine[index].nextState0;
		}
		else if (input == 1){
			currentState = stateMachine[index].nextState1;
		}
	}
}

//Processes the Change Command
void changeState(int input, char newState) {
	if (getIndex(currentState) != -1 && getIndex(newState) != -1){
		if (!stateMachine[getIndex(newState)].isDeleted){
			if (input == 0){
				stateMachine[getIndex(currentState)].nextState0 = newState;
			}
			else if (input == 1){
				stateMachine[getIndex(currentState)].nextState1 = newState;
			}
		}
	}
}

//Processes Print command
void printStates(){
	for (int i = 0; i < NUM_STATES; i++){
		if (!stateMachine[i].isDeleted){
			printf("%c %c %c\n", stateMachine[i].stateName, stateMachine[i].nextState0, stateMachine[i].nextState1);
		}
	}
}

//Determines Actual Garbage
void getGarbage(int garbageStates[NUM_STATES]) {
	
	//Initialize array to track reachable states
	int reachableStates[NUM_STATES] = {0};
	
	//Set reachable to act as a boolean, 0 = unreachable 1 = reachable
	//Current state is assumed reachable and will run the first while loop
	int reachable = 1;
	
	//Set the current state as 1 = reachable
	reachableStates[getIndex(currentState)] = 1;

	while (reachable){
		reachable = 0;
		for (int i = 0; i < NUM_STATES; i++){
			if (!stateMachine[i].isDeleted && reachableStates[i]){
				int nextIndex0 = getIndex(stateMachine[i].nextState0);
				int nextIndex1 = getIndex(stateMachine[i].nextState1);
				if (nextIndex0 != -1 && !reachableStates[nextIndex0]){
					reachableStates[nextIndex0] = 1;
					reachable = 1;
				}
				if (nextIndex1 != -1 && !reachableStates[nextIndex1]){
					reachableStates[nextIndex1] = 1;
					reachable = 1;
				}
			}
		}
	}
	
	//Store the garbage states in an array
	for (int i = 0; i < NUM_STATES; i++){
		garbageStates[i] = (!stateMachine[i].isDeleted && !reachableStates[i]);
	}
	
}

//Processes Garbage Identification Command
void identifyGarbage(){
	
	//Initialize the garbage states through the getGarbage method
	int garbageStates[NUM_STATES] = {0};
	getGarbage(garbageStates);

	//Printing the identified garbage
	//First assume state machine to have no garbage
	int hasGarbage = 0; //Acts as boolean where 0 = false and 1 = true
	printf("Garbage: ");
	for (int i = 0; i < NUM_STATES; i++){
		if(garbageStates[i]){ //State is unreachable and not deleted
			printf("%c ", stateMachine[i].stateName);
			hasGarbage = 1; //Sets hasGarbage to true
		}
	}

	if(!hasGarbage){
		printf("No garbage.");
	}

	printf("\n");

}

//Calculates Actual Deletion
void delete(char state){
	
	//Delete Inputted State Name
	if (getIndex(state) != -1){
		if (!stateMachine[getIndex(state)].isDeleted){
			stateMachine[getIndex(state)].isDeleted = 1;
			printf("Deleted.\n");
			return;
		}
		else{
			printf("Not deleted.\n");
			return;
		}
	}

	//Delete all garbage if provided no arguments
	int garbageStates[NUM_STATES] = {0};
	getGarbage(garbageStates);
	
	int deleted = 0; //Act as boolean
	printf("Deleted: ");
	for (int i = 0; i < NUM_STATES; i++){
		if(garbageStates[i]){ //State is unreachable and not deleted
			printf("%c ", stateMachine[i].stateName);
			stateMachine[i].isDeleted = 1;
			deleted = 1; //Sets hasGarbage to true
		}
	}

	if(!deleted){
		printf("No states deleted.");
	}

	printf("\n");

}

//Processes Delete Command
void deleteFunction(char* input){
	
	//If not given a state name
	if (strlen(input) == 1){
		delete(input[0]);
	}
	else if (strlen(input) > 1){
		delete(input[2]); //Skip input[0] and [1] because of command "d" and space
	}
	
}

//Main Method
int main(int argc, char * argv[]) {
	
	char input[MAX_INPUT];

	//Prompt start of program
	printf("Type 's' to stop.\n");
	printf("Current state: \n%c\n", currentState);

	//Commands
	while (1){
		fgets(input, MAX_INPUT, stdin);
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "0") == 0){
			nextState(0);
			printf("Next State: %c\n", currentState);
		}
		else if (strcmp(input, "1") == 0){
			nextState(1);
			printf("Next State: %c\n", currentState);
		}
		else if (input[0] == 'c'){
			int convert = input[2] - '0'; //Convert char to int
			changeState(convert, input[4]);
		}
		else if (input[0] == 'p'){
			printStates();
		}
		else if (input[0] == 'g'){
			identifyGarbage();
		}
		else if (input[0] == 'd'){
			deleteFunction(input);
		}
		if (input[0] == 's'){
			exit(0);
		}
	}
	exit(0);
	
}
