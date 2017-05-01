#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "crypto.h"

//run stream GUI
void stream(void)
{
  char msg[101], output[101], stream[101], printStr[201] = "", cat[51], ascii[3];
  
  printf("\nWe are now doing a stream cipher, a much more useful cipher.\nThis cipher genereates a random (pseudo-random, so for real purposes there are more complex random number generators) stream of bits we use as our key\nPlease input your message now:\n");
  
  scanLoopStr(msg, cat);
  printf("%s\n", msg);

  fillByteArray(stream, strlen(msg) + 1);

  printf("\nWe will now encrypt using modulo 2 addition (XOR gate)\n");
  XOR_msgStream(msg, stream, output);

  //convert to printable chars
  convertOutput(output, printStr, ascii);
  
  printf("%s\n", msg);
  printf("\nAfter bitwise encryption, we have:\n\n%s\n\n", printStr);

  XOR_msgStream(output, stream, msg);
  
  printf("The beauty of the stream cipher is that we do the exact same modulo 2 addition to get our original string back\nHere it should be:\n%s\n", msg);


  clearStr(msg); clearStr(output);
}
