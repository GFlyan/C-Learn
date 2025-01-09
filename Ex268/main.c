#include <stdio.h>
#include <stdlib.h>

//Exercício 268: Inserção em Árvore Binária - 3ª VERSÃO

typedef struct binaryTreeNode
/*Estrutura que diz respeito aos nós de uma
árvore binária.*/
{
    int value;//Campo que diz respeito ao valor do nó
    struct binaryTreeNode *left, *right;//Campos que dizem respeito aos nós filhos sendo respectivamente, nó esquerdo e nó direito
}BinaryTreeNode;

void insertBinaryTree(BinaryTreeNode **binaryTree, int value)
/*Procedimento que realiza a inserção de um nó
na árvore binária.

Recebe como parâmetro o endereço de memória
do ponteiro da raiz e o valor a ser inserido.*/
{
    BinaryTreeNode *auxNewNode = *binaryTree;
    /*Criando respectivamente, um ponteiro que recebe o endereço de memória
    do conteudo do ponteiro da raiz e um ponteiro que recebe o endereço de
    memória do ponteiro da raiz;*/
    while(auxNewNode)
    /*Enquanto o conteúdo de memória analisado existir*/
    {
        if(value < auxNewNode->value) binaryTree = &(auxNewNode->left);
        /*Caso o valor parametrado seja menor que o valor contido no nó analisado
        será acessado o nó filho a esquerda*/
        else binaryTree = &(auxNewNode->right);
        /*Caso o valor parametrado seja maior que o valor contido no nó analisado
        será acessado o nó filho a direita*/
        auxNewNode = *binaryTree;//Ponteiro recebe o endereço de memória do proximo nó a ser analisado
    }
    auxNewNode = malloc(sizeof(BinaryTreeNode));//Alocando memória para o novo nó
    auxNewNode->value = value;//Atribuindo o valor parametrado ao nó
    auxNewNode->left = NULL;//Atribuindo NULL ao nó filho a esquerda
    auxNewNode->right = NULL;//Atribuindo NULL ao nó filho a direita
    *binaryTree= auxNewNode;//O conteudo do ponteiro recebe o endereço do novo nó
    printf("------------------------------------------\n");
    printf("VALOR INSERIDO\n");
    printf("------------------------------------------\n");
}

void printBinaryTree(BinaryTreeNode *binaryTree) {
    if(!binaryTree) return;
    printBinaryTree(binaryTree->left);
    printf("%d ", binaryTree->value);
    printBinaryTree(binaryTree->right);
}

int main()
{
    BinaryTreeNode *binaryTree = NULL;
    printf("%p\n", &binaryTree);
    int userValue;
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - IMPRIMIR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userValue);
        printf("------------------------------------------\n");
        switch(userValue) {
            case 1:
                int value;
                printf("------------------------------------------\n");
                printf("VALOR: ");
                scanf("%d", &value);
                printf("------------------------------------------\n");
                insertBinaryTree(&binaryTree, value);
                break;
            case 2:
                if(binaryTree)
                {
                    printf("------------------------------------------\n");
                    printBinaryTree(binaryTree);
                    printf("\n------------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            default:
                if(userValue != 0)
                {
                    printf("------------------------------------------\n");
                    printf("OPCAO INVALIDA\n");
                    printf("------------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------------\n");
                    printf("ARVORE FINALIZADA\n");
                    printf("------------------------------------------\n");
                }
                break;
        }
    } while(userValue != 0);
}
