#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define Key int
#define key(item) (item.key)
#define Data int
#define nullItem (Item) {-1}
#define isNullItem(item) (key(item) == key(nullItem))
#define validItem (Item) {-2}
#define isValidItem(item) (key(item) == key(validItem))

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
    Item item;
    item.key = key;
    item.data = key;
    return item;
}

HashTable createHT(int size) {
    HashTable newHashTable = malloc(sizeof(hashTable));
    newHashTable->table = malloc(size * sizeof(Item));
    newHashTable->size = size;
    newHashTable->amount = 0;
    for (int i = 0; i < size; i++) newHashTable->table[i] = nullItem;
    return newHashTable;
}

int hash(Key key, int size) {
    return key % size;
}

int hashTwo(Key key, int size) {
    return 1 + key % (size-1);
}

void insertItem(HashTable hashTable, int hashPosition, Item item) {
    Item hashItem = hashTable->table[hashPosition];
    if (isNullItem(hashItem) || isValidItem(hashItem)) {
        hashTable->table[hashPosition] = item;
        hashTable->amount++;
        return;
    }
    hashPosition = hash(hashPosition + hashTwo(key(item), hashTable->size), hashTable->size);
    insertItem(hashTable, hashPosition, item);
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
        if (isNullItem(item) || key(item) == key) return item;
        hashPosition = hash( hashPosition + hashTwo(key, hashTable->size),hashTable->size);
    } while (hashPosition != firstPosition);
    return nullItem;
}

bool searchHT(HashTable hashTable, Key key) {
    if (!hashTable->amount) return false;
    int hashPosition = hash(key, hashTable->size);
    return !isNullItem(searchItem(hashTable, hashPosition, key));
}

Item removeItem(HashTable hashTable, int hashPosition, Key key) {
    int firstPosition = hashPosition;
    do {
        Item item = hashTable->table[hashPosition];
        if (isNullItem(item)) break;
        if (key(item) == key) {
            hashTable->table[hashPosition] = validItem;
            hashTable->amount--;
            return item;
        }
        hashPosition = hash(hashPosition + hashTwo(key, hashTable->size), hashTable->size);
    } while (hashPosition != firstPosition);

    return nullItem;
}

Item removeHT(HashTable hashTable, Key key) {
    if (!hashTable->amount) return nullItem;
    int hashPosition = hash(key, hashTable->size);
    return removeItem(hashTable, hashPosition, key);
}

void printHT(HashTable hashTable) {
    if (!hashTable->amount) return;
    printf("------------------------------------------\n");
    printf("                HASH TABLE                \n");
    printf("------------------------------------------\n");
    printf("[ ");
    for (int i = 0; i < hashTable->size; i++) {
        Item item = hashTable->table[i];
        if (isNullItem(item)) printf("null ");
        else if (isValidItem(item)) printf("valid ");
        else printf("%d ", key(item));
    }
    printf(" ]\n");
    printf("------------------------------------------\n");
}

int main() {
    HashTable hashTable = createHT(5);
    //insertHT(hashTable, createItem());
    insertHT(hashTable, createItem(13));
    insertHT(hashTable, createItem(23));
    insertHT(hashTable, createItem(33));
    insertHT(hashTable, createItem(43));
    insertHT(hashTable, createItem(53));
    insertHT(hashTable, createItem(63));

    printHT(hashTable);
    printf(searchHT(hashTable, 53) ? "53 True\n" : "53 False\n");
    printf(searchHT(hashTable, 63) ? "63 True\n" : "63 False\n");

    Item removed = removeHT(hashTable, 33);
    printf("KEY: %d\n", key(removed));
    printHT(hashTable);
    printf(searchHT(hashTable, 53) ? "53 True\n" : "53 False\n");
    printf(searchHT(hashTable, 63) ? "63 True\n" : "63 False\n");

    insertHT(hashTable, createItem(63));
    printHT(hashTable);
    printf(searchHT(hashTable, 53) ? "53 True\n" : "53 False\n");
    printf(searchHT(hashTable, 63) ? "63 True\n" : "63 False\n");

    return 0;
}