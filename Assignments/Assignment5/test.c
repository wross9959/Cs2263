#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "list.c"


size_t total_memory_allocated = 0;
bool memory = false;

void readFile(char *fileName, bool memory);

// Modified Node construction to include memory tracking
Node *Node_construct(char *tag) {
    size_t tagLength = strlen(tag) + 1;
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    total_memory_allocated += sizeof(Node);

    n->tag = (char *)malloc(tagLength);
    if (!n->tag) {
        free(n);
        printf("Memory allocation failed\n");
        exit(1);
    }
    total_memory_allocated += tagLength;

    strncpy(n->tag, tag, tagLength);
    n->next = NULL;

    if (memory) {
        printf("Allocated %zu bytes for node, %zu bytes for tag, total so far: %zu bytes.\n", sizeof(Node), tagLength, total_memory_allocated);
    }

    return n;
}

void memory_track_free(void *ptr, size_t size) {
    free(ptr);
    total_memory_allocated -= size;
    if (memory) {
        printf("Freed %zu bytes, total now: %zu bytes.\n", size, total_memory_allocated);
    }
}

void List_free(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        memory_track_free(temp->tag, strlen(temp->tag) + 1);
        memory_track_free(temp, sizeof(Node));
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

void readFile(char *filename, bool memory)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }
    

    Node *head = NULL;
    char tag[256];
    int c;
    bool inTag = false;
    size_t index = 0;


    while((c = fgetc(file)) !=EOF)
    {
        if (c == '<') {
            inTag = true;
            index = 0;
        } else if (c == '>' && inTag) {
            tag[index] = '\0'; // Null-terminate the string
            if (!List_search(head, tag)) {
                Node *newNode = Node_construct(tag);
                head = List_add(head, newNode);
            }
            inTag = false;
        } else if (inTag && index < sizeof(tag) - 1) {
            tag[index++] = (char)c;
        }
    }
    fclose(file);

    List_print(head);
    List_free(head);
    if (memory) {
        printf("Final memory usage: %zu bytes\n", total_memory_allocated);
    }
}