#include <stdio.h>
#include <stdlib.h>
#define Key int
#define Data int
#define NULLItem (Item) {-1}
#define key(item) (item.key)
#define maxColisions hashSize/2
#define null(item) (key(item) == key(NULLItem))
#define equal(valueA, valueB)  (valueA == valueB)

//Exercício 260: TABELA HASH - VETOR

typedef struct {
  Key key;
  Data data;
}Item;//Diz respeito a um item

Item *HT;//Vetor de itens
int amount, hashSize;//Variáveis globais

void HTinit(int size) {
  amount = 0;
  hashSize = size * 2;
  HT = malloc(hashSize * sizeof(Item));
  for(int clear = 0; clear < hashSize; clear++) HT[clear] = NULLItem;
}//Aloca e inicializa o vetor de itens com NULL

int HTcount() {
  return amount;
}//Retorna a quantidade de elementos que tem na tabela

int hashFunction(Key hashKey) {
  return hashKey % hashSize;
}//Realiza o calcula da hashPosition

void HTinsert(Item newItem) {
  if(HTcount() == hashSize) return;
  int hashPosition = hashFunction(key(newItem));
  for(int colisions = 0 ; colisions < maxColisions && !null(HT[hashPosition]); colisions++) hashPosition = hashFunction(hashPosition + 1);
  if(null(HT[hashPosition])) {
    HT[hashPosition] = newItem;
    amount++;
  }
}//Insere um item na tabela hash

Item HTsearch(Key hashKey) {
  if(!HTcount()) return NULLItem;
  int hashPosition = hashFunction(hashKey);
  for(int colisions = 0 ; colisions < maxColisions && !equal(hashKey, key(HT[hashPosition])) && !null(HT[hashPosition]); colisions++)
    hashPosition = hashFunction(hashPosition + 1);
  return (equal(hashKey, key(HT[hashPosition])) ? HT[hashPosition] : NULLItem);
}//Procura um valor parametrizado na tabela hash

int main() {
  return 0;
}