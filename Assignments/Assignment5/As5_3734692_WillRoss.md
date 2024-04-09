
# CS2263 Assignment 5

**Student:**  
Name: Will Ross  
Number: #3734692  
Email: [will.ross@unb.ca](mailto:will.ross@unb.ca)

**Date:** April 9th, 2024  
**Due Date:** April 11th, 2024

<div style="page-break-after: always;"></div>

## Contents

- [CS2263 Assignment 5](#cs2263-assignment-5)
  - [Contents](#contents)
  - [Question 1](#question-1)
    - [Answer Q1](#answer-q1)
  - [Question 2](#question-2)
    - [Source Code list.h](#source-code-listh)
    - [Source Code list.c](#source-code-listc)
    - [Source code Htag4](#source-code-htag4)
  - [Question 3](#question-3)
    - [Htags4.c without -m output](#htags4c-without--m-output)
  - [Question 4](#question-4)
    - [htag4.c -m output](#htag4c--m-output)
  - [Question 5](#question-5)
    - [Output without -m A4W2024](#output-without--m-a4w2024)
    - [Output with -m A4W2024](#output-with--m-a4w2024)
  - [Question 6](#question-6)
    - [Output without -m A5W2024](#output-without--m-a5w2024)
    - [Output with -m A5W2024](#output-with--m-a5w2024)

<div style="page-break-after: always;"></div>

## Question 1

In a few sentences describe the design of the htags4 program. Focus on the description of the algorithm used and of any data structures needed to complete the task.

### Answer Q1

For my htag4s program, we will have 3 files, list.h, list.c, htags4.c. list.h is my header file with all my functions for our linkedlist functionality to be called, list.c is my c file used for all of my linked list algorithms for the htags4 program. htags4 is the main file of my program. In list.c i have 5 functions, `*Node_constructor` used for contructing nodes from char inputs from htags. `*list_add` is a function used to add a node onto my linked list of htags htags. `List_search` is a function used to find if the input tag already exists somewhere in the linked list so there is no duplicates. `List_print` is used to print our tag inputs, and `List_free` is used for freeing memory on our linked list.

In htags.c I made quite a bit of changes compared to htags3.c due to the linked list data structure. We read in the users input from the terminal line now checking if the user wants the memory option. Then passing the file and the memory option into a readfile function. Once then we go line to line checking the input for tags. Once we read `<` we add the current char to the word array and set currentAllocat to 1 for memory allocation. Cycling through the while loop if we read a `>` and inTag is true, we add current char and `\0` to the word array and then construct a new Node if we arent in a comment and the tag isnt in the linked list already.
Then we get the size of the node and add it to our current memory allocation and add total memory allocation from the current varible. If in tag is true we will add the tags onto the current word array and make sure incomment isnt true. Then we close the file scanner, print the linked list, free the memory and print the totol memory if the user wanted to see the memory of the program.


<div style="page-break-after: always;"></div>

## Question 2

Show the complete source code.

### Source Code list.h

```c

// header file
#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdio.h>

typedef struct listnode {

  struct listnode *next;
  char *tag;
} Node;

// Constructor
Node *Node_construct(char *tag);

// Add a new node on the linked list
Node *List_add(Node *head, Node *n);

// search for a node in the linked list
int List_search(Node *head, char *tag);

// print the linked list
void List_print(Node *head);

// free memory in the list
void List_free(Node *head);

#endif

```

### Source Code list.c

```c

#include "list.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int totalAllocat = 0;

Node *Node_construct(char *tag) 
{
    size_t tagSize = sizeof(strlen(tag) + 1);
    Node *n = malloc(sizeof(Node));
    

    if (n == NULL) 
    {
        return NULL;
    }

    totalAllocat += sizeof(n);
    n->tag = malloc(sizeof(tagSize));

    if ((n->tag) == NULL) 
    {
        free(n);
        return NULL;
    }

    totalAllocat += tagSize;

    strcpy(n->tag, tag);
    n->next = NULL;
    return n;
}

Node *List_add(Node *head, Node *n) 
{
    if (head == NULL) 
    {
        return n;
    }
    Node *current = head;

    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = n;

    return head;
}

int List_search(Node *head, char *tag) 
{
    Node *current = head;
    while (current != NULL) 
    {
        if (strcmp(current->tag, tag) == 0) 
        {
            return false;
        }
        current = current->next;
    }

    return true;
}

void List_print(Node *head) 
{
    Node *current = head;

    while (current != NULL) 
    {

        printf("%s\n", (current->tag));
        current = current->next;
    }
}

void List_free(Node *head) 
{
    Node *current = head;

    while (current != NULL) 
    {
        Node *temp = current;
        current = current->next;
        free(temp->tag);
        free(temp);
    }
}

```

### Source code Htag4

```c
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
            currentAllocat += 2;
            inTag = false;

            if (!inComment && List_search(head, word)) 
            {
                Node *n = Node_construct(word);
                head = List_add(head, n);

                currentAllocat += sizeof(Node);
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
                currentAllocat++;
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

```

<div style="page-break-after: always;"></div>

## Question 3

Show the output from running htags4 program on the following input HTML code (store it in a file) without using the -m option:

`<html> <b> TEST1 </b> <b> TEST2 </b> </html>`

### Htags4.c without -m output

```html

~/htags$ gcc -o htags4 test.c list.c
~/htags$ ./htags4 index.html
<html>
<b>
</b>
</html>
~/htags$ 

```

<div style="page-break-after: always;"></div>

## Question 4

Show the output from running the htags4 program on the following input HTML code with the -m option specified as the command line parameter  (i.e. $ htags4 -m myInputFile.html):

### htag4.c -m output

```html

~/htags$ ./htags4 index.html -m
Current allocated memory: 26 bytes
Current allocated memory: 14 bytes
Current allocated memory: 18 bytes
Current allocated memory: 30 bytes
<html>
<b>
</b>
</html>
Total allocated memory: 88 bytes
~/htags$ 

```

<div style="page-break-after: always;"></div>

## Question 5

Show the output from running the htags4 program on this HTML file, i.e. the very file describing this assignment: you need to download this file separately from D2L to your computer (do not download the entire D2L web page!). The file name is A4W2024.html.

### Output without -m A4W2024

```html

```

### Output with -m A4W2024

```html

```

## Question 6

Show the output from running the htags4 program on another HTML file, of your choice.
I chose Assignment 5 as the test input as we were asked to test A4 not A5

### Output without -m A5W2024

```html




```

### Output with -m A5W2024

```html

```
