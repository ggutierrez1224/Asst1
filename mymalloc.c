#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "mymalloc.h"

#define malloc( x ) mymalloc( x, __FILE__, __LINE__)
#define free( x ) myfree( x, __FILE__, __LINE__)

#define MEMAMT 5000


static char ALLMEM[MEMAMT];//memory block for malloc and free implementation
static MemEntry * entryArr[MEMAMT/sizeof(MemEntry)+1]; //array of memEntry pointers
static MemEntry * construct; 
static int currMemUsed = sizeof(MemEntry);

void * mymalloc(unsigned int size, char * filename, unsigned int linenum)
{
  static int isFirst = 0; //flag for if memory is initialized
  MemEntry * next; //pointer for adding new memory blocks
  
  printf("currMemUsed = %d\n", currMemUsed);

  //check is size is 0 or greater than available memory
  if(currMemUsed + size + sizeof(MemEntry) > MEMAMT || size == 0)
    {
      printf("ERROR: Memory requested not available\n");
      return NULL;
    }
 
  //if first malloc call
  if(!isFirst)
    {
      isFirst = 1; //change falg to true

      construct = (MemEntry*) ALLMEM; //make MemEntry pointer to start of ALLMEM
      construct->capacity = MEMAMT - sizeof(MemEntry); //size of memory block
      construct->next = construct->prev = NULL;
      construct->free = 'n'; //flag is false            
      
      //create first memory block
      next = construct + 1; 
      next->prev = construct;
      next->next = (MemEntry*)((char*)(next+1) + size);
      next->capacity = size;
      next->free = 'n';

      //increment current memory usage
      currMemUsed += (size + sizeof(MemEntry));
      
      //store to list
      entryArr[0] = next;

       return (void *)(next + 1);
    }
  
  //find next available opening in entryArr to store new pointer
  int i;
  for(i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
    {
      if (entryArr[i] == NULL)
        {
          break;
        }
    }


  MemEntry * search = construct + 1; //MemEntry pointer to search through list
  while(search != NULL) //loop to see if there is any freed blocks to allocate
    {
      if(search->capacity <= size && search->free == 'y')//memory block is big enough and is free for memory block
        {
          search->free = 'n';
	  currMemUsed += (size + sizeof(MemEntry));
          return (void*)search + sizeof(MemEntry);
        }
      search = search->next;
    }
 
   //no freed blocks were able to be used
  if((currMemUsed < MEMAMT) && ((MEMAMT - currMemUsed - sizeof(MemEntry)) >= size))
   {
     //use free memory and create the MemEntry of the next block 
     next = (MemEntry *)((char *)(entryArr[i-1]+1) + entryArr[i-1]->capacity);
     next->prev = entryArr[i-1];
     next->next = (MemEntry*)((char*)(next+1) + size);
     next->capacity = size;
     next->free = 'n';

     currMemUsed += (size + sizeof(MemEntry)); // increment memory usage
     entryArr[i] = next; //store new entry in array
     
     return (void*)(next + 1);
   }
   
 return NULL;
}


void myfree (void *ptr, char * filename, unsigned int linenum)
{
  if(ptr == NULL) //check for NULL pointer
    {
      printf("Fatal error in malloc call line %d, in file %s\n", linenum, filename);
      printf("Can't free a NULL pointer !\n");
      return;
    }

  MemEntry * anotherPtr = NULL;
  anotherPtr = (MemEntry *)((char*)ptr - sizeof(MemEntry));
  int allocated = 0;
  
  //check if pointer was allocated
  int ind  = 0;
  int i = 0;
  //check to see if pointer is in entryArr
  for(i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
    {
      if(anotherPtr->free  == 'n' && anotherPtr == entryArr[i])
	{
	  ind = i;
	  allocated = 1;
	  break;
	}
    }

  if(allocated != 1)//check if pointer was returned by malloc call
    {
      printf("Fatal Error in free call line %d, in file %s\n", linenum, filename);
      printf("Pointer was not returned by malloc!\n");
      return;
    }
  else if(anotherPtr->prev != NULL && anotherPtr->prev->free == 'y')//check if previous memory block is free
    {
      if(ind != 0)
	{
	  printf("Merging previous with current!\n");
	  //merge previous block with current block
	  anotherPtr->prev->capacity += sizeof(MemEntry)+ anotherPtr->capacity;
	  entryArr[ind] = 0; //free entry in array
	}
    }
  else if(anotherPtr->next != NULL && anotherPtr->next->free == 'y')//check if next memory block is free
    {
      printf("Merging next with current!\n");

      //find entry of next block in entry array
      for(i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
	{
	  if(anotherPtr->next  == entryArr[i])
	    {
	      entryArr[i] = 0;//free entry
	      break;
	    }
	}
     
      //merge current memory block with next memory block
      anotherPtr->prev += sizeof(MemEntry) + anotherPtr->next->capacity;
      anotherPtr->next = anotherPtr->next->next;
    }
   //free pointer 
  
  printf("Freeing pointer!\n");
  anotherPtr->free = 'y';
  currMemUsed -= (sizeof(MemEntry) + anotherPtr->capacity);
}
