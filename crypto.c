#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "test.h"

char * encodeCaesar(char const * msg, char * output, int shift)
{
	
	for (int i = 0; msg[i] != '\0'; i++)
	{
		if(msg[i] >= 'a' && msg[i] <= 'z')
			output[i] =	 'a' + ((msg[i] - 'a' + shift) % 26);
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			output[i] = 'A' + ((msg[i] - 'A' + shift) % 26);
		else
			output[i] = msg[i];
	}
	return output;
}


char * decodeCaesar(char * msg, char * output, int shift)
{
	

	for (int i = 0; msg[i] != '\0'; i++)
	{
		if(msg[i] >= 'a' && msg[i] <= 'z')
			output[i] =	 'a' + ((msg[i] - 'a' - shift) % 26);
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			output[i] = 'A' + ((msg[i] - 'A' - shift) % 26);
		else
			output[i] = msg[i];
	}
	return output;

}

int main(void)
{
	char str[] = "Hello!";
	char out[strlen(str)];
	printf("s", encodeCaesar("Hello", out, 1));
	return 0;
}
