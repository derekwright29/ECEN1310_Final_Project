#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "crypto.h"

/**********Caesar Functions (may be used elsewhere as well)*********/
int scanLoopInt(void)
{
  int scan;
  int ret = 0;
  //to flush stdin when bad input
  char c[101] = "";
  char inter[21] = "";

  while (!ret)
    {
      printf("I am expecting an integer.\n");
      scanLoopStr(c, inter);
      //testing
      //printf("string scanned: %s\n", c);
      ret = sscanf(c, "%d", &scan);
      //testing
      //printf("int scanned from string: %d\n", scan);
      clearStr(c);
    }
  return scan;
}

int scanLoopKeyMatchInt(int const key, int scan)
{
  int ret;
  scan = scanLoopInt();
  if (key == scan)
    return 1;
  else
    {
      printf("No match, try again\n");
      ret = scanLoopKeyMatchInt(key, scan);
      if(ret)
	return 1;
    }
  return 0;
}

void encodeCaesar(char * msg, char * output, int shift)
{
  int i;
  for (i = 0; msg[i] != '\0'; i++)
    {
      if(isLower(msg[i]))
	output[i] = 'a' + ((msg[i] - 'a' + shift) % 26);
      else if (isUpper(msg[i]))
	output[i] = 'A' + ((msg[i] - 'A' + shift) % 26);
      else
	{
	  printf("In else statement (shouldn't be)\n");
	  output[i] = msg[i];
	}
      //clearStr in less computational power
      msg[i] = '\0';
    }
  output[i] = '\0';
  
  return;
}

void decodeCaesar(char * msg, char * output, int shift)
{
  //encoding the message with 26 - shift will get us back to the original msg
  encodeCaesar(msg, output, 26 - shift);
}


/*****************Vigenere Functions (May be used Elsewhere**************/


void scanLoopStr(char * str, char * interStr)
{
  while(scanf("%50s", interStr) != EOF)
    {
      strcat(str, interStr);
    }
}

void scanLoopStrLettersOnly(char * str, char * interStr)
{
  int ret = 1;
   while(ret)
     {
       ret = 1;
       scanLoopStr(str, interStr);
       
       for (int j = 0; str[j] != '\0'; j++)
	 {
	   if (!isUpper(str[j]) && !isLower(str[j]))
	     {
	       printf("\nPlease only characters. Let's try this again\n\n");
	       ret++;
	       clearStr(str);
	     }
	   
	 }
       if (ret == 1)
	 ret = 0;
       
     }
   clearStr(interStr);
  
}


int scanLoopKeyMatchStr(char const * key, char * in, char * interStr)
{
  clearStr(in);
  clearStr(interStr);
  scanLoopStr(in, interStr);
  printf("Scanned string is : %s\n", in);

  if(strcmp(key, in) == 0)
    return 1;
  else
    {
      printf("Wrong key. Try again\n");
      return 0;
    }
}


void clearStr(char * in)
{
  for (int i = 0; i < (int) strlen(in); i++)
    {
      in[i] = '\0';
    }
}


void invertVigKey(char * key)
{
  for (int i = 0; key[i] != '\0'; i++)
    {
      if(isLower(key[i]))
	key[i] = (((26 - (key[i] - 'a')) % 26) + 'a');
      else if(isUpper(key[i]))
	key[i] = (((26 - (key[i] - 'A')) % 26) + 'A');
    }
}

char caesarForChar(char in, int shift)
{
  if (isUpper(in))
    return 'A' + ((in - 'A' + shift) % 26);
  else if (isLower(in))
    return 'a' + ((in - 'a' + shift) % 26);
  else
    return '\0';
}

