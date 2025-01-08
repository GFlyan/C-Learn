#include <stdio.h>
#include <stdlib.h>

//Exercício 265: Inserção em Árvore Binária - 1ª VERSÃO

typedef struct nodeBinaryTree
/*Criando uma estrutura que diz respeito
à composição dos nós de uma árvore binária*/
{
    int value;//Campo que diz respeito ao valor
    struct nodeBinaryTree *left, *right;//Campos que dizem respeito respectivamente aos endereços do nó a esquerda e do nó a direita
}NodeBinaryTree;

NodeBinaryTree* insertBinaryTree(NodeBinaryTree *binaryTree, int value)
/*Função que insere um novo nó na árvore binária, caso não exista
nenhum nó é inserido o primeiro novo, ou seja, o nó raiz, sendo
posteriormente inserido os nós filhos a cada chamada da função
insertBinaryTree.

Recebe como parâmetro o endereço de memória do nó raiz e o valor a ser
inserido.*/
{
    if(!binaryTree)
    /*Caso o nó analizado não exista, será criado um novo nó para inserção do valor na árvore*/
     {
        binaryTree = malloc(sizeof(NodeBinaryTree));//Alocando memória para o nó, fazendo assim com que ele exista
        binaryTree->left = NULL;//Atribuindo NULL como endereço para o nó filho a esquerda
        binaryTree->right = NULL;//Atribuindo NULL como endereço para o nó filho a direita
        binaryTree->value = value;//Atribuindo o valor do nó
        printf("--------------------------------------------\n");
        printf("VALOR INSERIDO\n");
        printf("--------------------------------------------\n");
        return binaryTree;//Retornando para o ponteiro passado como parâmetro um novo conteúdo, sendo um endereço de memória
    } else
    /*Caso o nó analisado exista*/
    {
        if(value < binaryTree->value) binaryTree->left = insertBinaryTree(binaryTree->left, value);
        /*Caso o valor parametrado seja menor que o valor contido no nó, ele será inserido em um nó a esquerda*/
        else binaryTree->right = insertBinaryTree(binaryTree->right, value);
        /*Caso o valor parametrado seja maior que o valor contido no nó, ele será inserido em um nó a direita*/
        return binaryTree; //Retornando a modificação feita na árvore para o nó raiz
    }
}

void printBinaryTree(NodeBinaryTree *binaryTree)
/*Procedimento que imprime os valores contidos
em uma árvore binária.

Recebe como parâmetro o endereço do nó raiz.*/
{
    if(binaryTree)
    /*Caso o nó fornecido não esteja vazio*/
    {
        printBinaryTree(binaryTree->left);//Chamada recursiva da fuñção para imprimir a partir do nó mais a esquerda
        printf("%d ", binaryTree->value);//Impressão do valor contido no nó
        printBinaryTree(binaryTree->right);//Chamada recursiva para imprimir um nó a direita após imprimir um nó a esquerda
    }
}

int main() {
    NodeBinaryTree *binaryTree = NULL;//Atribuindo NULL como endereço de memória
    int userValue;//Definindo uma variável que será atribuido um valor fornecido pelo usuário
    do {
        printf("--------------------------------------------\n");
        printf("1 - INSERIR\n2 - IMPRIMIR\n0 - SAIR\n");
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
                binaryTree = insertBinaryTree(binaryTree, value);//Acionando a função que insere um novo valor na árvore binária
                break;
            case 2:
                if(binaryTree)
                //Caso exista nós na árvore
                {
                    printf("--------------------------------------------\n");
                    printBinaryTree(binaryTree);//Acionando o procedimento que mostra os valores contidos na árvore binária
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
