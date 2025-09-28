#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define Key int
#define key(item) (item.key)
#define Data int
#define nullItem (Item) {-1}
#define isNullNode(node) (node == nullNode)
#define eq(first, second) (first == second)


typedef struct {
    Key key;
    Data data;
} Item;

typedef struct node {
    Item item;
    struct node *next;
}node;

typedef node *Node;

typedef struct {
    Node *table;
    int size, amount;
}hashTable;

typedef hashTable *HashTable;

Item createItem(Key key) {
    Item newItem;
    newItem.key = key;
    newItem.data = key;
    return newItem;
}

Node createNode(Item item, Node next) {
    Node newNode = malloc(sizeof(node));
    newNode->item = item;
    newNode->next = next;
    return newNode;
}

Node nullNode = NULL;

void initNullNode() {
    if (!nullNode) nullNode = createNode(nullItem, NULL);
}


HashTable createHT(int size) {
    HashTable newHashTable = malloc(sizeof(hashTable));
    newHashTable->table = malloc(size * sizeof(Node));
    for (int i = 0; i < size; i++) {
        newHashTable->table[i] = nullNode;
    }
    newHashTable->size = size;
    newHashTable->amount = 0;
    return newHashTable;
}

int hash(Key key, int size) {
    return key % size;
}

Node insertItem(Node node, Item item) {
    Node newNode = createNode(item, node);
    return newNode;
}

void insertHT(HashTable hashTable, Item item) {
    int hashPosition = hash(key(item), hashTable->size);
    hashTable->table[hashPosition] = insertItem(hashTable->table[hashPosition], item);
    hashTable->amount++;
}

Node searchItem(Node node, Key key) {
    if (isNullNode(node)) return node;
    if (eq(key, key(node->item))) return node;
    return searchItem(node->next, key);
}

bool searchHT(HashTable hashTable, Key key) {
    int hashPosition = hash(key, hashTable->size);
    return !isNullNode(searchItem(hashTable->table[hashPosition], key)) ? true : false;
}

void removeItem(HashTable hashTable, Node *node, Key key) {
    if (isNullNode(*node)) return;
    if (eq(key, key((*node)->item))) {
        *node = (*node)->next;
        hashTable->amount--;
        return;
    }
    return removeItem(hashTable, &(*node)->next, key);
}

void removeHT(HashTable hashTable, Key key) {
    int hashPosition = hash(key, hashTable->size);
    removeItem(hashTable, &hashTable->table[hashPosition], key);
}

void destroyHT(HashTable hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        free(hashTable->table[i]);
        hashTable->table[i] = NULL;
    }
    free(hashTable->table);
    hashTable->table = NULL;
    free(hashTable);
    hashTable = NULL;
}

int countHT(HashTable hashTable) {
    return hashTable->size;
}

void printHT(HashTable hashTable) {
    if (!countHT(hashTable)) return;
    printf("==================================================\n");
    printf("                    HASH TABLE                    \n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("[%d] ", i);
        printf("[ ");
        Node node = hashTable->table[i];
        while (!isNullNode(node)) {
            printf("%d ", key(node->item));
            node = node->next;
        }
        printf("]\n");
    }
    printf("==================================================\n");
}

int main() {
    initNullNode();
    HashTable hashTable = createHT(5);

    insertHT(hashTable, createItem(22));
    insertHT(hashTable, createItem(34));
    insertHT(hashTable, createItem(52));
    printHT(hashTable);

    insertHT(hashTable, createItem(72));
    insertHT(hashTable, createItem(99));
    insertHT(hashTable, createItem(4));
    printHT(hashTable);

    removeHT(hashTable, 52);
    printHT(hashTable);

    insertHT(hashTable, createItem(13));
    printHT(hashTable);

    destroyHT(hashTable);
    return 0;
}

