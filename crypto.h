/*Encodes string msg using a caesar cipher with shift shift*/
char * encodeCaesar(char * msg, char * output, int shift);

/*Encodes string msg using a Vigenere Cipher with string key*/
int encodeVigenere(char * msg, char * key);

/*Encodes string msg using DES (Data Encryption Standard)*/
int encodeDES(char *msg, char * key, int * phase);

/*Encodes string msg using affine*/
int encodeAffine(char *msg, int shif1, int shif2);
//multiplier must satisfy: gcd(shif1,26) = 1
//{1,3,5,7,9,11,15,17,19,21,23,25}
//fancy footwork to find a^-1, page 20 in book

/* 
   Tries all 26 possibilities (not practical for better encryptions) 
   for Caesar and Affine algorithms
   Starts with shift = 1 because 0 is least likely
 */
int decodeCaesarAffineBrute(char * msg);

/*Decodes Caesar Cipher*/
int decodeAffine(char * msg, int shift);

/*Decodes Caesar Cipher*/
char * decodeCaesar(char * msg, int shift);

/*decodes Vigenere cipher*/
int decodeVigenere(char * msg, char * key);

/*Decodes DES encryption*/
int decodeDES(char * msg, char * key, int * phase, int manage, void ** limiter);

int streamCipher(char * name, char * recipient, char * pswd);




