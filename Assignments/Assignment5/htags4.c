#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "list.h"

size_t totalAllocat = 0;


void printArr(char **arr, int size){

    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < size; i++)
    {
        printf("<%s>\n", arr[i]);
        free(arr[i]);
    }
}

void readFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    //If we are in a tag
    bool inTag = false;
    
    //If we are in a comment
    bool inComment = false;

    //The index for storing tags
    int index = 0;

    //The count of unique chars
    int uniqueCount = 0;

    //Array for all words stored
    char * word = NULL;

    //to add to the 2d array
    int newAllocat = 0;

    //total allocation to the 2d array
    int totalAllocat = 0;

    //Array for unique tags
    char ** unique = NULL;

    //The current value read in
    int currChar;

    //If we found duplicate
    bool found = false;

    int allocatCount = 0;
    int open = '<';
    int close = '>';

    while ((currChar = fgetc(file)) != EOF)
    {

        //check if we are at a tag start
        if(currChar == open){

            //get next char
            currChar = fgetc(file);

            //check if we are at a comment tag
            if(currChar == '!')
            {
                //in a comment
                inComment = true;
                continue;
            }
            else
            {
                newAllocat = 2;
                totalAllocat += 2;

                //in a tag and not a comment

                inTag = true;
                word = malloc(totalAllocat * sizeof(char));

                //add the current word to be returned
                word[index++] = currChar; 
                continue;
            }
        }

        //if the current is at the end of a tag
        else if (currChar == close)
        {

            //if was in a comment change to false
            if(inComment)
            {
                inComment = false;
                continue;
            }

            //if not in comment
            else{

                //set the array to be 2 more for last char and close tag
                newAllocat += 2;
                totalAllocat += 2;
                word = realloc(word, totalAllocat * sizeof(char));
                

                // Set not in tag
                inTag = false;


                // Set the end of the word array    
                word[index] = '\0';


                // Check if the word is unique
                found = false;

                // Loop through the word array to make sure all unique
                for (int i = 0; i < uniqueCount; i++)
                {
                    // Check if they are the same
                    if (strcmp(word, unique[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }

                // If the word is unique
                if (!found)
                {
                    allocatCount += newAllocat;
                    printf("Current Allocation of current tag: %d\n", newAllocat);

                    // Add the word to the unique array
                    unique = realloc(unique, (uniqueCount + 1) * sizeof(char *));
                    
                    // Allocate memory for the word
                    unique[uniqueCount] = malloc(totalAllocat * sizeof(char));

                    // Copy the word to the unique array
                    strcpy(unique[uniqueCount++], word);
                }
                
                // Reset the index
                index = 0;

                // Free the word allocation
                free(word);
            }
        }
        // If we are in a tag and not in a comment        
        if (inTag && !inComment)
        {
            
            // Add a new heap memory allocation
            newAllocat++;
            totalAllocat++;

            // Reallocate the word array
            word = realloc(word, totalAllocat * sizeof(char));

            // Add the current char to the word array
            word[index++] = currChar;
        }
    }
    printArr(unique, uniqueCount);
    fclose(file);
    totalAllocat = allocatCount;
    printf("Total allocated memory: %d\n", totalAllocat);
    free(unique);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);

    return EXIT_SUCCESS;
}