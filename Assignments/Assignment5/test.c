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
    int index = 0, currChar, prevChar, open = '<', close = '>';

    char *word = malloc(1);
    Node *head = NULL;

    int totalAllocat = 0;
    int tagCount = 0;

    while ((currChar = fgetc(file)) != EOF) {


        if (currChar == '!' && prevChar == '<') 
        {
            inComment = true;
            inTag = false; 
            index = 0; 
            continue; 
        }
        if (inComment && prevChar == '-' && currChar == '>') 
        {
            inComment = false;
            continue; 
        }
        if (inComment) 
        {
            prevChar = currChar; 
            continue; 
        }

   
        if (!inTag && currChar == '<') 
        {

            inTag = true;
            word = realloc(word, index + 2);
            word[index++] = currChar;

        } 
        else if (inTag && currChar == '>') 
        {

            word[index++] = currChar;
            word[index] = '\0'; 
            if (!List_search(head, word)) 
            {
                Node *n = Node_construct(word);
                head = List_add(head, n);
                int currentTagMem = sizeof(Node) + strlen(n->tag) + 1;
                totalAllocat += currentTagMem;
                if (memory) 
                {
                    printf("Current allocated memory: %d bytes\n", currentTagMem);
                    tagCount++;
                }
            }
            word[0] = '\0'; 
            index = 0; 
            inTag = false;
        } 
        else if (inTag) 
        {
            word = realloc(word, index + 2); 
            word[index++] = currChar;
        }

        prevChar = currChar; 
    }

    fclose(file);
    List_print(head);
    List_free(head);
    free(word);

    if (memory) 
    {
        printf("Total allocated memory: %d bytes\n", totalAllocat);
        printf("Number of tags found: %d\n", tagCount);
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