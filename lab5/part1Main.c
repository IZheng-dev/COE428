/*
 * Name: Isaac Zheng
 * Student ID: 501263130
 * Professor: Dr. Yasaman Ahmadiadli
 * TA: Majd Alber
 * Description: Acts as main function to read stdin and implements the XML stack validation algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Declare the functions in other file
extern char *pop();
extern void push(char *);
extern int isEmpty(void);

int main(int argc, char * argv[]) {
	
	//Define the variables
	int ch;
	int isValid = 1; //Assume input is valid
	
	while ((ch = getchar()) != EOF) {
		
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
			continue;
			
		if (ch != '<')
			continue; //Only continue if its start of a tag
			
		int input = getchar();
		if (input == EOF){
			isValid = 0;
			break;
		}
		
		int isEnd = 0;
		if (input == '/'){
			isEnd = 1; //It is an end tag, set isEnd to true
		}
		else{
			ungetc(input, stdin); //Unget the char (place it back)
		}
		
		size_t max = 100;
		size_t length = 0;
		char *name = (char *)malloc(max);
		
		if (!name){
			isValid = 0;
			break;
		}
		
		while ((input = getchar()) != EOF){
			
			if (input == '>')
				break;
				
			if (!isalpha((unsigned char)input)){
				isValid = 0;
				free(name);
				name = NULL;
				break; //Check only alphabetic charcaters allowed in input
			}
			
			if (length+1 >= max){
				max *= 2; //Double max capacity if input exceeds it
				char *temp = (char *)realloc(name, max);
				if (!temp){
					isValid = 0;
					free(name);
					name = NULL;
					break;
				}
				name = temp;
			}
			name[length++] = (char)input;
		}
		
		if (!isValid)
			break;
		
		//If input missing eng tag bracket
		if (input != '>'){
			isValid = 0;
			free(name);
			break;
		}
		
		//If tag is empty (no name)
		if (length == 0){
			isValid = 0;
			free(name);
			break;
		}
		name[length] = '\0';
		
		//If it is a start tag, push the identity
		if (!isEnd){
			char *identity = strdup(name);
			free(name);
			if (!identity){
				isValid = 0;
				break;
			}
			push(identity);
		}
		//If it is end tag, must matched previously pushed start tag identity
		else{
			if (isEmpty()){
				isValid = 0;
				free(name);
				break;
			}
			char *topIdentity = pop();
			if (!topIdentity || strcmp(topIdentity, name) != 0){
				if (topIdentity)
					free(topIdentity);
				isValid = 0;
				free(name);
				break;
			}
			free(topIdentity);
			free(name);
		}
	}
	
	//Reached end of file, check if the start and end tags match
	if (isValid && !isEmpty())
		isValid = 0;
		
	printf("%s\n", isValid ? "Valid Tag" : "Invalid Tag");
	
	exit(0);
}
