// CSE 220 Spring 2019
// Project 4

// Enter your name here
// Mention which environment you used: VS or gcc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "proj4.txt"
#define WORD_LENGTH 20

#pragma warning(disable: 4996)	// needed for VS

FILE *fp;		// Use this file pointer to open the file in readFile() and use this pointer through out this file.

/*
Problem 1: (10 points)
Open the file proj4.txt. Use proper parameters to open the file for reading as well as writing.
After opening the file, you will use the 'fp' pointer in other functions.
Display the size of the file.
Note: If using VS and default project location then place proj4.txt here- "C:\Users\<user>\Documents\Visual Studio 2017\Projects\Project1\Project1"
*/
void readFile()
{
	int fileSize = 0;
	fp = fopen("proj4.txt", "r");
	if (fp == NULL) {
		printf("ERROR: Could not load file!\n");
	}
	else {
		fseek(fp, 0, SEEK_END); //put pointer to end of file
		fileSize = ftell(fp);
		rewind(fp);
	}

	printf("The file size = %d bytes\n", fileSize);
}

/*
Problem 2: (8 points)
Using file operations, calculate and display the number of words in the .txt file.
You are NOT allowed to use string library functions.
*/
void wordCount()
{
	int words = 0;
	// enter code here

	printf("Total words = %d \n", words);
}

/*
Problem 3: (7 points)
Using file operations, calculate and display the number of sentences in the .txt file.
You are NOT allowed to use string library functions.
*/
void sentenceCount()
{
	int sentences = 0;
	// enter code here

	printf("Total sentences = %d \n", sentences);
}

/*
Problem 4: (15 points)
In findAndReplace(), ask the user for a word (find[]) to replace and the new word (replace[]) that will be inserted in its place.
For simplicity, you may assume that both these words will be of same length and replace the first occurance of the 'find' word.
If the word is found and replaced, then print "Found and replaced", lese print "Word not found"
For example, user might enter find[]= "with" and replace[]= "into". So all instances of the word "with" should be replaced by "into".
You are allowed to use only these string functions here, if necessary: strlen(), strcmp(), strcat().
*/
void findAndReplace()
{
	char find[WORD_LENGTH], replace[WORD_LENGTH];
	// enter code here

}

int main()
{
	printf("CSE 220 p04q3: \n");
	printf("\nProblem 1: \n");
	readFile();
	
	printf("\nProblem 2: \n");
	wordCount();

	printf("\nProblem 3: \n");
	sentenceCount();
	
	printf("\nProblem 4: \n");
	findAndReplace();

	fclose(fp);
	system("pause");	// needed for VS
	return 0;
}