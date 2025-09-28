#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define Key int
#define key(item) (item.key)
#define Data int
#define nullItem (Item){-1}
#define RED 0
#define isRed(node) (node->color == RED)
#define BLACK 1
#define eq(first, second) (first == second)
#define less(first, second) (first < second)
#define greater(first, second) (first > second)
#define isNullNode(node) (node == nullNode)

typedef struct {
    Key key;
    Data data;
}Item;

typedef struct node {
    Item item;
    struct node *left, *right;
    int amount, color;
}tree;

typedef tree *Tree;

Tree nullNode = NULL;

Item createItem(Key key) {
    Item newItem;
    newItem.key = key;
    newItem.data = key;
    return newItem;
}

Tree createNode(Item item, Tree left, Tree right, int amount) {
    Tree newTree = malloc(sizeof(tree));
    newTree->item = item;
    newTree->left = left;
    newTree->right = right;
    newTree->amount = amount;
    newTree->color = RED;
    return newTree;
}

void initNullNode() {
    if (nullNode) return;
    nullNode = createNode(nullItem, NULL, NULL, 0);
    nullNode->color = BLACK;
}

Tree createTree() {
    return nullNode;
}

Tree searchItem(Tree node, Key key) {
    if (isNullNode(node) || eq(key, key(node->item))) return node;
    if (less(key, key(node->item))) return searchItem(node->left, key);
    return searchItem(node->right, key);
}

bool searchTree(Tree tree, Key key) {
    return !isNullNode(searchItem(tree, key)) ? true : false;
}

Tree rotateLeft(Tree downNode) {
    Tree upNode = downNode->right;
    downNode->right = upNode->left;
    upNode->left = downNode;
    upNode->color = downNode->color;
    downNode->color = RED;
    upNode->amount = downNode->amount;
    downNode->amount = 1 + downNode->left->amount + downNode->right->amount;
    return upNode;
}

Tree rotateRight(Tree downNode) {
    Tree upNode = downNode->left;
    downNode->left = upNode->right;
    upNode->right = downNode;
    upNode->color = downNode->color;
    downNode->color = RED;
    upNode->amount = downNode->amount;
    downNode->amount = 1 + downNode->left->amount +downNode->right->amount;
    return upNode;
}

void flipColors(Tree node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

Tree insertItem(Tree node, Item item) {
    if (isNullNode(node)) return createNode(item, nullNode, nullNode, 1);
    if (less(key(item), key(node->item))) node->left = insertItem(node->left, item);
    else if (greater(key(item), key(node->item))) node->right = insertItem(node->right, item);
    if (!isRed(node->left) && isRed(node->right)) node = rotateLeft(node);
    if (isRed(node->left) && isRed(node->left->left)) node = rotateRight(node);
    if (isRed(node->left) && isRed(node->right)) flipColors(node);
    node->amount = 1 + node->left->amount + node->right->amount;
    return node;
}

void insertTree(Tree *tree, Item item) {
    *tree = insertItem(*tree, item);
    if (isRed((*tree))) (*tree)->color = BLACK;
}

void printItem(Tree node) {
    if (isNullNode(node)) return;
    printItem(node->left);
    printf("%d ", key(node->item));
    printItem(node->right);
}

void printTree(Tree tree) {
    if (isNullNode(tree)) return;
    printf("==================================================\n");
    printf("                     RED BLACK                    \n");
    printf("--------------------------------------------------\n");
    printf("[ ");
    printItem(tree);
    printf("]\n");
    printf("==================================================\n");
}

int main() {
    initNullNode();
    Tree tree = createTree();
    insertTree(&tree, createItem(5));
    insertTree(&tree, createItem(7));
    insertTree(&tree, createItem(9));
    insertTree(&tree, createItem(6));
    insertTree(&tree, createItem(4));
    printTree(tree);
}