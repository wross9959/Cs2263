#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//MAX Equals 150 for whole D2L site 
#define MAX 100

void printArr(char arr[][MAX], int size){

    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < size; i++)
    {
        printf("<%s>\n", arr[i]);
    }
}

void readFile(char *filename)
{
    //If we are in a tag
    bool inTag = false;
    
    //If we are in a comment
    bool inComment = false;

    //The index for storing tags
    int index = 0;

    //The count of unique chars
    int uniqueCount = 0;

    //Array for all words stored
    char word[MAX] = ""; 

    //Array for unique tags
    char unique[100][MAX] = {""};

    //The current value read in
    int currChar;

    //If we found duplicate
    bool found = 0;

    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    while ((currChar = fgetc(file)) != EOF)
    {

        //check if we are at a tag start
        if(currChar == '<'){

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
                //in a tag and not a comment
                inTag = true;

                //add the current word to be returned
                word[index++] = currChar; 
                continue;
            }
        }

        //if the current is at the end of a tag
        else if (currChar == '>')
        {

            //if was in a comment change to false
            if(inComment)
            {
                inComment = false;
                continue;
            }

            //if not in comment
            else{

                //set not in tag
                inTag = false;

                //set the end of the word array
                word[index] = '\0';

                found = 0;

                //loop through the word array to make sure all unique
                for (int i = 0; i < uniqueCount; i++)
                {
                    //check if they are the same
                    if (strcmp(word, unique[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }

                // If the word is unique add it to unique
                if (!found)
                {
                    
                    strcpy(unique[uniqueCount++], word);
                }
                
                //reset index
                index = 0;
            }
        }
        //stores the strings of tags
        if (inTag && !inComment && isalpha(currChar))
        {
            word[index++] = currChar;
        }
    }
    printArr(unique, uniqueCount);
    
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