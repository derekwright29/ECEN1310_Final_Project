#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "crypto.h"

int vigenere(void)
{
  char msg[101] = "";
  char key[101] = "";
  char test[101];
  char cat[31] = "";
  char output[101] = "";
 
  printf("\nNow we move onto the Vigenere Cipher\nIt is just multiple caesar ciphers with varying shifts depending on a key string\nEnter your key string now!\n\n");

  scanLoopStrLettersOnly(key, cat);

  //Prompt and scan with spaces, cat into no space string.
  printf("\nKey string: %s\n\nAwesome. Now you can enter the message you want to encode:\n\n", key);

  scanLoopStr(msg, cat);

  printf("\nExcellent. Let's encode it!\n\n");

  encodeVig(msg, output, key);
  
  printf("\nYour encrypted message is:\n%s\n\n", output);
  printf("\nTo decode your message, please input your key:\n");

  while(!scanLoopKeyMatchStr(key, test, cat));

  decodeVig(output, msg, key);

  printf("\nHere's your decoded message:\n%s\n\n", msg);
  
  return 0;
}


