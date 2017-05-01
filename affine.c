#include <stdio.h>
#include <assert.h>

#include "crypto.h"

int affine()

{
  int ret, shif1 = 0, shift2 = 0, test = 0;
  char msg[101] = "";
  char output[101] = "";
  char interMsg[51] = "";
    
  printf("\nNow let's move onto the affine cipher\nThis one requires two integer keys to produce a shift for your message\n\nFirst, enter your first integer key between 1-25\n");

  shif1 = scanLoopInt();

  printf("\n\n\nNice, now the second. This one is more mathematically tricky. It has to be relatively prime with 26, which means no factor of 2 (and also no 13)!\n\nThis is because there would be no inverse function (or key) to decrypt the affine cipher and thus it would serve no purpose in sending a message\n\nThe only way to decrypt would be brute force/linguistic analyziation, which any attacker can perform anyways\n\nEnter your second key now!\n");

  shift2 = checkAffineShif2();

  printf("\nPerfect! Now enter your message. These should be all alphabet letters.\n");

  scanLoopStr(msg, interMsg);
  
  encodeAffine(msg, output, shif1, shift2);

  printf("Wonderful! now your encoded message is:\n%s\n\nNow to decode\nEnter your first shift value now:\n", output);

  ret = scanLoopKeyMatchInt(shif1, test); assert(ret == 1);

  printf("\nSame deal, but now with your second key:\n");

  ret = scanLoopKeyMatchInt(shift2, test); assert(ret == 1);

  decodeAffine(output, msg, shif1, shift2);

  printf("\nGreat! Now here is your decoded message:\n%s\n", msg);
  
  return 0;
}

