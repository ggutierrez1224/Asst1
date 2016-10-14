#ASSIGNMENT 1: A better malloc() and free() 

Group 88: Gabriel Gutierrez (gg548) and Ayush Joshi (aj470)

#Description:
-	Our Implementation uses a static char array as the source of memory with a size of 5000 that can easily be increase/decreased by changing the size of  #define MEMAMT
-	A doubly linked list is used to store metadata, which consists of prev/next pointers, a char flag, and short to hold the size of the allocated block
-	Prior to using available memory to create pointer, malloc checks if a freed block can be used in a First Fit fashion
-	A static array is used to store pointers that were malloced for easy checks in free()
-	Free() checks the surrounding blocks of the pointer being freed to check(and if possible) merge freed blocks.
#Error Checks:
-	Malloc does not allow requests 0 byte allocations nor allocations larger than current available memory, and returns a NULL pointer
-	Free checks for NULL pointers
-	Free checks to make sure pointer being freed was passed by malloc
-	Free checks if pointer was not already freed

#Runtime Analysis:
	
