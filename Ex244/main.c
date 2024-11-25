#include <stdio.h>
#include <stdlib.h>

/*
Exercício 244: Inserindo no final em uma lista encadeada
*/

int insertIntegerValue()
/*
Criando uma função que pede pro
usuário pra que ele informe um valor
para o nó e retorna esse valor para o
campo valor do nó.
*/
{
    int value;//Criando uma variável que irá receber o valor informado pelo usário.
    printf("Informe um valor para o nó: ");
    scanf("%d", &value);//Usuário atribui um valor.
    return value;//Retornando o valor do nó.
}

typedef struct node
/*
Criando uma estrutura que diz respeito a um
nó para estruturas de dados dinâmicas, onde
possui dois campos, um para valor e outro
para o endereço do próximo nó.
*/
{
    int value;//Campo que diz respeito ao valor do nó.
    struct node *nextNode;//Campo que diz respeito ao endereço de memória do próximo nó.
}Node;

void insertEnd(Node **linkedList)
/*
Procedimento que insere elementos no final
de uma lista encadeada, caso a opção
seja executada e não exista nenhum elemento
na lista ainda, será adicionado 1 elemento
no inicio.

Recebe como parâmetro o endereço de memória
do ponteiro que armazena o endereço do
primeiro nó da lista encadeada.
*/
{
    Node *newNode = malloc(sizeof(Node));//Criando um ponteiro que diz respeito ao novo nó e alocando memória
    if(newNode)//Caso a alocação de memória de certo
    {
        newNode->value = insertIntegerValue();//Atribuindo um valor pro campo valor do nó
        newNode->nextNode = NULL;//Por se tratar de uma inserção como último nó, o próximo nó do novo nó não irá existir
        if(*linkedList)//Caso já tenha elementos na lista
        {
            Node *aux = *linkedList;//Criando um ponteiro auxiliar que recebe o primeiro nó
            while(aux->nextNode)//Percorrendo até chegar no último nó
                aux = aux->nextNode;//Atribuindo os próximos nós de cada nó até chegar no último nó
            aux->nextNode = newNode;//O campo próximo nó do último nó recebe o novo nó
        }
        else//Caso a lista esteja vazia
            *linkedList = newNode;//O primeiro nó da lista recebe o novo nó
    }

}

void printLinkedList(Node *linkedList)
/*
Procedimento que informa cada elemento
da lista caso existam elementos na lista.

Recebe como parâmetro o nó inicial.

Funciona por chamadas recursivas até o último
elemento da lista.
*/
{
    if(linkedList)//Caso o nó exista. - PONTO DE PARADA
    {
        printf("%d\n", linkedList->value);//Mostrando cada valor da lista.
        printLinkedList(linkedList->nextNode);//Chamada recuriva utilizando os próximos nós como parâmetro.
    }
}


int main()
{
    Node *linkedList = NULL;//Criando um ponteiro que diz respeito a uma lista encadeada
    int userValue;//Criando uma variável que irá receber um valor fornecido pelo usuário

    do//Enquanto o usuário não desejar sair da lista encadeada
    {
        printf("--------------------------------\n");
        printf("1 - Inserir no final\n2 - Imprimir\n0 - Sair\n");
        printf("--------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userValue);//Usuário fornece um valor
        switch(userValue)//Executar conforme a escolha do usuário
        {
            case 1:
                printf("--------------------------------\n");
                insertEnd(&linkedList);//Acionando o procedimento que adiciona um nó novo no final da lista encadeada
                printf("--------------------------------\n");
                printf("Elemento adicionado.\n");
                printf("--------------------------------\n");
                break;
            case 2:
                if(linkedList)//Caso existam elementos na lista encadeada
                {
                    printf("--------------------------------\n");
                    printLinkedList(linkedList);//Mostrando cada valor na lista encadeada
                    printf("--------------------------------\n");
                }
                else//Caso a lista encadeada esteja vazia
                {
                    printf("--------------------------------\n");
                    printf("Lista vazia.\n");
                    printf("--------------------------------\n");
                }
                break;
            default:
                if(userValue != 0)//Caso o usuário tenha fornecido uma opção inválida
                {
                    printf("--------------------------------\n");
                    printf("Opção inválida.\n;");
                    printf("--------------------------------\n");
                }
                else//Caso o usuário queira fechar o programa
                {
                    printf("--------------------------------\n");
                    printf("Finalizando lista encadeada.");
                    printf("--------------------------------\n");
                }
                break;
        }
    }
    while(userValue != 0);
    return 0;
}
