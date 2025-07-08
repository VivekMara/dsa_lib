#include "ds.h"
#include "stdio.h"
#include "stdlib.h"

struct DynamicArray
{
    int *data;       // a pointer to the data
    size_t length;   // holds the length of the array
    size_t capacity; // holds the capacity of the array
};

void init_array(struct DynamicArray *d){
    d->length = 0;
    d->capacity = 1;
    d->data = (int *)calloc(d->capacity,sizeof(int));
    if (d->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void push(struct DynamicArray *d, int value){
    if (d->length == d->capacity)
    {
        d->data = (int *)realloc(d->data, d->capacity * 2 * sizeof(int));
        if (d->data == NULL)
        {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
        d->capacity *= 2;
    }
    d->data[d->length++] = value;
}

void free_array(struct DynamicArray *d){
    free(d->data);
    d->data = NULL;
    d->length = 0;
    d->capacity = 0;
}