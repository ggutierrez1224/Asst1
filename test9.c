#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
	printf("Test Case 9: freeing p twice\n");
    void* p = malloc(1);
    free(p);
    free(p);
}
