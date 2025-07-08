#ifndef DS_H
#define DS_H

#include "stdlib.h"

struct DynamicArray
{
    int *data;       // a pointer to the data
    size_t length;   // holds the length of the array
    size_t capacity; // holds the capacity of the array
};

void init_array(struct DynamicArray *d);
void push(struct DynamicArray *d, int value);
void free_array(struct DynamicArray *d);

#endif