#include <stdio.h>
#include <stdlib.h>

/*
Exercício 245: Inserindo no meio de uma lista encadeada

A inserção pode ser feita no final também
*/

int insertValueNode()
/*
Funçao que pergunta um valor inteiro ao usuário e
retorna ele a uma variável.
*/
{
    int value;//Definindo uma variável inteira que irá receber um valor
    printf("Insira um valor na lista: ");
    scanf("%d", &value);//Armazenando o valor fornecido pelo usuário
    return value;//Retornando o valor para o usuário
}
typedef struct node
/*
Estrutura que diz respeito a um nó,
onde o primeiro campo diz respeito
ao valor desse nó e o segundo ao
endereço de memória do próximo nó.
*/
{
    int value;//Valor do nó
    struct node *nextNode;//Endereço de memória do próximo nó
}Node;


void insertMid(Node **linkedList, int value)
/*
Procedimento que diz respeito a inserção
de um nó no meio de uma lista encadeada,
o endereço da lista é passado como parâmetro
para que seja possível acessar os nós e
os conteúdos de cada nó.

Recebe um valor como parâmetro também, onde
a inserção do novo nó será feito em um nó
após o que tiver o nó com o valor informado.

Caso não haja nenhum nó com o valor informado
o novo nó será inserido no final da lista encadeada.
*/
{
    Node *newNode = malloc(sizeof(Node));//Criando um nov nó e alocando memória
    if(newNode)//Caso a alocação de memória de certo
    {
        newNode->value = insertValueNode();//Inserindo um novo valor ao nó

        if(*linkedList)//Caso a lista não esteja vazia
        {
            Node *aux = *linkedList;//Criando um ponteiro auxiliar que recebe o primeiro nó

            while((aux->value != value) && (aux->nextNode))/*Percorrendo a lista a procura do nó
                                                             que contém o valor informado ou até
                                                             o último nó*/

                aux = aux->nextNode;//Percorrendo a lista de nó em nó
            if(aux->value == value)//Caso tenha sido encontra o nó que contém o valor informado
                newNode->nextNode = aux->nextNode;/*O próximo nó do novo nó recebe o
                                                    próximo nó do nó que contém o valor
                                                    informado*/
            else//Caso o valor não tenha sido encontrado e a percursão da lista tenha chegado ao fim
                newNode->nextNode = NULL;/*O próximo nó do novo nó recebe null
                                           pois será inserido no final da lista*/
            aux->nextNode = newNode;//O nó que teve ponto de parada recebe então o novo nó
        }
        else//Caso a lista esteja vazia
        {
            newNode->nextNode = *linkedList;//O novo nó recebe o valor da lista NULL
            *linkedList = newNode;//O inicio da lista recebe o novo nó
        }
    }
}

void printLinkedList(Node *linkedList)
/*
Procedimento que mostra cada elemento da lista.

Recebe como parâmetro o endereço do primeiro nó.

Chamadas recursivas são feitas até o último nó
para que mostre o valor de cada nó.
*/
{
    if(linkedList)//Caso exista elemento no nó - PONTO DE PARADA
    {
        printf("%d\n", linkedList->value);
        printLinkedList(linkedList->nextNode);//Chamada recursiva de nó em nó
    }
}

void insertTwoNodes(Node **linkedList)
/*
Procedimento que insere dois nós na lista
encadeada.

Recebe como parâmetro o endereço da lista.
*/
{
    Node *firstNode = malloc(sizeof(Node));//Criando o primeiro nó e alocando memória
    firstNode->value = 0;//Definindo 0 como valor do priemiro nó
    Node *secondNode = malloc(sizeof(Node));//Criando o segundo nó e alocando memória
    secondNode->value = 999;//Definindo 999 como valor do segundo nó
    firstNode->nextNode = secondNode;//O próximo nó do primeiro nó recebe o endereço do segundo
    secondNode->nextNode = NULL;//O próximo nó do segundo recebe NULL pois será o último
    *linkedList = firstNode;//A lista recebe o primeiro nó
}

int main()
{
    Node *linkedList = NULL;//Criando um ponteiro que diz respeito a uma lista encadeada
    insertTwoNodes(&linkedList);/*Inserindo dois nós na lista, um
                                  no inicio cujo valor é 0 e um
                                  no final cujo valor é 999*/

    int userValue;//Definindo uma variável que irá armazenar um valor informado pelo usuário
    printf("------------------------------------------\n");
    printf("Primeiro valor da lista: 0\nÚtimo valor da lista: 999\n");
    printf("**O último valor pode ser alterado.\n");
    printf("------------------------------------------\n");

    do{
        printf("------------------------------------------\n");
        printf("1 - Inserir no Meio\n2 - Imprimir Lista\n0 - Sair\n");
        printf("------------------------------------------\n");
        printf("Inserir: ");
        scanf("%d", &userValue);//Atribuindo um valor informado pelo usuário

        switch(userValue)//Escolha do usuário
        {

            case 1:
                        printf("------------------------------------------\n");
                        printf("Deseja inserir depois de qual valor: ");
                        int value;//Definindo uma variável que irá receber um valor informado pelo usuário
                        scanf("%d", &value);/*Usuário atribui um valor que diz
                                                  respeito ao valor contido no nó
                                                  qual será posto um novo nó após
                                                  ele*/
                        printf("------------------------------------------\n");
                        insertMid(&linkedList, value);//Acionando o procedimento que insere um elemento no meio da lista encadeada
                        printf("------------------------------------------\n");
                break;
            case 2:

                    printf("------------------------------------------\n");
                    printLinkedList(linkedList);//Acionando o procedimento que mostra os elementos da lista encadeada
                    printf("------------------------------------------\n");

                break;
            default:
                if(userValue!=0)//Caso o usuário forneça uma opção inválida
                {
                    printf("------------------------------------------\n");
                    printf("Opção inválida.\n");
                    printf("------------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------------\n");
                    printf("Lista finalizada.\n");
                    printf("------------------------------------------\n");
                }
                break;
        }
    }
    while(userValue != 0);//Ponto de parada

    return 0;
}

