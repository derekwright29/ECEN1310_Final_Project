# ECEN1310_Final_Project
Final project for ECEN 1310 Spring '17

To Run:
Simply call make after you have downloaded the zip (and unzipped it) and run the resultant executable (./)

This project was a way to learn more about cryptography and an attempt to implement some of this learning into C code with rudimentary user input. Much of this was very intensive and non-trivial, but what I have compiled here represents some very simple (and insecure) cryptographic ciphers that have little real-world meaning nowadays (except for the stream cipher, although modern stream ciphers are much more complex and use a CSPRNG rather than a repeatable, dependent function PRNG, rand()).

Notes on the Project:

General
  For all the stdin input that the user supplies, the C-d command must be called to indicate EOF.
  For the character ciphers (Caesar, Vigenere, Affine) are encoded and decoded using the ASCII values of letters, so having any numbers in your message will result in not being able to decode it correctly (it'll produce a letter when encoded).

For the Caesar Cipher, I useed many limitations
  1) You can't type whitespace characters in your message. This is because scanf stops at the first whitespace char it sees, and I didn't want to overcomplicate it by accounting for this.
  2) I also have a 100 char limit. This can be alleviated with a dynamic array, but I wanted to reduce malloc calls... Keeping it simple.
  
For Vigenere Cipher

For Affine

For Strean

For DES
