#include "ds.h"
#include "stdio.h"
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
    int value; // stores the value of that node
    struct Node *next; // stores the address of the next node ( null for tail )
};

struct DoublyLinkedList
{
    struct Node *HeadNode;
    struct Node *TailNode;
};

struct DoublyLinkedList *list = NULL;

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

void init_list(int *data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    list = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));

    if (!node || !list)
    {
        fprintf(stderr, "Failed to allocate memory!");
        exit(1);
    }

    node->value = *data;
    node->prev = NULL;
    node->next = NULL;

    list->HeadNode = node;
    list->TailNode = node;
}

void append(int *data){
    if (!list)
    {
        fprintf(stderr, "List not initialized!\n");
        exit(1);
    }
    struct Node *next_node = (struct Node *)malloc(sizeof(struct Node));

    if (!next_node)
    {
        fprintf(stderr, "Failed to allocate memory!");
        exit(1);
    }

    next_node->value = *data;
    list->TailNode->next = next_node;
    next_node->prev = list->TailNode;
    list->TailNode = next_node;
    next_node->next = NULL;
}

void prepend(int *data){
    if (!list)
    {
        fprintf(stderr, "List not initialized!\n");
        exit(1);
    }
    struct Node *prev_node = (struct Node *)malloc(sizeof(struct Node));

    if (!prev_node)
    {
        fprintf(stderr, "Failed to allocate memory!");
        exit(1);
    }

    prev_node->value = *data;
    list->HeadNode->prev = prev_node;
    prev_node->next = list->HeadNode;
    list->HeadNode = prev_node;
    prev_node->prev = NULL;
}

void print_list(){
    if (!list)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *curr = list->HeadNode;
    while (curr)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void free_list(){
    if (!list)
    {
        return;
    }

    struct Node *curr = list->HeadNode;
    struct Node *next;
    while (curr)
    {
        struct Node *next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}