

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
// int List_search(Node * head, Node * n);

// print the linked list
void List_print(Node *head);

// free memory in the list
void List_free(Node *head);

#endif
