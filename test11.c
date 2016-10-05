#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{ 	
	char *x =  NULL;
	printf("Test Case 11: Free NULL\n");
	free(x);
}