int isUpper(char c)
{
  if (c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

int isLower(char c)
{
  if (c >= 'a' && c<= 'z')
    return 1;
  else
    return 0;
}

void encodeVig(char * msg, char * output, char * key)
{
  int shift;
  for(int i = 0; msg[i] != '\0'; i++)
    {
      int keylen = strlen(key);
      char out[2];
      if (isLower(key[i % keylen]))
	shift = (key[i % keylen] - 'a') % 26;
      
      else if (isUpper(key[i%keylen]))
	shift = (key[i%keylen] - 'A') % 26;
      //testing
      //printf("Encrypting char %c, with shift value %d\n", msg[i], shift);
      out[0] = caesarForChar(msg[i], shift);
      out[1] = '\0';
      strcat(output, out);
      //testing
      //printf("Output: %s\n", output);
      
    }
  clearStr(msg);
}

void decodeVig(char *  msg, char * output, char * key)
{
  //testing
  //printf("key is: %s\n", key);
  invertVigKey(key);
  //testing
  //printf("Inverted key is: %s\n", key);
  encodeVig(msg, output, key);
}

/**********Affine Functions (May be used elsewhere**********/


int findAffineInverse(int shift2)
{
  int i;
  for (i = 1; i < 26; i++)
    {
      if (((shift2 * i) % 26) == 1)
	return i;
    }
  return 0;
}

void encodeAffine(char * msg, char * out, int shif1, int shift2)
{
  for (int i = 0; msg[i] != '\0'; i++)
    {
      if (isLower(msg[i]))
	{
	  out[i] = ((((msg[i] - 'a') * shift2 + shif1) % 26) + 'a');
	}
      else
	{
	  out[i] = ((((msg[i] -'A')* shift2 + shif1) % 26) + 'A');
	}
    }
  clearStr(msg);
  return;
}

void decodeAffine(char * msg, char * out, int shif1, int shift2)
{
  char trash[101] = "";
  int shift2_inv = findAffineInverse(shift2); assert(shift2_inv != 0);
  encodeCaesar(msg, trash, 26 - shif1);
  encodeAffine(trash, out, 0, shift2_inv);
}

int checkAffineShif2()
{
  int ret = 1, shift2 = 0;
  int invalid[] = {0,2,4,6,8,10,12,13,14,16,18,20,22,24,26};
  while(ret)
    {
      ret = 1;
      shift2 = scanLoopInt();
      for (size_t i = 0; i < sizeof(invalid)/sizeof(invalid[0]); i++)
	{
	  if (shift2 == invalid[i])
	    {
	      printf("Invalid shift key, try again\n");
	      ret++;
	    }
	}
      if(ret == 1)
	break;
    }
  return shift2;
}

/**************Stream Functions (may be used elsewhere)*******************/

//Only to allow for the printing of the encryption string in intelligible chars
void convert(char c, char * ascii)
{
  char bank[] = "0123456789ABCDEF";
  ascii[0] = bank[((c >> 4) & 15)]; //make a 0-15 num of most significant 4 bits
  ascii[1] = bank[(c & 15)];//0-15 of least significant four bits
  ascii[2] = '\0';
}

//produce hex string out of unintelligible chars
void convertOutput(char * output, char * convertStr, char * ascii)
{
  //convvert output string
  for (int i = 0; output[i] != '\0'; i++)
    {
      convert(output[i], ascii);
      strcat(convertStr, ascii);
    }
}

//uses rand to get a one-byte number
char randGet()
{
  return rand() % 256;
}

//Fills stream array with 1 byte numbers cast to chars
void fillByteArray(char * stream, int size)
{
  for (int i = 0; i < size; i++)
    {
      stream[i] = (char) randGet();
    }
  stream[size] = '\0';
}

//XOR loop operation to encrypt
void XOR_msgStream(char * msg, char * stream, char * output)
{
  int i;
  if (strlen(msg) > strlen(stream))
    {
      printf("\nStream not big enough. Need %d, only have %d\n", (int) strlen(msg), (int) strlen(stream));
      return;
    }
  for (i = 0; msg[i] != '\0'; i++)
    {
      output[i] = (msg[i] ^ stream[i]);
      //clearStr
      msg[i] = '\0';
    }
  output[i] = '\0';
}

/*********************************************************/
