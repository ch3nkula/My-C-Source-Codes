/*********************************************************************/
/* file: strong_filecopy.c
   author: Alangi Derick
   Description: This is a program that uses complicated functions in the 
                C library to copy the content of one file and transfer it
		to the other.
*/

#include<stdio.h>
#include<errno.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
  char array[BUF_SIZE];
  size_t bytesIn, bytesOut;
  FILE *inFile, *outFile;

  if(argc != 3){
    fprintf(stderr, "Usage: cp file1 file 2\n");
    return 1;
  }

  inFile = fopen(argv[1], "rb");
  if(inFile == NULL){
    perror(argv[1]);
    return 2;
  }

  outFile = fopen(argv[2], "wb");
  if(outFile == NULL){
    perror(argv[2]);
    fclose(inFile);
    return 3;
  }
  
  while((bytesIn = fread(array, 1, BUF_SIZE, inFile)) > 0){
    bytesOut = fwrite(array, 1, bytesIn, outFile);
    if(bytesIn != bytesOut){
      perror("Fatal write error.");
      fclose(inFile);
      fclose(outFile);
      return 4;
    }
  }
    fclose(inFile);
    fclose(outFile);
  return 0;
}//this is the end of the main function.
