#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
  printf("Test Case 1 : Malloc 5 values and print each value's address\n");
    int i;
    for(i = 0; i < 5; i++){
        int* p = malloc(sizeof(int));
        *p = i;
        printf("address: %p, value: %d\n",p, *p);
    }
}
