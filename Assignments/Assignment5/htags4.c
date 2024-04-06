#include "list.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char *filename, bool memory) 
{
    FILE *file = fopen(filename, "r");

    if (file == NULL) 
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    bool inTag = false, inComment = false;
    int index = 0, currChar, open = '<', close = '>';

    char word[256];
    Node *head = NULL;

    int totalAllocat = 0;
    int currentAllocat = 0;

    while ((currChar = fgetc(file)) != EOF) 
    {

        if (currChar == open) 
        {
            inTag = true;
            index = 0;
            word[index++] = currChar;
            currentAllocat = 1;
            continue;

        } 
        else if (currChar == close && inTag) 
        {
            word[index++] = currChar;
            word[index] = '\0';
            currentAllocat += 1;
            inTag = false;

            if (!inComment && List_search(head, word)) 
            {

                Node *n = Node_construct(word);
                head = List_add(head, n);
                currentAllocat += sizeof(n);
                totalAllocat += currentAllocat;
                if (memory) 
                {
                    printf("Current allocated memory: %d bytes\n", currentAllocat);
                }
            }
            inComment = false;
        } 
        else if (inTag) 
        {
            if (index == 0 && currChar == '!') 
            {
                inComment = true;
            } 
            else if (!inComment) 
            {
                word[index++] = currChar;
                currentAllocat += sizeof(currChar);
            }
        }
    }

    fclose(file);
    List_print(head);
    List_free(head);
    if (memory) 
    {
        printf("Total allocated memory: %d bytes\n", totalAllocat);
    }
}

int main(int argc, char **argv) 
{
    if (argc < 2) 
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    bool memory = false;
    if (argc == 3 && strcmp(argv[2], "-m") == 0) 
    {
        memory = true;
    }

    readFile(argv[1], memory);

    return EXIT_SUCCESS;
}