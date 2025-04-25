#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Key int
#define Data int
#define key(item) (item.key)
#define eq(valueA, valueB) (valueA == valueB)

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
}Item;

typedef struct node{
    Item item;
    struct node *nextNode;
}STnode;

static STnode *STlinkedList;

bool STinsert(Item newItem) {
    if(!STlinkedList) {
        STlinkedList = malloc(sizeof(STnode));
        STlinkedList->item = newItem;
        STlinkedList->nextNode = NULL;
        return true;
    } else {
        STnode *aux = STlinkedList;
        while(aux->nextNode) aux = aux->nextNode;
        aux->nextNode = malloc(sizeof(STnode));
        aux = aux->nextNode;
        aux->item = newItem;
        aux->nextNode = NULL;
        return true;
    }
    return false;
}

bool STsearch(Key id) {
    STnode **auxSearch = &STlinkedList;
    while(*auxSearch) {
        if(eq(id, (*auxSearch)->item.key)) return true;
        auxSearch = &(*auxSearch)->nextNode;
    }
    return false;
}

bool STremove(Key id) {
    STnode **auxRemove = &STlinkedList;
    while(*auxRemove) {
        if(eq(id, (*auxRemove)->item.key)) {
            *auxRemove = (*auxRemove)->nextNode;
            return true;
        }
        auxRemove = &(*auxRemove)->nextNode;
    }
    return false;
}

Item insertItem() {
    Item newItem;
    printf("------------------------------------------\n");
    printf("INSIRA O ID: ");
    scanf("%d", &newItem.key);
    printf("------------------------------------------\n");
    newItem.data = NULL;
    return newItem;
}

void printST(STnode *ST) {
    if(!ST) return;
    printf(" %d ", ST->item.key);
    printST(ST->nextNode);
}

void printfSTempty() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("------------------------------------------\n");
}

int main()
{
    int option;
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - REMOVER\n3 - PROCURAR\ qqqqn4 - MOSTRAR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &option);
        switch(option) {
            case 1:

                printf("------------------------------------------\n");
                printf(STinsert(insertItem()) ? "ITEM INSERIDO\n" : "ITEM NÃO INSERIDO\n");
                printf("------------------------------------------\n");
                break;
            case 2:
                if(STlinkedList) {
                    Key removeID;
                    printf("------------------------------------------\n");
                    printf("INSIRA O ID A SER REMOVIDO: ");
                    scanf("%d", &removeID);
                    printf("------------------------------------------\n");
                    printf("------------------------------------------\n");
                    //STremove(removeID, &STlinkedList);
                    //printf("TESTA ESSA PORCARIA\n");
                    printf(STremove(removeID) ? "ITEM REMOVIDO\n" : "ITEM NÃO ENCONTRADO\n");
                    printf("------------------------------------------\n");
                } else printfSTempty();
                break;
            case 3:
                if(STlinkedList) {
                    Key searchID;
                    printf("------------------------------------------\n");
                    printf("INSIRA O ID A SER PROCURADO: ");
                    scanf("%d", &searchID);
                    printf("------------------------------------------\n");
                    printf(STsearch(searchID) ? "ITEM ENCONTRADO\n" : "ITEM NÃO ENCONTRADO\n");
                    printf("------------------------------------------\n");
                } else printfSTempty();
                break;
            case 4:
                if(STlinkedList) {
                    printf("------------------------------------------\n");
                    printf("[");
                    printST(STlinkedList);
                    printf("]\n");
                    printf("------------------------------------------\n");
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
