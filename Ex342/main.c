#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Key int
#define Data int
#define key(item) (item.key)
#define eq(valueA, valueB) (valueA == valueB)
#define NULLItem (Item) {-1}

/*Exercício 342: SYMBOL TABLE - LINKED LIST

Uma ST armazena dados que chamamos de itens, a partir
do ID (Key) de cada item, sendo que os itens podem
ter também dados (Data) associados a eles.

Vantagem:

    Inserção dinâmica, ou seja, não é limitada
    pelo tamanho do array como nos casos passados.

Desvantagem:

    Grande maioria das operações são de custo O(n) devido
    a impossibilidade de acesso direto por índice:

        Inserção no inicio O(1)
        Inserção no meio O(n/2)
        Inserção no final O(n)
        Remover no inicio O(1)
        Remover no meio O(n/2)
        Remover no final O(n)
        Busca em lista ordenada/desordenada O(n)
        Ordenação O(n)
*/

typedef struct {
    Key key;
    Data data;
}Item;//Diz respeito a um item

typedef struct node{
    Item item;
    struct node *nextNode;
}STnode;//Diz respeito ao nó de uma lista encadeada

STnode *STlinkedList, *NULLNode;//Nó cabeça da lista encadeada e um nó vazio NULLNode

STnode* NEW(Item newItem, STnode* nextNode) {
    STnode *newNode = malloc(sizeof(STnode));
    newNode->item = newItem;
    newNode->nextNode = nextNode;
    return newNode;
}//Cria e retorna um novo nó com as especificações passadas

void STinit() {
    NULLNode = NEW(NULLItem, 0);
    STlinkedList = NULLNode;
}//Inicializa a lista encadeada, atribuindo o NULLNode, STinit - caixa preta


STnode* insert(Item newItem, STnode *insertNode) {
    if(insertNode == NULLNode) return insertNode = NEW(newItem, NULLNode);
    insertNode->nextNode = insert(newItem, insertNode->nextNode);
    return insertNode;
}//Insere um novo item no final da lista com as especificações parametrizadas

void STinsert(Item newItem) {
    STlinkedList = insert(newItem, STlinkedList);
}//STinsert - caixa preta

STnode* search(Key id, STnode *searchNode) {
  if(searchNode == NULLNode) return NULLNode;
  if(eq(id, key(searchNode->item))) return searchNode;
  return search(id, searchNode->nextNode);
}//Procura se um item com dado ID existe na ST

bool STsearch(Key id) {
    return search(id, STlinkedList) != NULLNode ? true : false;
}//STsearch - caixa preta

STnode* removeN(Key id, STnode *removeNode) {
  if(removeNode == NULLNode) {
    printf("ITEM NÃO ENCONTRADO\n");
    return NULLNode;
  }
  if(eq(id, key(removeNode->item))) {
    printf("ITEM REMOVIDO\n");
    return removeNode->nextNode;
  }
  removeNode->nextNode = removeN(id, removeNode->nextNode);
  return removeNode;
}//Remove um item dado o ID parametrizado

void STremove(Key id) {
    STlinkedList = removeN(id, STlinkedList);
}//STremove - caixa preta

Item insertItem() {
    Item newItem;
    printf("------------------------------------------\n");
    printf("INSIRA O ID:");
    scanf("%d", &newItem.key);
    printf("------------------------------------------\n");
    newItem.data = 0;
    return newItem;
}//Cria e retorna um novo item com ID fornecido pelo usuário

void printST(STnode *ST) {
    if(ST == NULLNode) return;
    printf(" %d ", key(ST->item));
    printST(ST->nextNode);
}//Mostra todos os elementos existentes na ST

void printfSTempty() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("------------------------------------------\n");
}//Mensagem de ST vazia

int main()
{
    int option;
    STinit();
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - REMOVER\n3 - PROCURAR\n4 - MOSTRAR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA:");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("------------------------------------------\n");
                STinsert(insertItem());
                printf("ITEM INSERIDO\n");
                printf("------------------------------------------\n");
                break;
            case 2:
                if(STlinkedList != NULLNode) {
                    Key removeID;
                    printf("------------------------------------------\n");
                    printf("INSIRA O ID A SER REMOVIDO:");
                    scanf("%d", &removeID);
                    printf("------------------------------------------\n");
                    printf("------------------------------------------\n");
                    STremove(removeID);
                    printf("------------------------------------------\n");
                } else printfSTempty();
                break;
            case 3:
                if(STlinkedList != NULLNode) {
                    Key searchID;
                    printf("------------------------------------------\n");
                    printf("INSIRA O ID A SER PROCURADO:");
                    scanf("%d", &searchID);
                    printf("------------------------------------------\n");
                    printf(STsearch(searchID) ? "ITEM ENCONTRADO\n" : "ITEM NÃO ENCONTRADO\n");
                    printf("------------------------------------------\n");
                } else printfSTempty();
                break;
            case 4:
                if(STlinkedList != NULLNode) {
                    printf("------------------------------------------\n[");
                    printST(STlinkedList);
                    printf("]\n------------------------------------------\n");
                } else printfSTempty();
                break;
            default:
                printf("------------------------------------------\n");
                printf(option ? "OPCAO INVALIDA\n" : "PROGRAMA FINALIZADO\n");
                printf("------------------------------------------\n");
                break;
        }
    } while(option);
    return 0;
}
