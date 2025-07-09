#ifndef DS_H
#define DS_H

#include "stdlib.h"

struct DynamicArray
{
    int *data;       // a pointer to the data
    size_t length;   // holds the length of the array
    size_t capacity; // holds the capacity of the array
};

struct Node
{
    struct Node *prev; // stores the address of the previous node ( null for head )
    int value;         // stores the value of that node
    struct Node *next; // stores the address of the next node ( null for tail )
};

struct DoublyLinkedList
{
    struct Node *HeadNode;
    struct Node *TailNode;
};

void init_array(struct DynamicArray *d);
void push(struct DynamicArray *d, int value);
void free_array(struct DynamicArray *d);

void init_list(int *data);
void append(int *data);
void prepend(int *data);
void print_list();
void free_list();

#endif