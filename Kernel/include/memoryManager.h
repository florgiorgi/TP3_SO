#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#define FREEPAGES 300
#define PAGEQUANTITY 262144 // 1GB dividido entre 4KB

struct memoryPage
  {
     void * startingMemory;
     int occupied;
  };

struct memoryFreeStack
  {
     void * memoryFree[FREEPAGES];
     int size;
  };


/*Initialize memory manager by splitting the memory in pages of 4KB and initialize stack for released pages*/ 
void initializeMemoryManager();

/*Splits memory in pages of 4KB*/
void splitMemory();

/*Returns an unused page*/
void * allocPage();

/*Search for a free page*/
void * searchForFreePage();

/*Puts the released page in stack for optimization*/
//void releasePage(struct Process * process);

void markOccupiedPages();

void printMemoryPages();

#endif