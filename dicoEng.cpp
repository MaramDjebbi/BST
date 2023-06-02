#include "BST.h"
#include <bits/stdc++.h>
using namespace std;

// Return a random number
int randomNum(int maxNum){
int y = rand();
return y%maxNum;
}

// Draw a word from the dictionary
int chosen[1005], count = 0;
int drawWord(char drawnWord){
    FILE dictionary = NULL;
    int numWords = 0, chosenWordNum = 0, i = 0;
    int characterRead = 0;
    dictionary = fopen("dictionary.txt", "r"); // Open the file in read mode
    if (dictionary == NULL){ // The file does not exist
        cout << "\nUnable to load the word dictionary\n";
        return 0;
        }
    while (characterRead != EOF){ // Count the number of words in the file
        characterRead = fgetc(dictionary);
        if (characterRead == '\n' || characterRead == EOF)
        numWords++;
    };
    if (count == numWords) return 0; // The file contains no words
    while (true){
        chosenWordNum = randomNum(numWords);
        if (chosen[chosenWordNum]) continue;
        chosen[chosenWordNum] = 1;
        count++;
        break;
    }
    rewind(dictionary); // Return to the beginning of the file
        while (chosenWordNum > 0){ // Traverse the file to find the word to draw
        characterRead = fgetc(dictionary);
        if (characterRead == '\n')
        chosenWordNum--;
    }
    fgets(drawnWord, 100, dictionary); // Draw the word
    drawnWord[strlen(drawnWord) - 1] = '\0'; // Replace the last character of the line (which is '\n') with a '\0'
    fclose(dictionary); // Close the text file
    return 1;
}