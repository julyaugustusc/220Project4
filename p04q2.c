// CSE 220 Spring 2019
// Project 4

// Augustus Crosby
// Mention which environment you used: VS 

#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "myBMP.bmp"

#pragma warning(disable: 4996)	// needed for VS only

// functions that need implementation
void loadFile(const char *filename);
void displayBmpFile();
void changePixelToWhite();
void saveNewFile(const char *);

// gloabl variables
unsigned char *fp = 0;			//pointer to navigate through the opened file.
unsigned char *fileStart = 0;	// pointer to save the start address of the file, in case you need to go back to start of file
unsigned char fileSize = 0;		// stores the size of file

/*
Problem 1: loadFile (10 points)
Implement loadfile() to open the myBMP.bmp file. By default, file name is myBMP.bmp
Use dynamic memory allocation to store the entire contents of the file and let that memory be pointed by 'fp'.
Save the start of file in 'fileStart' so that you use it to go to start of file in other functions.
Print the size of the file by reading the appropriate byte from BITMAPFILEHEADER.
Hint: After opening the file, read the file size and use it for dynamic memory allocation to read entire file.
Note: If using VS, the bmp file should be placed in "C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1" if using default project location.
*/
void loadFile(const char *filename)
{
	FILE *fileBuffer; //declaring pointer to filetype
	fileBuffer = fopen(filename, "rb"); //rb for read and binary
	if (fileBuffer == NULL) {
		printf("ERROR: Could not load file!\n"); //error message
	}
	else {
		fseek(fileBuffer, 0, SEEK_END); //put pointer to end of file
		fileSize = ftell(fileBuffer);	//read location of pointer as size of file
		rewind(fileBuffer);				//put pointer back to beginning
		fp = (char*)malloc(fileSize);	//dynamic memory allocation

		printf("File loaded. File size = %#x bytes\n", fileSize);
		fread(fp, fileSize, 1, fileBuffer); //read from filebuffer
		fileStart = fp;			// set starting pointer
		fclose(fileBuffer);		// close
	}

}

/*
Problem 2: displayBmpFile (10 points)
Display myBMP.bmp file in hex.
Display neatly the content of myBMP.bmp file as seen in hex editor, as per expected output given in project question file.
Even after closing the file with fclose(), we have the contents of the file in memory pointed by 'fp' (or 'fileStart' in loadFile()).
So you don't have to open and read the file again.
*/
void displayBmpFile()
{
	printf("Hex view of loaded bmp file:\n");
	for (int k = 0; k < 16; k++) {
		printf("%-7x", k);			// displaying hex 1-16
	}
	printf("\n");
	for (int l = 0; l < 16; l++) {
		printf("-------");			// displaying 7 dashes for the 7 spacing set
	}
	printf("\n");
	for (int i = 0; i < fileSize; i++) {
		printf("%-7.02x", fp[i]);	// 7 spaces, 2 decimals for hex values
		if ((i+1) % 16 == 0) {
			printf("\n");			// after 16 numbers, next column
		}
	}
	printf("\n");
	
}

/*
Problem 3: (15 points)
Ask the user for a pixel location and store the location in 'row' & 'col'. Change that pixel to white color.
Valid pixel locations are 0  to 4. Check for valid location and keep asking the user until valid location is entered.
White color is RGB= (255, 255, 255).
For instance, if user enters row=2, column=0 then change the pixel (2,0) to white color.
*/
void changePixelToWhite()
{
	unsigned int row = 0, col = 0;
	// enter code here
	do {
		printf("Enter row of pixel: ");
		scanf("%d", &row);  //scan value into the row value
	} while (row != 0 && row != 1 && row != 2 && row != 3 && row != 4); // if not any of these choices will reject
	do {
		printf("Enter column of pixel: ");
		scanf("%d", &col); //scan value into the col value
	} while (col != 0 && col != 1 && col != 2 && col != 3 && col != 4);  // if not any of these choices will reject

	unsigned int temp = 4 - row, temp2 = 0; //temp flips because the number 0 starts from bottom instead of top and it's labeled the opposite way
	temp2 = temp2 + 54;			// temp2 is placement of how far pointer needs to be, 14 and 40 for the BITMAP
	temp2 = temp2 + temp * 16; 
	temp2 = temp2 + col * 3;	// add appropriate values to get to the pointer
	fp[temp2] = 255;			// set the next 3 values to equal 255.
	fp[temp2 + 1] = 255;
	fp[temp2 + 2] = 255;

	printf("Changed pixel (%d, %d) to white \n", row, col);
}

/*
Problem 4: saveNewFile (10 points)
Open a new file and write that file with the modified .bmp image with the white pixel.
You should have the file content pointed by 'fileStart'.
File name is provided as parameter when calling in main()
Note: If using VS, the bmp file will be saved in "C:\Users\<username>\Documents\Visual Studio 2017\Projects\Project1\Project1" if using default project location.
*/
void saveNewFile(const char *fileName)
{
	FILE *fileBuffer; //declaring pointer to filetype
	fileBuffer = fopen(fileName, "wb"); //write and binary instead this time
	if (fileBuffer == NULL) {
		printf("ERROR: Could not load file!\n"); // error message
	}
	else {

		fwrite(fileStart, fileSize, 1, fileBuffer); // save the program
		fclose(fileBuffer);
	}

	printf("File %s saved.\n", fileName);
}

int main()
{
	printf("CSE 220 p04q2: \n");
	printf("Problem 1: \n");
	loadFile(FILE_PATH);

	printf("Problem 2: \n");
	displayBmpFile();

	printf("Problem 3: \n");
	changePixelToWhite();

	printf("Problem 4: \n");
	saveNewFile("myBMP2.bmp");

	system("pause");		// needed for VS only
	return 0;
}