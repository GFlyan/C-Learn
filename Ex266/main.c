#include <stdio.h>
#include <stdlib.h>

//Exercício 266: Imprimindo os valores de uma Árvore Binária

typedef struct nodeBinaryTree
/*Criando uma estrutura que diz respeito
à composição dos nós de uma árvore binária*/
{
    int value;//Campo que diz respeito ao valor
    struct NodeBinaryTree *left, *right;//Campos que dizem respeito respectivamente aos endereços do nó a esquerda e do nó a direita
}NodeBinaryTree;

void printBinaryTree1(NodeBinaryTree *binaryTree)
/*Procedimento que imprime os valores contidos
em uma árvore binária.

Recebe como parâmetro o endereço do nó raiz.*/{
    if(binaryTree)
    /*Caso o nó fornecido não esteja vazio*/
    {
        printBinaryTree1(binaryTree->left);//Chamada recursiva da fuñção para imprimir a partir do nó mais a esquerda
        printf("%d ", binaryTree->value);//Impressão do valor contido no nó
        printBinaryTree1(binaryTree->right);//Chamada recursiva para imprimir um nó a direita após imprimir um nó a esquerda
    }
}

void printBinaryTree2(NodeBinaryTree *binaryTree)
/*Procedimento que imprime os valores contidos
em uma árvore binária.

Recebe como parâmetro o endereço do nó raiz.*/{
    if(binaryTree)
    /*Caso o nó fornecido não esteja vazio*/
    {
        printf("%d ", binaryTree->value);//Imprime o valor do nó
        printBinaryTree2(binaryTree->left);//Chamada recursiva para imprimir o nó a esquerda
        printBinaryTree2(binaryTree->right);//Chamada recursiva para imprimir o nó a direita
    }
}

int main()
{
    NodeBinaryTree *binaryTree = malloc(sizeof(NodeBinaryTree)), *aux;//Alocando memória para o primeiro nó da árvore e criando um ponteiro auxiliar
    binaryTree->value = 50;//Nó raiz recebe o valor 50
    binaryTree->left = malloc(sizeof(NodeBinaryTree));//Alocando memória para o nó a esquerda do nó raiz
    aux = binaryTree->left;//Ponteiro auxiliar recebe o endereço do nó a esquerda
    aux->value = 25;//Nó a esquerda recebe o valor 25
    binaryTree->right = malloc(sizeof(NodeBinaryTree));//Alocando memória para o nó a direita do nó raiz
    aux = binaryTree->right;//Ponteiro auxiliar recebe o endereço do nó a direita
    aux->value = 75;//Nó a direita recebe o valor 75
    printf("------------------------------------------\n");
    printf("PRIMEIRA VERSÃO\n\n");
    printBinaryTree1(binaryTree);//Acionando um dos procedimentos que imprime os valores contidos na árvore
    printf("\n------------------------------------------\n");
    printf("SEGUNDA VERSÃO\n\n");
    printBinaryTree2(binaryTree);//Acionando um dos procedimentos que imprime os valores contidos na árvore
    printf("\n------------------------------------------\n");
    return 0;
}
