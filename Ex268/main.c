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

void printBinaryTree(BinaryTreeNode *binaryTree)
/*Procedimento que mostra os valores contidos em uma
árvore binária de forma crescente.*/
{
    if(!binaryTree) return;//Caso o conteudo do ponteiro analisado seja nulo
    printBinaryTree(binaryTree->left);//Chamada recursiva do nó mais a esquerda existente na árvore
    printf("%d ", binaryTree->value);//Mostra o valor do nó
    printBinaryTree(binaryTree->right);//Chamada recursiva do nó a direita de cada raiz
}

int main()
{
    BinaryTreeNode *binaryTree = NULL;//Criando um ponteiro e atribuindo NULL como endereço de memória
    printf("%p\n", &binaryTree);
    int userValue;//Criando uma variável que irá receber um valor informado pelo usuário
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - IMPRIMIR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userValue);//Atribuindo um valor fornecido pelo usuário
        printf("------------------------------------------\n");
        switch(userValue) {
            case 1:
                int value;//Criando uma variável que irá receber um valor informado pelo usuário
                printf("------------------------------------------\n");
                printf("VALOR: ");
                scanf("%d", &value);//Atribuindo um valor fornecido pelo usuário
                printf("------------------------------------------\n");
                insertBinaryTree(&binaryTree, value);//Acionando o procedimento que insere um novo valor na árvore binária
                break;
            case 2:
                if(binaryTree)
                /*Caso a árvore tenha pelo menos um nó*/
                {
                    printf("------------------------------------------\n");
                    printBinaryTree(binaryTree);//Acionando o procedimento que mostra todos os valores contidos na árvore binária de forma crescente
                    printf("\n------------------------------------------\n");
                }
                else
                /*Caso não tenha nenhum nó na árvore*/
                {
                    printf("------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            default:
                if(userValue != 0)
                /*Caso o valor fornecido pelo usuário seja um valor inválido*/
                {
                    printf("------------------------------------------\n");
                    printf("OPCAO INVALIDA\n");
                    printf("------------------------------------------\n");
                }
                else
                /*Caso o usuário forneça o valor 0*/
                {
                    printf("------------------------------------------\n");
                    printf("ARVORE FINALIZADA\n");
                    printf("------------------------------------------\n");
                }
                break;
        }
    } while(userValue != 0);//Realizar enquanto o usuário não fornecer o valor 0
}
