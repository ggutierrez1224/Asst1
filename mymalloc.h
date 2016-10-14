#ifndef MYMALLOC
#define MYMALLOC

//structure to implement a linked list on the memory block allMem
struct MemEntry_{
  struct MemEntry_ * next; //pointer to next memory block
  struct MemEntry_ * prev; //pointer to previous memory block
  char free; //flag for whether memory block is free or not
  short capacity; //size of memory given to user
};
typedef struct MemEntry_ MemEntry;

void * myrealloc(void * ptr, unsigned int size_x);
void * mycalloc(unsigned int nmemb, unsigned int size);

void * mymalloc(unsigned int size, char * filename, unsigned int linenum);
void myfree(void * ptr, char * filename, unsigned int linenum);

#endif
