#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "header.h"

int main(int argc, char* argv)
{
	char * a;
	
	char b[] = "hello everyone";
	printf("String of size %zu: \n", strlen(b));
	a = malloc(sizeof(char)*strlen(b));
	strncpy(a, b, strlen(b));
	
	printf("%s\n", a);
	printf ("%s\n", b);
	
	//free(a);
	
	char * c;
	char d[] = "is this working ?";
	printf ("String of size %zu: \n", strlen(d));
	c = malloc(sizeof(char)*strlen(d));
	strncpy(c, d, strlen(d));
	
	printf("%s\n", c);
	printf ("%s\n", d);
	
	//free(c);
	
	return 0;
}