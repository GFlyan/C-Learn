#include <stdlib.h>
#include <stdio.h>
#define Key int
#define Data int
#define NULLItem (Item) {-1}
#define key(item) (item.key)
#define null(item) (key(item) == key(NULLItem))
#define equal(value1, value2)  (value1 == value2)

typedef struct {
  Key key;
  Data data;
}Item;

Item *HT;
int amount, hashSize;

void HTinit(int size) {
  amount = 0;
  hashSize = size * 2;
  HT = malloc(hashSize * sizeof(Item));
  for(int clear = 0; clear < hashSize; clear++) HT[clear] = NULLItem;
}

int HTcount() {
  return amount;
}

int hashFunction(Key hashKey) {
  return hashKey % hashSize;
}

int doubleHashFunction(Key hashKey) {
  return hashKey % (hashSize - 3) + 1;
}

void HTinsert(Item newItem) {
  int hashPosition = hashFunction(key(newItem));
  int doubleHashPosition = doubleHashFunction(hashPosition);
  while(!null(HT[hashPosition])) hashPosition = hashFunction(hashPosition + doubleHashPosition);
  HT[hashPosition] = newItem;
  amount++;
  if(amount >= hashSize) reallocHash();
}

void reallocHash() {
  if(HTcount() < hashSize) return;
  hashSize = hashSize * 2;
  Item *aux = HT;
  HT = malloc(hashSize * sizeof(Item));
  for(int alloc = 0; alloc < hashSize; alloc++) {
    if(!null(aux[alloc])) HTinsert(aux[alloc]);
    else HT[alloc] = NULLItem;
  }
  free(aux);
}

Item searchItem(Key hashKey) {
  if(!HTcount()) return NULLItem;
  int hashPosition = hashFunction(hashKey);
  int doubleHashPosition = doubleHashFunction(hashPosition);
  while(!equal(hashKey, key(HT[hashPosition])) && !null(HT[hashPosition])) hashPosition = hashFunction(hashPosition + doubleHashPosition);
  return (equal(hashKey, key(HT[hashPosition])) ? HT[hashPosition] : NULLItem);
}

int main() {
  return 0;
}