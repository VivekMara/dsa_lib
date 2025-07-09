#include "stdio.h"
#include "ds.h"

int main(){
    int a = 10, b = 20, c = 30;
    init_list(&a);
    append(&b);
    prepend(&c);
    print_list();
    free_list();
    return 0;
}