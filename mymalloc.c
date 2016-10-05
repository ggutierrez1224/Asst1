
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "mymalloc.h"
#define malloc( x ) mymalloc( x, __FILE__, __LINE__)
#define free( x ) myfree( x, __FILE__, __LINE__)

#define MEMAMT 5000


static char ALLMEM[MEMAMT];//memory block for malloc and free implementation
static void * entryArr[MEMAMT/sizeof(MemEntry)+1]; //array of memEntry pointers
static MemEntry * ptr = NULL;

void * mymalloc(unsigned int size, char * filename, unsigned int linenum)
{ 
  //check is size is 0 or greater than available memory
  if(size > MEMAMT || size == 0)
    {
      printf("ERROR: Memory requested not available\n");
      return NULL;
    }
 
  char *head = ALLMEM; //set head pointer to start of memory block
  MemEntry * construct = (MemEntry*) head; //make MemEntry pointer to head
  
  //if first malloc call
  if(ptr == NULL)
    {
      ptr = construct;
      
      construct->capacity = MEMAMT; //size of memory block
      construct->next = NULL; //set next pointer to null
      construct->prev = NULL;
      construct->free = 1; //flag is true

      //search for first element index without a memEntry
      int i = 0;
      int ind = 0;
      for (i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
	{ 
	  if (entryArr[i] == 0)
	    {
	      ind = i;
	      break;
	    }
	}
      entryArr[ind] = construct; //set first array element to start of memory block
      
      return ((void*)(construct+1)); //cast pointer to void * and increment by 1
    }
  
  //not first malloc call
  
  MemEntry * search = construct; //MemEntry pointer to search through list
  do //loop to continue running length of list till end is reached or return call is made
    {
      if(search->free != 1 || search->capacity < size )//if current position is not free or size too small
	{
	  search = search->next;//update search address
	}
      else if(search->capacity < (size + sizeof(MemEntry)))//memory block is big enough and is free for memory block 
	{
	  search->free = 0;
	  return (void*)search + sizeof(MemEntry);
	}
      else
	{
	  //use free memory and create the MemEntry of the next block
	  MemEntry * next;

	  next = (MemEntry*)((char*)search + sizeof(MemEntry) + size);
	  next->prev = search;
	  next->next = search->next;
	  next->capacity = search->capacity - sizeof(MemEntry) - size;
	  next->free = 1;
	        
	  //search for first element index without a memEntry
	  int i = 0;
	  int ind = 0;
	  for (i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
	    {
	      if (entryArr[i] == 0)
		{
		  ind = i;
		  break;
		}
	    }
	        
	  entryArr[ind] = next; //store new entry in array
	  search->capacity = size;
	  search->free = 0;
	  search->next = next;

	  return (void*)search + sizeof(MemEntry);
	}
        
    }while(search != NULL);
    
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
  for(i = 0; i < (MEMAMT/sizeof(MemEntry)+1); i++)
    {
      if(anotherPtr->free  == 0 && anotherPtr == entryArr[i])
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
    }
  else if(anotherPtr->prev != NULL && anotherPtr->prev->free == 1)//check if previous memory block is free
    {
      printf("Merging previous with current!\n");
      //merge previous block with current block
      anotherPtr->prev->capacity += sizeof(MemEntry)+ anotherPtr->capacity;
      entryArr[ind] = 0; //free entry in array
    }
  else if(anotherPtr->next != NULL && anotherPtr->free == 1)//check if next memory block is free
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
  else //free pointer 
    {
      printf("Freeing pointer!\n");
      anotherPtr->free = 1;
    }
}








