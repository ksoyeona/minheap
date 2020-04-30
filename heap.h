#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>
struct Entry {
  int key;
  char* value;
};

typedef struct Entry Entry;

struct Heap {
  int capacity;
  int size;
  Entry** elements;
};

typedef struct Heap Heap;

Heap* makeHeap(int capacity);
void add(Heap* heap, int priority, char* value);
char* removeMin(Heap* heap);
char* peek(Heap* heap);
int size(Heap* heap);
void cleanupHeap(Heap* h);

#endif
