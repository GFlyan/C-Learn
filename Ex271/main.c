#include <stdio.h>
#include <stdlib.h>

//Exercício 271: Altura de uma Árvore Binária de Busca

typedef struct binaryTreeNode
/*Criando uma estrutura que diz respeito
à composição dos nós de uma árvore binária*/
{
    int value;//Campo que diz respeito ao valor
    struct binaryTreeNode *left, *right;//Campos que dizem respeito respectivamente aos endereços do nó a esquerda e do nó a direita
}BinaryTreeNode;

BinaryTreeNode* insertBinaryTree(BinaryTreeNode *binaryTree, int value)
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
        binaryTree = malloc(sizeof(BinaryTreeNode));//Alocando memória para o nó, fazendo assim com que ele exista
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


BinaryTreeNode *searchValueBinaryTree(BinaryTreeNode *binaryTree, int value)
/*Funçao que procura se um elemento existe na árvore binária, recebe
como parâmetros o endereço do primeiro nó da árvore binária
e o valor a ser procurado.

Utiliza recursão.*/
{
    if(!binaryTree) return NULL;//Caso o valor do ponteiro analisado seja nulo
    else if(value == binaryTree->value) return binaryTree;//Caso o valor seja encontrado na árvore binária
    else {
        if(value < binaryTree->value) return searchValueBinaryTree(binaryTree->left, value);//Caso o valor seja menor que o valor do nó, será realizada a chamada recursiva para o nó a esquerda
        else return searchValueBinaryTree(binaryTree->right, value);//Caso o valor seja maior que o valor do nó, será realizada a chamada recursiva para o nó a direita
    }
}

void printBinaryTree(BinaryTreeNode *binaryTree)
/*Procedimento que imprime os valores contidos
em uma árvore binária de forma crescente.

Recebe como parâmetro o endereço do nó raiz.*/
{
    if(!binaryTree) return;
    /*Caso o nó fornecido não esteja vazio*/
    printBinaryTree(binaryTree->left);//Chamada recursiva da fuñção para imprimir a partir do nó mais a esquerda
    printf("%d ", binaryTree->value);//Impressão do valor contido no nó
    printBinaryTree(binaryTree->right);//Chamada recursiva para imprimir um nó a direita após imprimir um nó a esquerda
}

int heightBinaryTree(BinaryTreeNode *binaryTree)
/*Função que calcula o tamanho de uma árvore binária.

Caso a árvore esteja vazia, será retornado -1.*/
{
    if(!binaryTree) return -1;//Caso o ponteiro analisado esteja vazio
    else
    /*Caso o ponteiro analisaod não esteja vazio*/
    {
        int left = heightBinaryTree(binaryTree->left);//Criando uma variável que recebe o retorno da chamada recursiva da função para o nó a esquerda
        int right = heightBinaryTree(binaryTree->right);//Criando uma variável que recebe o retorno da chamada recursiva da função para o nó a direita
        if(left>right) return left+1;//Caso a subárvore a esquerda seja maior que a subárvore a direita
        else return right+1;//Caso a subárvore a direita seja maior ou igual que a subárvore a esquerda
    }
}

int main()
{
    BinaryTreeNode *binaryTree = NULL;//Criando um ponteiro e atribuindo NULL como endereço de memória
    int optionValue;//Criando uma variável que irá receber um valor informado pelo usuário
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - PROCURAR\n3 - MOSTRAR\n4 - ALTURA\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &optionValue);//Atribuindo um valor fornecido pelo usuário
        printf("------------------------------------------\n");
        switch(optionValue) {
            case 1:
                int insertValue;//Criando uma variável que irá receber um valor informado pelo usuário
                printf("------------------------------------------\n");
                printf("VALOR: ");
                scanf("%d", &insertValue);//Atribuindo um valor fornecido pelo usuário
                printf("------------------------------------------\n");
                binaryTree = insertBinaryTree(binaryTree, insertValue);//Acionando o procedimento que insere um novo valor na árvore binária
                break;
            case 2:
                if(binaryTree)
                /*Caso a árvore tenha pelo menos um nó*/
                {
                    int searchValue;//Definindo uma variável que receberá um valor informado pelo usuário
                    printf("------------------------------------------\n");
                    printf("PROCURE: ");
                    scanf("%d", &searchValue);//Atribuindo um valor fornecido pelo usuário à uma variável
                    printf("------------------------------------------\n");
                    BinaryTreeNode *aux = searchValueBinaryTree(binaryTree, searchValue);//Criando um ponteiro que vai receber o retorno da função da busca de um valor na árvore binária
                    aux ? printf("VALOR ENCONTRADO\n") : printf("VALOR NÃO ENCONTRADO\n");
                    printf("------------------------------------------\n");
                } else
                /*Caso não tenha nenhum nó na árvore*/
                {
                    printf("------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            case 3:
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
            case 4:
                if(binaryTree){
                    printf("------------------------------------------\n");
                    printf("ALTURA: %d\n", heightBinaryTree(binaryTree));//Acionando o procedimento que retorna o tamanho da árvore
                    printf("------------------------------------------\n");
                } else {
                    printf("------------------------------------------\n");
                    printf("ARVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            default:
                if(optionValue)
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
    } while(optionValue);//Realizar enquanto o usuário não fornecer o valor 0
}
