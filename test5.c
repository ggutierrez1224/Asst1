#include "mymalloc.h"
#include <stdio.h>
#define  malloc(x) mymalloc((x), __FILE__, __LINE__)
#define  free(x) myfree((x), __FILE__, __LINE__)
#define realloc( x, y ) myrealloc( x, y)
#define calloc( x, y ) mycalloc( x, y)
void testCaseC() {

  char * work[3000];
  int malloc_index = 0, free_index = 0;
  int mallocs = 0, frees = 0;

  while (1) {

    int r = rand() % 2; //r=1=malloc, r=0=free
    
    if (mallocs == 3000) {

      r = 0;
      if (frees == 3000) {

	break;
      }
    }
    
    if (r) {

      char * testc = malloc(1);
      work[malloc_index] = testc;
      malloc_index++;
      mallocs++;

    } else {

      free(work[free_index]);
      if (free_index <= malloc_index) {

	free_index++;
	frees++;

      }

    }

  }

}

void main()
{
  testCaseC(); 
}
