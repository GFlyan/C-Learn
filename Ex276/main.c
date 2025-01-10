#include <stdio.h>
#include <stdlib.h>

//Exercício 276: Remover nó com dois filhos em uma Árvore Binária de Busca

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

int amountBinaryTreeNodes(BinaryTreeNode *binaryTree)
/*Função que retorna a quantidade de nós existentes em
uma árvore binária.

Recebe o endereço do nó raiz.*/
{
    int amount = 0;//Variável que diz respeito a quantidade de nós existentes na árvore
    if(!binaryTree) return amount;//Caso o ponteiro não tenha nenhum endereço de memória associdado, será retornado 0;
    else {
        amount += amountBinaryTreeNodes(binaryTree->left);//Recebe a a quantidade de nós existentes a esquerda
        amount += amountBinaryTreeNodes(binaryTree->right);//Recebe a a quantidade de nós existentes a direita
        return ++amount;//Retornando com acrescimo unitário a variável que contém a quantidade dos nós da árvore
    }
}

int amountLeafBinaryTreeNodes(BinaryTreeNode *binaryTree)
/*Função que retorna a quantidade de nós folhas existentes
em uma árvore binária.

Recebe como parâmetro o endereço do primeiro nó.*/
{
    if(!binaryTree) return 0;//Caso o ponteiro analisado seja nulo, será retornado 0
    else if(!(binaryTree->left) && !(binaryTree->right)) return 1;//Caso seja um nó folha
    else return amountLeafBinaryTreeNodes(binaryTree->left) + amountLeafBinaryTreeNodes(binaryTree->right);//Caso seja um nó que tenha filhos
}

BinaryTreeNode *removeBinaryTreeNode(BinaryTreeNode *binaryTree, int value)
/*Função que libera um nó folha, ou um nó com apenas um filho, ou um nó com
dois filhos.

Recebe o nó raiz e o valor contido no nó a ser removido.*/
{

    if(!binaryTree)
    /*Caso o ponteiro analisado não possua um endereço de memória atribuido*/
    {
        printf("VALOR NÃO ENCONTRADO\n");
        return NULL;//Retorna NULL para o ponteiro que executou a função
    }
    else if(binaryTree->value == value)
    //Caso o valor do nó analisado seja o valor em questão
    {
        if (!(binaryTree->left) && !(binaryTree->right))
        /*Caso o nó seja um nó folha*/
        {
            free(binaryTree);//Libera o endereço do nó
            printf("VALOR REMOVIDO\n");
            return NULL;//Retorna NULL para o ponteiro que executou a função
        }
        else
        /*Caso não seja um nó folha*/
        {
            if(binaryTree->left && binaryTree->right)
            /*Caso seja um nó com dois filhos*/
            {
                BinaryTreeNode **auxTravel = &(binaryTree->right), *auxNode;
                /*Criando um ponteiro pra ponteiro que recebe como conteudo o endereço
                do ponteiro do nó que possui o nó a direita do nó a ser removido que terá
                a função de percorrer a árvore binária.

                Definindo também um ponteiro que será */

                while((*auxTravel)->left)//Enquanto o próximo nó a esquerda existir
                    auxTravel = &((*auxTravel)->left);//O ponteiro recebe o endereço do ponteiro que contém o próximo nó a esquerda

                auxNode = *auxTravel;//Ponteiro auxiliar recebe o endereço de memória do nó com o menor dos maiores valores em relação ao nó a ser removido

                if((*auxTravel)->right) *auxTravel = (*auxTravel)->right;//Caso exista um nó filho a direita
                else *auxTravel = NULL;//Caso não exista um nó filho a direita

                auxNode->left = binaryTree->left;//Atribuindo os nós filhos a esquerda do nó a ser removido ao ponteiro
                auxNode->right = binaryTree->right;//Atribuindo os nós filhos a direita do nó a ser removido ao ponteiro
                free(binaryTree);//Liberando o nó a ser removido
                printf("NÓ SUBSTITUTO VALE: %d\n", auxNode->value);
                return auxNode;//Retornando o nó que irá substituir o nó a ser removido
            }
            else
            /*Caso seja um nó com apenas um filho*/
            {
                BinaryTreeNode *aux;//Definindo um ponteiro auxiliar que irá receber o endereço de memória referente ao nó filho
                if(binaryTree->left) aux = binaryTree->left;//Caso o nó filho seja o nó a esquerda
                else aux = binaryTree->right;//Caso o nó filho seja o nó a direita
                free(binaryTree);//Liberando o endereço de memória contido no ponteiro
                printf("VALOR REMOVIDO\n");
                return aux;//Retornando o endereço de memória referente ao nó filho para o ponteiro que executou a função
            }
        }
    }
    else
    /*Caso seja um nó com filhos*/
    {
        if(value < binaryTree->value) binaryTree->left = removeBinaryTreeNode(binaryTree->left, value);
        /*Caso o valor parametrado seja menor que o valor contido no nó, o nó a esquerda executará recursivamente a função parametrando o endereço contido nele mesmo*/
        else binaryTree->right = removeBinaryTreeNode(binaryTree->right, value);
        /*Caso o valor parametrado seja maior que o valor contido no nó, o nó a direita executará recursivamente a função parametrando o endereço contido nele mesmo*/
    }
        return binaryTree;//Retorna o endereço de memória parametrado
}

int main()
{
    BinaryTreeNode *binaryTree = NULL;//Criando um ponteiro e atribuindo NULL como endereço de memória
    int optionValue;//Criando uma variável que irá receber um valor informado pelo usuário
    do {
        printf("------------------------------------------\n");
        printf("\tOPCOES\n");
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - PROCURAR\n3 - MOSTRAR\n4 - ALTURA\n5 - QUANTIDADE DE NÓS\n6 - QUANTIDADE DE NÓS FOLHAS\n7 - REMOVER\n0 - SAIR\n");
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
            case 5:
                printf("------------------------------------------\n");
                printf("QUANTIDADE DE NÓS: %d\n", amountBinaryTreeNodes(binaryTree));//Acionando a função que retorna a quantidade de nós na árvore
                printf("------------------------------------------\n");
                break;
            case 6:
                printf("------------------------------------------\n");
                printf("QUANTIDADE DE NÓS FOLHAS: %d\n", amountLeafBinaryTreeNodes(binaryTree));//Acionando a função que retorna a quantidade de nós folhas na árvore
                printf("------------------------------------------\n");
                break;
            case 7:
                int removeLeafValue;
                printf("------------------------------------------\n");
                printf("REMOVA: ");
                scanf("%d", &removeLeafValue);
                printf("------------------------------------------\n");
                binaryTree = removeBinaryTreeNode(binaryTree, removeLeafValue);//Acionando a função que remove um nó
                printf("------------------------------------------\n");
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
