#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define Key int
#define key(item) (item.key)
#define Data int
#define nullItem (Item){-1}
#define isNullItem(item) (key(item) == key(nullItem))
#define validItem (Item){-2}
#define isValidItem(item) (key(item) == key(validItem))
#define eq(first, second) (first == second)

typedef struct {
    Key key;
    Data data;
}Item;

typedef struct {
    Item *table;
    int size, amount;
}hashTable;

typedef hashTable *HashTable;

Item createItem(Key key) {
    Item newItem;
    newItem.key = key;
    newItem.data = key;
    return newItem;
}

HashTable createHT(int size) {
    HashTable hashTable = malloc(sizeof(hashTable));
    hashTable->table = malloc(sizeof(Item) * size);
    hashTable->size = size;
    hashTable->amount = 0;
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = nullItem;
    }
    return hashTable;
}

int hash(Key key, int size) {
    return key % size;
}

void insertItem(HashTable hashTable, int hashPosition, Item item) {
    Item itemTable = hashTable->table[hashPosition];
    if (isValidItem(itemTable) || isNullItem(itemTable)) {
        hashTable->table[hashPosition] = item;
        hashTable->amount++;
        return;
    }
    hashPosition = hash(hashPosition+1, hashTable->size);
    return insertItem(hashTable, hashPosition, item);

}

void insertHT(HashTable hashTable, Item item) {
    if (hashTable->amount == hashTable->size) return;
    int hashPosition = hash(key(item), hashTable->size);
    insertItem(hashTable, hashPosition, item);
}

Item searchItem(HashTable hashTable, int hashPosition, Key key) {
    int firstPosition = hashPosition;
    do {
        Item item = hashTable->table[hashPosition];
        if (isNullItem(item) || eq(key, key(item))) return item;
        hashPosition = hash(hashPosition + 1, hashTable->size);
    } while (hashPosition != firstPosition);
    return nullItem;
}

bool searchHT(HashTable hashTable, Key key) {
    if (hashTable->amount == 0) return false;
    int hashPosition = hash(key, hashTable->size);
    return !isNullItem(searchItem(hashTable, hashPosition, key)) ? true : false;
}

void removeItem(HashTable hashTable, int hashPosition, Key key) {
    int firstPosition = hashPosition;
    do {
        Item item = hashTable->table[hashPosition];
        if (isNullItem(item)) break;
        if (eq(key,key(item))) {
            hashTable->table[hashPosition] = validItem;
            hashTable->amount--;
            return;
        }
        hashPosition = hash(hashPosition + 1, hashTable->size);
    } while (hashPosition != firstPosition);
}

void removeHT(HashTable hashTable, Key key) {
    if (hashTable->amount == 0) return;
    int hashPosition = hash(key, hashTable->size);
    removeItem(hashTable, hashPosition, key);
}

void destroyHT(HashTable hashTable) {
    free(hashTable->table);
    hashTable->table = NULL;
    free(hashTable);
    hashTable = NULL;
}

int countHT(HashTable hashTable) {
    return hashTable->amount;
}

void printHT(HashTable hashTable) {
    if (!countHT(hashTable)) return;
    printf("==================================================\n");
    printf("                    HASH TABLE                    \n");
    printf("--------------------------------------------------\n");
    printf("[ ");
    for (int i = 0; i < hashTable->size; i++) {
        Item item = hashTable->table[i];
        if (isNullItem(item)) printf("null ");
        else if (isValidItem(item)) printf("disponivel ");
        else printf("%d ", key(item));
    }
    printf("]\n");
    printf("==================================================\n");
}

int main() {
    HashTable hashTable = createHT(5);

    insertHT(hashTable, createItem(22));
    insertHT(hashTable, createItem(34));
    insertHT(hashTable, createItem(52));
    printHT(hashTable);

    insertHT(hashTable, createItem(72));
    insertHT(hashTable, createItem(99));
    insertHT(hashTable, createItem(4));
    printHT(hashTable);

    removeHT(hashTable, 72);
    printHT(hashTable);

    insertHT(hashTable, createItem(13));
    printHT(hashTable);

    destroyHT(hashTable);
    return 0;
}
