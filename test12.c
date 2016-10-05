#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
	printf("Test Case 12: Allocating Max bytes\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(i)) != NULL; i++){
        printf("%d bytes allocated\n", i);
    }
}
