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
   for(j = 0; j < 3000; j++)
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


int main()
{
  int total = 0, avg, i;
  struct timeval start, end;
  
  for(i = 0; i <= 100; i++)
   {
      gettimeofday(&start, NULL);
      testA();
      testB();
      //testC();
      //testD();
      //testE();
      //testF();
      gettimeofday(&end, NULL);
      total += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
   }
  avg = total/100 ;
  printf("Average run time: %dms\n", avg);
  return 0;
}
