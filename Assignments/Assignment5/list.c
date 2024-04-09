#include "list.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *Node_construct(char *tag) 
{
    Node *n = malloc(sizeof(Node));
    
    if (n == NULL) 
    {
        return NULL;
    }
    size_t tagSize = sizeof(strlen(tag) + 1);
    
    n -> tag = strdup(tag);

    if ((n->tag) == NULL) 
    {
        free(n);
        return NULL;
    }
    n->next = NULL;
    
    return n;
}

// this just adds at the end due adding tags at the end to be read later
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

// int List_search(Node * head, Node * n)
int List_search(Node *head, char *tag) 
{
    Node *current = head;

    while (current != NULL) 
    {
        if (strcmp(current->tag, tag) == 0) 
        {
            return true;
        }
        
        current = current->next;
        
    }

    return false;
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