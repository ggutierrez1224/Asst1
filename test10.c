#include "mymalloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void main()
{
	printf("Test Case 10: Mallocing Mutiple pointers and Freeing them\n");
    void* p = malloc(sizeof(int));
    *((int*)p) = 5;
    printf("integer: address: %p, value: %d\n", p, *((int*)p));
    free(p);
    char* c = "Hello World, how are you?"; 
    p = malloc(sizeof(char) * (strlen(c) + 1));
    memcpy(p, c, strlen(c));
    printf("String: address: %p, value: %s\n", p, (char*)p);
    free(p);
    p = malloc(sizeof(float));
    *((float*)p) = 2.222;
    printf("float: address: %p, value: %f\n", p, *((float*)p));
    free(p);

    p = malloc(sizeof(float));
    *((float*)p) = 1.2345;
    printf("float: address: %p, value: %f\n", p, *((float*)p));
    free(p);



    p = malloc(sizeof(float));
    *((float*)p) = 1.2345;
    printf("float: address: %p, value: %f\n", p, *((float*)p));
    free(p);


    p = malloc(sizeof(float));
    *((float*)p) = 1.2345;
    printf("float: address: %p, value: %f\n", p, *((float*)p));
    free(p);

 
     }
