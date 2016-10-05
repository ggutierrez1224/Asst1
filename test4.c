#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
  printf("Test Case 4: print address and value of 5 var\n");
    int i;
    int* p = malloc(5 * sizeof(int));
    for(i = 0; i < 5; i++)
	{
       	p[i] = i;
		printf("address: %p, value: %d\n", p + i, p[i]);
 	}
   
    free(p);
}
