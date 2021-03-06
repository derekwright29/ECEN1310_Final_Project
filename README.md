# ECEN1310_Final_Project
Final project for ECEN 1310 Spring '17

To Run:
Simply call make after you have downloaded the zip (and unzipped it) and run the resultant executable (./run_crypto)

This project was a way to learn more about cryptography and an attempt to implement some of this learning into C code with rudimentary user input. Much of this was non-trivial, but what I have compiled here represents some very simple (and insecure) cryptographic ciphers that have little real-world meaning nowadays (except for the stream cipher, although modern stream ciphers are much more complex and use a CSPRNG rather than a repeatable, dependent function PRNG, rand()).

Notes on the Project:

General

  For all the stdin input that the user supplies, the C-d command must be called to indicate EOF. This includes for integer scans because I check for bad string input.
  For the character ciphers (Caesar, Vigenere, Affine) are encoded and decoded using the ASCII values of letters, so having any numbers in your message will result in not being able to decode it correctly (it'll produce a letter when encoded). For the stream cipher, any characters are acceptable.
  I use a character limit of 100 chars for all my input. This is non-ideal, since it is so short, but I didn't want to have to call malloc at all in order to keep it simple.
  For all input, I get rid of the spaces in between words. Either will work, but spaces won't come out at the output.
  I do test for lower case and upper case at some points during my shift encryptions, which probably makes the ciphers even less secure...
  I test for bad input everywhere... except the run_crypto program. So when you type a letter or a 6 when I ask for a 0-5, the program will end. 

Caesar Cipher:

  This is just your run of the mill shift cipher. We did one just like it as a homework assignment.

For Vigenere Cipher:

  This is a variable caesar cipher depending on the characters of a key string. key string of "aa" as well as "aaaaa" will prroduce no shift, and so on.
  
For Affine:

  Caesar cipher but the shift is computed with two integers and the character C is encoded to output O as such: O = a*C+b.
  To decode, we must find the inverse of a or the message is unrecoverable algorithmically. The constraint of this is: (a*a^-1)%26 = 1. From there: C = (a^-1)*(O-b)
  
For Stream:

  The stream cipher is the most relevent, but I dumbed it down a lot. 
  First, I used the rand() function. This is a psuedo-random number generator that produces the exact same sequence of numbers everytime you call it a number of times... So much for random. 
  The principles hold though, because XOR operation with pseudo-random numbers (PRNs) produces a "random output" that can easily be decoded by doing the same XOR operation with the same sequence (or stream) of PRNs. The stream is the key.
  

Debugging and Structure:

I started my project by splitting up the ciphers into their own programs. I would write a main for that program in order to test each individually, and then when it worked I added the functions to my header file and added the OBJ in my Makefile. I also wrote the run_crypto program very early so I knew where I was headed and I knew how it work work in the end. My design originally called for a program that simply took you through my different ciphers and then ended, forcing you to have to run again in order to play with any ciphers. I changed that later, implementing a state machine essentially that allows you to jump around and retry ciphers to your heart's desire. I had many bugs in the input department. Trying to get good input and testing for all the bad was very time-consuming (like how to clear stdin if a letter was given and and integer was asked for. I ended up scanning the full input by looping and scanning strings. Then I would try to sscanf an integer out of that).

Future
My original goal was to build up to the Data Encryption Standard and implement a C program modelling its function, but it turned out to be quite complicated and with my other ciphers taking up time, I couldn't get to it. The project accomplished its goal, though, by interesting me and teaching me very much about the field of cryptography.

Software
I tried to download a Cryptographically Secure Psuedo-Random Number Generator (CSPRNG), but couldn't get it to work in my VM and went with the rand() function in the end. No external software was used.
