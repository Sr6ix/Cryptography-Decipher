#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define KEYWD "LEXICON"  //Define keyword to be LEXICON

int main() {
    char input[50];                         //Asks user to input a series of letters with a maximum of 50 characters
    printf("Enter secret message: ");
    fgets(input, 50, stdin);

    char removeSpace[strlen(input)];       //Removes any of the spaces from the input
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i]) != 0) continue;
        removeSpace[j] = input[i];
        j++;
    }
    removeSpace[j] = '\0';

    int inputSize = strlen(removeSpace);      //Creating the secret key
    char key[inputSize + 1];
    int k = 0;
    for (int i = 0; i < inputSize; i++) {
        if (isupper(removeSpace[i])) {          //If statement to ignore letters that are not capital
            key[i] = KEYWD[k % strlen(KEYWD)];
            k++;
        } else {
            key[i] = removeSpace[i];
        }
    }
    key[inputSize] = '\0';

    char output[inputSize + 1];
    for (int i = 0; i < inputSize; i++) {
        int distance = key[i] - removeSpace[i];
        char c = distance + key[i];
        if (distance != 0) {                        //If the letter reflects out of the alphabet, it is then wrapped around.
            if (c > 'Z') {
                c -= 26;
            } else if (c < 'A') {
                c += 26;
            }
        }
        output[i] = c;
    }
    output[inputSize] = '\0';

    int finalLength = inputSize+28;      //Adding the begin and end phrases for the final message. The number "28" is calculated by adding the number of characters from the begin and end phrases
    char finalMessage[finalLength];
    strcpy(finalMessage, "*BEGIN_MESSAGE*\n");
    strcat(finalMessage, output);
    strcat(finalMessage, "\n*END_MESSAGE*");

    printf("%s\n", finalMessage);       //Printing the final statement

    return 0;
}
