/*
Assignment 2: A better malloc() and free()

Group 1/0
By:
Gabriel Gutierrez
Netid: gg548
Ayush Joshi
Netid: aj470
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
int main()
{
  
           char *a; 
           char b[] = "hello peepz i am here"; 
           printf("String of size: %zu \n", strlen(b)); 
           a = malloc(sizeof(char)*strlen(b)); 
           strncpy(a, b, strlen(b)); 

 
           printf("%s\n", a); 
          printf("%s\n", b); 

	  char *p;
	  char q[] = "Ayush I am here peepz";
	  printf("String of size: %zu \n", strlen(q));
	  p = malloc(sizeof(char)*strlen(q));
	  strncpy(p, q, strlen(q));


	  printf("%s\n", p);
          printf("%s\n", q);
 
	  //free(a);


	  char *y;
          char u[] = "here";
          printf("String of size: %zu \n", strlen(u));
          y = malloc(sizeof(char)*strlen(u));
          strncpy(y, u, strlen(q));


          printf("%s\n", y);
          printf("%s\n", u);
 
        
           char *c; 
         char d[] = "iz thiz workingz?"; 
         printf("String of size: %zu\n",strlen(d)); 
         c = malloc(sizeof(char)*strlen(d)); 
          strncpy(c, d, strlen(d)); 
 
 
         printf("%s\n", c); 
          printf("%s\n", d);  
 
	  // free(c); 
 
 
  return 0; 
} 
