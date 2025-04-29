#include <stdio.h>
#include <stdlib.h>
#define Key int
#define Data int
#define NULLItem (Item) {-1}
#define key(item) (item.key)
#define equal(value1, value2) (value1 == value2)
#define null(node) (node == NULLNode)

//Exercício 261: TABELA HASH - LISTA ENCADEADA

typedef struct {
  Key key;
  Data data;
}Item;

typedef struct node{
  Item item;
  struct node *nextNode;
}Node;

typedef Node *link;

link *HT, NULLNode;//Cria um vetor de nós e um nó NULL
int amount, hashSize;

link NEW(Item newItem, link nextNode){
  link newNode = malloc(sizeof(Node));
  newNode->item = newItem;
  newNode->nextNode = nextNode;
  return newNode;
}

void HTinit(int size) {
  NULLNode = NEW(NULLItem, NULL);
  amount = 0;
  hashSize = size * 2;
  HT = malloc(sizeof(link) * hashSize);
  for(int clear = 0; clear < hashSize; clear++) HT[clear] = NULLNode;
}

int HTcount() {
  return amount;
}

int hashFunction(Key hashKey) {
  return hashKey % hashSize;
}

void HTinsert(Item newItem) {
  if(HTcount() == hashSize) return;
  int hashPosition = hashFunction(key(newItem));
  HT[hashPosition] = NEW(newItem, HT[hashPosition]);
  amount++;
}

Item HTsearch(Key hashKey) {
  if(!HTcount()) return NULLItem;
  int hashPosition = hashFunction(hashKey);
  link aux = HT[hashPosition];
  while(!equal(hashKey, key(aux->item)) && !null(aux)) aux = aux->nextNode;
  return aux->item;
}

int main() {
  return 0;
}