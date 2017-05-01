#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "crypto.h"

int caesar()
{
  // int err;
  int shift = 0, test = 0, shif;
  char msg[101] = "";
  
  //to allow for spaces in input
  char interMsg[51] = "";
  
  char output[101] = "";

      printf("The first cipher is a Caesar cipher!\nTo start please enter your shift number (1-25) below:\n");
  
      shift = scanLoopInt();
      //in case the user inputs not in 0-25, I still let the cipher go on.
      shif = shift % 26;
            
  printf("Great! Now enter your message (100 character max) you want to encode. Spaces or other whitespace characters will not be encoded:\n\n");

  scanLoopStr(msg, interMsg);
  printf("Your message is: %s\n", msg);

  encodeCaesar(msg, output, shif);

  printf("Your encoded message is:\n%s\n\nNow input the key to decode your message:\n", output);

  while(scanLoopKeyMatchInt(shift, test) == 0);
  decodeCaesar(output, msg, shif); 
  printf("Decoded your message becomes:\n%s\n\n", msg);
  
  return 0;
}
