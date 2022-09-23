#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int bufferOverflow(const char * str)
{
   char buffer[12];
   /* This line has a buffer overflow vulnerability. */
   
   //char* firstAddressPointer = buffer;
   //printf("first address pointer: %p\n", firstAddressPointer);
   strcpy(buffer, str);
   return 1;
}

int main(int argc, char ** argv)
{
	   char aString[512];
	   FILE *badfile;

	   printf("Buffer overflow vulnerability starting up...\n");
	   badfile = fopen("badfile", "r");
	   fread(aString, sizeof(char), 512, badfile);

	   bufferOverflow(aString);

	   printf("bufferOverflow() function returned\n");

	   return 1;

}
