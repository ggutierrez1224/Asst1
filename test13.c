#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
	printf("Test Case 13: Allocating Max Memory\n");
    void* p;
    int i;
    for(i = 1; (p = malloc(i % 2 == 0 ? 1 : 30)) != NULL; i++){
        printf("%d items allocated\n", i);
    }
}
