#include <stdio.h>
#include <stdlib.h>

/*
Exercício 246: Todos os tipos de inserção em uma lista encadeada
*/

typedef struct node
/*
Estrutura que diz respeito a um nó,
tendo um campo referente ao valor
desse nó, e um campo referente ao
próximo nó
*/
{
    int value;//Campo que diz respeito ao valor do nó
    struct node *nextNode;//Campo que diz respeito ao endereço do próximo nó
}Node;

void insertBegin(Node **linkedList)
/*
Procedimento que insere no início de uma
lista encadeada um nó.

Recebe como parâmetro o endereço da fila,
que contém o endereço dos outros nós.
*/
{
    Node *newNode = malloc(sizeof(Node));//Criando um novo nó e alocando memória
    if(newNode)//Caso a alocação de memória tenha dado certo
    {
        newNode->value = insertValue();//Novo nó recebe um valor
        newNode->nextNode = *linkedList;/*Próximo nó do novo nó recebe o primeiro
                                          nó da lista, caso esteja vazia, receberá
                                          vazio*/

        *linkedList = newNode;/*Lista recebe o novo nó como primeiro nó*/
    }
}


void insertMid(Node **linkedList, int value)
/*
Procedimento que insere um nó no meio
da lista encadeada após um nó com
determinado valor.

Caso o valor não exista na lista, o nó
será inserido no final da lista.

Caso a lista esteja vazia, será inserido
como primeiro nó.

Recebe como parâmetro o endereço da lista
e o valor que diz respeito ao nó cujo
novo nó será inserido posterior a ele.
*/
{
    Node *newNode = malloc(sizeof(Node));//Criando um ponteiro que diz respeito ao novo nó e alocando memória
    if(newNode)//Caso a alocação de certo
    {
        newNode->value = insertValue();//Inserindo um valor para o novo nó
        if(*linkedList)//Caso a lista não esteja vazia
        {
            Node *aux = *linkedList;//Criando um ponteiro que recebe o primeiro nó para percorrer a lista
            while((aux->value != value) && (aux->nextNode))/*Percorrendo a lista até encontrar o nó
                                                             cujo valor é o valor informado, ou até
                                                             chegar no último nó*/
                aux = aux->nextNode;//Percorrendo de nó em nó

            newNode->nextNode = aux->nextNode;/*O próximo nó do novo nó recebe o próximo nó
                                                do nó cujo valor foi informado, ou do último
                                                nó caso o nó cujo valor foi informado não
                                                exista*/
            aux->nextNode = newNode;//Próximo nó do ponteiro de percursão recebe o novo nó

        }
        else//Caso a lista esteja vazia
        {
            newNode->nextNode = *linkedList;//O próximo nó do novo nó recebe NULL
            *linkedList = newNode;//O início da lista recebe o novo nó
        }
    }
}

void insertEnd(Node **linkedList)
/*
Procedimento que insere no final da lista,
caso não exista nenhum elemento na lista
será criado o primeiro nó.

Recebe como parâmetro o endereço da lista.
*/
{
    Node *newNode = malloc(sizeof(Node));//Criando um ponteiro que diz respeito ao novo nó e alocando memória
    if(newNode)//Caso a alocação tenha dado certo
    {
        newNode->value = insertValue();//Inserindo um valor para o novo nó
        newNode->nextNode = NULL;//Próximo nó do novo nó recebe NULL, pois será o último nó

        if(*linkedList)//Caso a lista tenha elementos
        {
            Node *aux = *linkedList;//Criando um ponteiro que recebe o primeiro nó da lista
            while(aux->nextNode)//Percorrendo a lista até encontrar o último nó
                aux = aux->nextNode;//Percorrendo de nó em nó

            aux->nextNode = newNode;//Próximo nó do último nó da lista recebe o novo nó
        }
        else//Caso a lista esteja vazia
            *linkedList = newNode;//Inicio da lista recebe o novo nó como primeiro nó
    }
}

int insertValue()
/*
Funçã que pede ao usuário um valor
inteiro e retorna esse valor.
*/
{
    int value;//Definindo uma variável que irá receber um valor informado pelo usuário
    printf("---------------------------------\n");
    printf("Insira um Valor: ");
    scanf("%d", &value;//Atribuindo valor informado pelo usuário
    printf("---------------------------------\n");
    return value;//Retorna o valor informado pelo usuário
}

void printLinkedList(Node *linkedList)
/*
Procedimento que mostra todos os elementos
da lista.

Recebe como parâmetro o primeiro nó.

Os demais valores dos outros nós
são mostrados por chamadas recursivas
da própria função recebendo como parâmetro
os próximos nós de cada nó até chegar no
último nó cujo próximo nó é NULL.
*/
{
    if(linkedList)//Caso exista um nó - PONTO DE PARADA
    {
        printf("%d\n", linkedList->value);//Mostrando o valor de cada nó
        printLinkedList(linkedList->nextNode);//Chamada recursiva de nó em nó
    }
}

int main()
{
    Node *linkedList = NULL;//Criando um ponteiro que diz respeito a uma lista encadeada
    int userValue;//Variável que diz respeito as opções principais do programa

    do//Fazer até o usuário finalizar o programa
    {
        printf("---------------------------------\n");
        printf("1 - Inserir no Início\n2 - Inserir no Meio\n3 - Inserir no Final\n4 - Imprimir Lista\n0 - Sair\n");
        printf("---------------------------------\n");
        printf("Insira: ");
        scanf("%d", &userValue);//Atribuindo valor informado pelo usuário
        switch(userValue)//Escolha do usuário
        {
            case 1:
                insertBegin(&linkedList);//Acionando procedimento que insere no início da lista
                printf("Elemento Adicionado.\n");
                printf("---------------------------------\n");
                break;
            case 2:
                int value;//Variável que diz respeito a inserção de um nó após certo valor de um nó
                printf("---------------------------------\n");
                printf("Inserir Após: ");
                scanf("%d", &value);//Atribuindo o valor do nó informado pelo usuario
                printf("(caso o valor não seja encontrado, a inserção será no final da lista)\n");
                insertMid(&linkedList, value);//Acionando o procedimento que insere no meio da lista
                printf("Elemento Adicionado.\n");
                printf("---------------------------------\n");
                break;
            case 3:
                insertEnd(&linkedList);//Acionando o procedimento que insere no fim da lista
                printf("Elemento Adicionado.\n");
                printf("---------------------------------\n");
                break;
            case 4:
                if(linkedList)//Caso a lista tenha elementos
                {
                    printf("---------------------------------\n");
                    printLinkedList(linkedList);//Acionando procedimento que informa cada valor da lista
                    printf("---------------------------------\n");
                }
                else//Caso não tenha elementos na lista
                {
                    printf("---------------------------------\n");
                    printf("Lista Vazia.\n");
                    printf("---------------------------------\n");
                }
                break;
            default:
                if(userValue != 0)//Caso o usuário escolha uma opção inválida
                {
                    printf("---------------------------------\n");
                    printf("Opção Inválida.\n");
                    printf("---------------------------------\n");
                }
                else//Caso o usuário finalize o programa
                {
                    printf("---------------------------------\n");
                    printf("Lista Finalizada.\n");
                    printf("---------------------------------\n");
                }
                break;
        }
    }
    while(userValue != 0);//PONTO DE PARADA
    return 0;
}
