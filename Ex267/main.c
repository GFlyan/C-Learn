#include <stdio.h>
#include <stdlib.h>

//Exercício 267: Inserção em Árvore Binária de Busca- 2ª VERSÃO

typedef struct binaryTreeNode
/*Estrutura que diz respeito aos dados de um nó
de uma árvore binária*/
{
    int value;//Campo que diz respeito ao valor do nó
    struct binaryTreeNode *left, *right;//Campos que dizem respeito aos nós filhos respectivamente sendo, nó a esquerda e nó a direita
} BinaryTreeNode;

void insertBinaryTree(BinaryTreeNode **binaryTree, int value)
/*Procedimento que insere um novo nó na árvore binária.

Recebe como parâmetro o endereço do ponteiro que está
armazenando a árvore e o valor a ser inserido.*/
{
    if(!(*binaryTree))
    /*Caso o nó analisado esteja vazio.*/
    {
        *binaryTree = malloc(sizeof(BinaryTreeNode));//Alocando endereço de memória como conteudo para um ponteiro
        (*binaryTree)->value = value;//Ponteiro recebe um valor para um campo apontado do tipo inteiro
        (*binaryTree)->left = NULL;//Ponteiro recebe NULL para um campo apontado do tipo ponteiro
        (*binaryTree)->right = NULL;//Ponteiro recebe NULL para um campo apontado do tipo ponteiro
        printf("--------------------------------------------\n");
        printf("VALOR INSERIDO\n");
        printf("--------------------------------------------\n");
    }
    else
    /*Caso o nó analisado não esteja vazio*/
    {
        if(value < (*binaryTree)->value) insertBinaryTree(&((*binaryTree)->left), value);
        /*Se o valor parametrado for menor que o valor contido no nó, o endereço do nó a esquerda será o novo endereço a ser analisado*/
        else insertBinaryTree(&((*binaryTree)->right), value);
        /*Se o valor parametrado for maior que o valor contido no nó, o endereço do nó a direita será o novo endereço a ser analisado*/
    }
}

void printBinaryTree1(BinaryTreeNode *binaryTree)
/*Procedimento que imprime os valores contidos
em uma árvore binária.

Recebe como parâmetro o endereço do nó raiz.*/
{
    if(binaryTree)
    /*Caso o nó fornecido não esteja vazio*/
    {
        printBinaryTree1(binaryTree->left);//Chamada recursiva da fuñção para imprimir a partir do nó mais a esquerda
        printf("%d ", binaryTree->value);//Impressão do valor contido no nó
        printBinaryTree1(binaryTree->right);//Chamada recursiva para imprimir um nó a direita após imprimir um nó a esquerda
    }
}

void printBinaryTree2(BinaryTreeNode *binaryTree)
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


int main() {
    BinaryTreeNode *binaryTree = NULL;//Atribuindo NULL como endereço de memória
    int userValue;//Definindo uma variável que será atribuido um valor fornecido pelo usuário
    do {
        printf("--------------------------------------------\n");
        printf("1 - INSERIR\n2 - IMPRIMIR (1ª VERSAO)\n3 - IMPRIMIR (2ª VERSAO)\n0 - SAIR\n");
        printf("--------------------------------------------\n");
        printf("OPCAO: ");
        scanf("%d", &userValue);//Atribuindo um valor fornecido pelo usuário
        printf("--------------------------------------------\n");
        switch(userValue)
        /*Realizar de acordo com o valor fornecido pelo usuário*/
        {
            case 1: //Caso o usuário queira inserir na árvore
                int value;//Definindo uma variável que será atribuido um valor fornecido pelo usuário
                printf("--------------------------------------------\n");
                printf("INSIRA UM VALOR NA ÁRVORE: ");
                scanf("%d", &value);//Atribuindo um valor fornecido pelo usuário
                printf("--------------------------------------------\n");
                insertBinaryTree(&binaryTree, value);//Acionando o procedimento que insere um novo valor na árvore binária
                break;
            case 2:
                if(binaryTree)
                //Caso exista nós na árvore
                {
                    printf("--------------------------------------------\n");
                    printBinaryTree1(binaryTree);//Acionando um dos procedimentos que mostra os valores contidos na árvore binária
                    printf("\n--------------------------------------------\n");
                } else //Caso não exista nós na árvore
                {
                    printf("--------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("--------------------------------------------\n");
                }
                break;
                case 3:
                if(binaryTree)
                //Caso exista nós na árvore
                {
                    printf("--------------------------------------------\n");
                    printBinaryTree2(binaryTree);//Acionando um dos procedimentos que mostra os valores contidos na árvore binária
                    printf("\n--------------------------------------------\n");
                } else //Caso não exista nós na árvore
                {
                    printf("--------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("--------------------------------------------\n");
                }
                break;

            default:
                if(userValue != 0)
                //Caso o usuário forneça um valor de opção inválida
                {
                    printf("--------------------------------------------\n");
                    printf("OPCAO INVALIDA\n");
                    printf("--------------------------------------------\n");
                } else
                //Caso o usuário queira sair do programa
                {
                    printf("--------------------------------------------\n");
                    printf("ARVORE FINALIZADA\n");
                    printf("--------------------------------------------\n");
                }
                break;
        }
    } while(userValue != 0);//Repetir enquanto o usuário não quiser sair do programa
    return 0;
}
