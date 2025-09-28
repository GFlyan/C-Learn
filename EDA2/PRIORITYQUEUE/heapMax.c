#include <stdlib.h>
#include <stdio.h>

#define Key int
#define key(item) (item.key)
#define Data int
#define nullItem (Item){-1}
#define isNullItem(item) (key(item) == key(nullItem))

typedef struct {
  Key key;
  Data data;
}Item;

typedef struct {
  Item *heap;
  int size, nextPosition;
}priorityQueue;

typedef priorityQueue *PriorityQueue;

Item createItem(Key key) {
  Item item;
  item.key = key;
  item.data = key;
  return item;
}

PriorityQueue createPQ(int size) {
  PriorityQueue newPriorityQueue = malloc(sizeof(priorityQueue));
  newPriorityQueue->heap = malloc(size*sizeof(Item));
  newPriorityQueue->size = size;
  newPriorityQueue->nextPosition = 0;
  for(int i = 0; i < size; i++) {
    newPriorityQueue->heap[i] = nullItem;
  }
  return newPriorityQueue;
}

void heapUp(PriorityQueue priorityQueue, int position) {
  if (!position) return;
  int fatherPosition = (position-1)/2;
  if (key(priorityQueue->heap[position]) > key(priorityQueue->heap[fatherPosition])) {
    Item aux = priorityQueue->heap[position];
    priorityQueue->heap[position] = priorityQueue->heap[fatherPosition];
    priorityQueue->heap[fatherPosition] = aux;
  }
  heapUp(priorityQueue, fatherPosition);
}

void insertPQ(PriorityQueue priorityQueue, Item item) {
  if (priorityQueue->size == priorityQueue->nextPosition) return;
  priorityQueue->heap[priorityQueue->nextPosition++] = item;
  heapUp(priorityQueue, priorityQueue->nextPosition-1);
}

void heapDown(PriorityQueue priorityQueue, int position) {
  int lastPosition = priorityQueue->nextPosition-1;
  int leftSonPosition = 2*position+1;
  int rightSonPosition = 2*position+2;
  int greaterSonPosition;
  if (leftSonPosition < lastPosition && rightSonPosition <= lastPosition) {
    if (key(priorityQueue->heap[leftSonPosition]) > key(priorityQueue->heap[rightSonPosition]))
      greaterSonPosition = leftSonPosition;
    else
      greaterSonPosition = rightSonPosition;
    if (key(priorityQueue->heap[greaterSonPosition]) > key(priorityQueue->heap[position])) {
      Item aux = priorityQueue->heap[greaterSonPosition];
      priorityQueue->heap[greaterSonPosition] = priorityQueue->heap[position];
      priorityQueue->heap[position] = aux;
      heapDown(priorityQueue, greaterSonPosition);
    }
  } else if (leftSonPosition == lastPosition) {
    greaterSonPosition = leftSonPosition;
    if (key(priorityQueue->heap[greaterSonPosition]) > key(priorityQueue->heap[position])) {
        Item aux = priorityQueue->heap[greaterSonPosition];
        priorityQueue->heap[greaterSonPosition] = priorityQueue->heap[position];
        priorityQueue->heap[position] = aux;
      }
  }
}


Item extractMax(PriorityQueue priorityQueue) {
  if (!priorityQueue->nextPosition) return nullItem;
  Item item = priorityQueue->heap[0];
  priorityQueue->heap[0] = priorityQueue->heap[--priorityQueue->nextPosition];
  priorityQueue->heap[priorityQueue->nextPosition] = nullItem;
  heapDown(priorityQueue, 0);
  return item;
}

void printPQ(PriorityQueue priorityQueue) {
  if (!priorityQueue || !priorityQueue->heap || !priorityQueue->nextPosition) return;
  printf("==================================================\n");
  printf("                     HEAP MAX                     \n");
  printf("--------------------------------------------------\n");
  printf("[ ");
  for (int i = 0; i < priorityQueue->size; i++) {
    if (isNullItem(priorityQueue->heap[i])) printf("null ");
    else printf("%d ", key(priorityQueue->heap[i]));
  }
  printf("]\n");
  printf("==================================================\n");
}

int main() {
  PriorityQueue priorityQueue = createPQ(7);

  insertPQ(priorityQueue, createItem(1));
  insertPQ(priorityQueue, createItem(2));
  insertPQ(priorityQueue, createItem(3));
  insertPQ(priorityQueue, createItem(4));
  insertPQ(priorityQueue, createItem(5));
  insertPQ(priorityQueue, createItem(6));
  insertPQ(priorityQueue, createItem(7));

  printPQ(priorityQueue);

  printf("-----------------\n");
  printf("NEXT POSITION: %d\nSIZE: %d\n", priorityQueue->nextPosition, priorityQueue->size);
  printf("-----------------\n");

  Item remove = extractMax(priorityQueue);

  printPQ(priorityQueue);
  printf("-----------------\n");
  printf("NEXT POSITION: %d\nSIZE: %d\n", priorityQueue->nextPosition, priorityQueue->size);
  printf("-----------------\n");
  return 0;
}

