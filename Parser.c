/* This is a program the i use my name to compile C source code files */
/* File name: Parser.c */
/* Author: Alangi Derick */
/* Date: Wed Feb 19, 2014 */
/* Level: Computer Engineering Level 300 */


/* Headers Include */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


/* Macro Definition */
#ifndef COMPILE
#define COMPILE 1	/* This is the flag that controls the entire program */

int 
main(int argc, char **argv)
{
		int STATUS = 0;
		
		/* This array hold the constant string to be used during compilation and linking */
		char ConstantString[] = "gcc -o call ";
		
		/*ConstantString is the concatenated string. ie gcc -o call <filename.c> */
		strcat(ConstantString, argv[1]);
		
		/*system now compiles and links the program at this stage */
		system(ConstantString);
		sleep(0);
		
		//STATUS = execl(PATH, arg0, NULL);
		system("./call"); /* execution of program */
		
		/* Normal termination of program */	
		exit(EXIT_SUCCESS);
}
#endif
