# Cryptography-Decipher
A project designed to use the concept of cryptography in order to create a cipher in C. 
The program works by encrypting and decrypting words to find a hidden message in a group of letters.
It is designed to only encrypt capital letters. A secret keyword is continiously written so that the the keyword matches the amount of letters as the message that is being encrypted. Following, each letter is compared to the corresponding letter of the keyword and reflected across it. If the program encounters a letter reflecting beyond the bounds of the alphabet, it is set to wrap around. After each letter of the message has been reflected, the encrypted message is then printed out.

The program generally uses knowledge in strings and related functions to allow in the creation of a more practical program such as this cipher.
