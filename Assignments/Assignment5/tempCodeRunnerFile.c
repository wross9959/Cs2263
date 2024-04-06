#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "list.h"



void printArr(char **arr, int size){

    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < size; i++)
    {
        printf("<%s>\n", arr[i]);
        free(arr[i]);
    }
}

void readFile(char *filename, bool memory)
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

    //
    int currAllocat = 0;

    int totalPrint = 0;

    //Array for unique tags
    char ** unique = NULL;

    //The current value read in
    int currChar;

    //If we found duplicate
    bool found = false;

    int allocatCount = 0;
    int open = '<';
    int close = '>';

    Node * head = NULL;

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
                //totalAllocat += 2;

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
                totalAllocat += newAllocat;

                word = realloc(word, totalAllocat);
                

                // Set not in tag
                inTag = false;


                // Set the end of the word array    
                word[index] = '\0';


                Node * n = Node_construct(word);

                // If the word is unique
                if (head == NULL)
                {
                    allocatCount += newAllocat;


                    // may need to do something with -m here
                    if(memory)
                    {
                        printf("Current Allocation of current tag: %d\n", newAllocat);

                    }

                    head = List_add(head, n);
                }

                else if(List_search(head, n))
                {
                    currAllocat = newAllocat + (sizeof(n) + (sizeof(n -> tag)));
                    totalPrint += currAllocat;
                    head = List_add(head, n);
                    if(memory){
                        printf("Current Allocation of current tag: %d\n", newAllocat);
                    }

                }
                else
                {
                    free(n -> tag);
                    free(n);
                }
                
                // Reset the index
                index = 0;
                totalAllocat = 0;
                // Free the word allocation
                free(word);
            }
        }
        // If we are in a tag and not in a comment        
        if (inTag && !inComment)
        {
            
            // Add a new heap memory allocation
            newAllocat++;
            totalAllocat += newAllocat;

            // Reallocate the word array
            word = realloc(word, totalAllocat * sizeof(char));

            // Add the current char to the word array
            word[index++] = currChar;
        }
    }
    List_print(head);
    fclose(file);
    List_free(head);
    if(memory)
    {
        printf("Total allocated memory: %d\n", totalAllocat);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }
    /* check if memory option has been specified */
    bool memory = false;
    if (argc == 3 && strcmp(argv[2], "-m") == 0)
    {
        memory = true;
    }

    readFile(argv[1], memory);

    return EXIT_SUCCESS;
}