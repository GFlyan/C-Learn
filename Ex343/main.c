#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Key int
#define Data int
#define key(item) item.key
#define less(firstValue, secondValue) (firstValue < secondValue)
#define eq(valueA, valueB) (valueA == valueB)

/*Exercício 343: SYMBOL TABLE - BINARY SEARCH TREE

Para evitar os problemas de custo dos outros
modelos de ST como:

    - ARRAY INSERÇÃO NO FINAL: Busca O(n), remoção O(n)
    - ARRAY DE ACESSO DIRETO:  Muita alocação de memória e limitação de inserção de acordo com o tamanho máximo defino para o vetor
    - LINKED LIST: Busca O(n), inserção O(n), remoção O(n)

implementamos a ST com BST.

Vantagem:

    inserção -> O(logn)
    remoção -> O(logn)
    busca -> O(logn)

Desvantagem:

    Desbalanceamento da árvore pode causar custos O(n).
*/

typedef struct { //Estrutura que diz respeito a um item
    Key key; //ID do item
    Data data; //Dados associados ao item
}Item;

typedef struct node { //Estrutura que diz respeito aos nós de uma árvore binária
    Item item; //Item associado ao nó
    struct node *leftNode, *rightNode; //Nós filhos associados
}STnode;

static STnode *STbinarySearchTree; //Criação estática de uma Symbol Table

bool STinsert(Item newItem, STnode **ST) { //Função que insere um novo item na árvore binária
    if(!(*ST)) {
        *ST = malloc(sizeof(STnode));
        (*ST)->item = newItem;
        return true;
    }
    else if (less(key(newItem), key((*ST)->item))) return STinsert(newItem, &(*ST)->leftNode);
    else return STinsert(newItem, &(*ST)->rightNode);
}

bool STremove(Key id, STnode **ST) { //Função que remove um item da árvore binária
    if(!*ST) return false; //Caso o nó analisado aponte pra NULL
    if(eq(id, key((*ST)->item))) { //Caso o ID seja encontrado

        if(!(*ST)->leftNode && !(*ST)->rightNode) *ST = NULL; //Caso o nó que contém o ID não tenha filhos

        else if((*ST)->leftNode && (*ST)->rightNode) { //Caso o nó que contém o ID tenha dois filhos
            STnode **aux = &(*ST)->rightNode;
            while((*aux)->leftNode) aux = &(*aux)->leftNode;
            (*aux)->leftNode = (*ST)->leftNode;
            if(eq((*ST)->rightNode, *aux)) (*aux)->rightNode = NULL;//Caso o nó filho a esquerda seja o próprio
            else (*aux)->rightNode = (*ST)->rightNode;
            free(*ST);
            *ST = *aux;
            *aux = NULL;
        }

        else { //Caso o nó que contém o ID tenha apenas um único filho
            if((*ST)->leftNode && !(*ST)->rightNode) //Caso o único nó filho existente seja o nó a esquerda
                *ST = (*ST)->leftNode;
            else //Caso o único nó filho existente seja o nó a direita
                *ST = (*ST)->rightNode;
        }
        return true;
    } else {
        if(less(id, key((*ST)->item))) return STremove(id, &(*ST)->leftNode);
        return STremove(id, &(*ST)->rightNode);
    }
}

Item insertItem() { //Funçã que retorna um item criado a partir de informações fornecidas pelo usuário
    Item newItem;
    printf("---------------------------------------------\n");
    printf("INFORME O ID: ");
    scanf("%d", &newItem.key);
    printf("---------------------------------------------\n");
    newItem.data = NULL;
    return newItem;
}

void printSTempty() { //Procedimento que mostra uma mensagem
    printf("---------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("---------------------------------------------\n");
}

void printST(STnode *ST) { //Procedimento que percorre em ordem a árvore e mostra todos os itens existentes nela
    if(!ST) return;
    printST(ST->leftNode);
    printf(" %d ", ST->item.key);
    printST(ST->rightNode);
}
int main()
{
    int option;
    do {
        printf("---------------------------------------------\n");
        printf("1 - INSERIR\n2 - REMOVER\n4 - MOSTRAR\n0 - SAIR\n");
        printf("---------------------------------------------\n");
        printf("INSERIR: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("---------------------------------------------\n");
                printf(STinsert(insertItem(), &STbinarySearchTree) ? "ITEM INSERIDO\n" : "ITEM NÃO INSERIDO\n");
                printf("---------------------------------------------\n");
                break;
            case 2:
                if(!STbinarySearchTree) printSTempty();
                else {
                    Key removeID;
                    printf("---------------------------------------------\n");
                    printf("INSIRA O ID A SER REMOVIDO: ");
                    scanf("%d", &removeID);
                    printf("---------------------------------------------\n");
                    printf(STremove(removeID, &STbinarySearchTree) ? "ITEM REMOVIDO\n" : "ITEM NÃO ENCONTRADO\n");
                    printf("---------------------------------------------\n");

                }
                break;
            case 4:
                if(!STbinarySearchTree) printSTempty();
                else {
                    printf("---------------------------------------------\n");
                    printf("[");
                    printST(STbinarySearchTree);
                    printf("]\n");
                    printf("---------------------------------------------\n");
                }
                break;
            default:
                printf("---------------------------------------------\n");
                printf(option ? "OPCAO INVALIDA\n" : "PROGRAMA FINALIZADO\n");
                printf("---------------------------------------------\n");
                break;
        }
    } while(option);
    return 0;
}
