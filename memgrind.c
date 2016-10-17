/*
Assignment 1: A better malloc() and free()

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
#include <sys/time.h>
#include "mymalloc.h"

#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)


void testA()
{
  char *c[3000];
  int i;
   for(i = 0; i < 3000; i++)
    {
      c[i] = (char *) malloc(1);
    }
   
   int j;
   for(j = 0; j < 200; j++)
     {
       free(c[j]);
     }
}

void testB()
{
  char *c;
  int i;
  for(i = 0; i < 3000; i++)
    {
      c = (char *) malloc(1);
      free(c);
      printf("%d\n", i);
    }
}

void testC()
{
  char * c[3000];
  int mIndex = 0;
  int fIndex = 0;
  int mallocs = 0;
  int frees = 0;
  int i = 0;
  
  while (1) 
    {
	  // if choice is even we malloc, else free
      int choice = rand() % 2; 

		if (mallocs == 3000) 
		{
			choice = 0;
			if (frees == 3000) 
	    {
	      break;
	    }
		}
      
		if (choice)
		{
			char * testc = malloc(1);
			c[mIndex] = testc;
			mIndex++;
			mallocs++;
		} 
		else 
		{
			free(c[fIndex]);
			if (fIndex <= mIndex) 
			{
				fIndex++;
				frees++;
			}	
		}
    i++;
	}
}  

int main()
{
  int total = 0, avg, i;
  struct timeval start, end;
  
  for(i = 0; i <= 100; i++)
  {
    gettimeofday(&start, NULL);
    testA();
    testB();
    testC();
	
    gettimeofday(&end, NULL);
    total += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
  }
  avg = total/100 ;
  printf("Average run time: %dms\n", avg);
  return 0;
}
