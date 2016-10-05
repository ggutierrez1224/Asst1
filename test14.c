#include "mymalloc.h"
#include <stdio.h>
#include <stdlib.h>
//#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
//#define  free(x) myfree((x), __FILE__, __LINE__)
//#define realloc( x, y ) myrealloc( x, y)
//#define calloc( x, y ) mycalloc( x, y)
void main()
{
	printf("Test Case 14: Allocate Max Memory with 1 byte each and free it\n");
	//    void* p;
    int i;
    char *p = (char *)malloc(0);
    printf("\n%c\n\n",*p);
    //  for(i = 1; (p = malloc(0)) != NULL; i++){
    //   printf("%d items allocated\n", i);
    //		free(p);
    // }
}
