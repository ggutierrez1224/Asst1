#ifndef MYMALLOC
#define MYMALLOC

//static char ALLMEM[5000]; //memory block that will be used to implement myMalloc and myFree
//char * end = ALLMEM + 5000; //points to end of memory block

//structure to implement a linked list on the memory block allMem
struct MemEntry_{
	int capacity; //size of memory given to user
	struct MemEntry_ * next; //pointer to next memory block
	struct MemEntry_ * prev; //pointer to previous memory block
	int free; //flag for whether memory block is free or not
};
typedef struct MemEntry_ MemEntry;

//MemEntry * ptr = NULL; //points to start of list 

void * myrealloc(void * ptr, unsigned int size_x);
void * mycalloc(unsigned int nmemb, unsigned int size);

void * mymalloc(unsigned int size, char * filename, unsigned int linenum);
void myfree(void * ptr, char * filename, unsigned int linenum);

#endif
