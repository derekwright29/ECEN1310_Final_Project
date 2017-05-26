/* This will contain the functions I want to have in all my functions*/

/* Runs the user-interactive caesar cipher code*/
int caesar(void);

//Encodes a string with a given shift and output string to fill
void encodeCaesar(char * msg, char * output, int shift);

//Decodes a msg with a given shift and output string to fill
void decodeCaesar(char * msg, char * output, int shift);

/* Runs the UI for a vigenere cipher
 */
int vigenere(void);

//Tests if char is uppercase, returns 1 if so, returns 0 in all other cases
int isUpper(char c);

//Tests if char is lowercase, returns 1 if true, 0 otherwise
int isLower(char c);

//Implements Caesar Cipher but with the ability to do it with one char
char caesarForChar(char in, int shift);

//fills string in with null chars for re-use or throwing away trash data
void clearStr(char * in);

//scans for correct integer scan, by first clearing stdin with scanLoopStr, and then trying to match an integer to it
int scanLoopInt(void);

//loop until user inputs correct key value. An int in this case
int scanLoopKeyMatchInt(int const key, int scan);

//scans entire stdin to allow for spaces in input
void scanLoopStr(char * str, char * interStr);

//scans input and checks that all non-empty-space input are letters a-z
void scanLoopStrLettersOnly(char * str, char * interStr);

//loop until user inputs correct key string
int scanLoopKeyMatchStr(char const * key, char * in, char * interStr);

//encodes the vigenere cipher with given message, key string, and output destination
void encodeVig(char * msg, char * output, char * key);

//decodes vigenere cipher
void decodeVig(char * msg, char * output, char * key);

//Inverts key string for decoding purposes (26 - letter) = new letter
void invertVigKey(char * key);

//Runs affine UI
int affine(void);

//makes sure shif2 is valid for affine cipher
int checkAffineShif2(void);

//encodes a string using affine method
void encodeAffine(char * msg, char * out, int shif1, int shift2);

//decodes affine cipher by first using caesar to get rid of addition shift and then calling encodeAffine with the inverse of shift2
void decodeAffine(char * msg, char * out, int shif1, int shift2);

//Finds a^-1 for decryption of affine cipher
int findAffineInverse(int shift2);

//runs stream GUI
void stream(void);

//returns one byte number cast as char
char randGet(void);

//fills stream array with one-byte array chars (pseudo-random)
void fillByteArray(char * stream, int size);

//runs XOR operation with msg chars and stream chars
void XOR_msgStream(char * msg, char * stream, char * output);

//converts one char into two hex digits for readability
void convert(char c, char * ascii);

//converts the one byte output of XOR_msgStream into printable chars
void convertOutput(char * output, char * convertStr, char * ascii);


/* 
   Tries all 26 possibilities (not practical for better encryptions) 
   for Caesar and Affine algorithms
   Starts with shift = 1 because 0 is least likely
 */
int decodeCaesarAffineBrute(char * msg);
