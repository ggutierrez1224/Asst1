#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
    printf("Test Case 3: Free a pointer not returned by malloc\n");
    char* p = (char*) malloc(sizeof(char));
    p = NULL;//(char)'\0';
    printf("address: %p, value: %d\n",p, *p);
    free(p);
}

