#include <stdio.h>

#include "crypto.h"

int main()
{

  int err = 0;
  int cnt = 0;
  

  printf("\nHello! Welcome to Derek's crypto program, where we will walk through many different ciphers.\nTo start, enter the number corresponding to the cipher you want to use\n\n\tCaesar: 1\n\tVigenere: 2\n\tAffine: 3\n\tStream: 4\n\tEnd Program: 5\n\n");

  scanf("%d", &err);
  while(err != 5)
    {
      while (err == 1)
	{
	  caesar();
	  printf("\nEnter 1 to try caesar cipher again, 2 to move to vigenere, 3 to move to affine, 4 to move to stream, 0 to main menu:\n");
	  scanf("%d", &err);
	  continue;
	}
      
      while(err == 2)
	{
	  vigenere();
	  printf("\nEnter 1, 2, 3 or 4 to try ciphers again, 0 to main menu, 5 to quit:\n");
	  scanf("%d", &err);
	  continue;
	}
      
      while(err == 3)
	{
	  affine();
	  printf("\nEnter 1, 2, 3 or 4 to try ciphers again, 0 to main menu, 5 to quit:\n");
	  scanf("%d", &err);
	  continue;
	}
      
      while (err == 4)
	{
	  if (cnt == 0)
	    printf("\n\nThis is your first use of the stream cipher! This means the first message you try to encrypt will be tainted with non-letter chars in stdin.\nRun the cipher once first to clear these, and then try again and again!\n\n");
	  stream();
	  printf("\nEnter 1, 2, 3 or 4 to try ciphers again, 0 to main menu, 5 to quit:\n");
	  scanf("%d", &err);
	  cnt++;
	  continue;
	}
      
      if (err == 5)
	printf("\n\nWell done! We made it through. Bye now.\n\n");
      else
	continue;
      
    }
  return 0;
  
}
