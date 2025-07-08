#include "stdio.h"
#include "ds.h"

int main(){
    struct DynamicArray arr;
    init_array(&arr);
    push(&arr, 1);
    push(&arr, 2);
    push(&arr, 2);
    printf("The length of the array is %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
    
    free_array(&arr);
    return 0;
}