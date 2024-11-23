#include <stdio.h>
#include <stdlib.h>

/*
Exercício 243: Inserindo no início de uma lista encadeada

Inserção em uma lista:

-Início
-Meio
-Fim

A inserção em uma lista pode ser em qualquer posição
*/

int insertValueNode()
{
    int value;
    printf("Insira um valor na lista: ");
    scanf("%d", &value);
    return value;
}
typedef struct node{//Criando um nó pra cada elemento da lista encadeada
    int value;
    struct node *nextNode;//Cada nó precisa de um ponteiro pro nó seguinte
}Node;

void insertBeggining(Node **linkedList )
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode)
    {
        newNode->value = insertValueNode();
        if(*linkedList)
        {
            newNode->nextNode = *linkedList;
            *linkedList = newNode;
        }
        else//Caso a lista esteja vazia
        {
            newNode->nextNode = NULL;
            *linkedList = newNode;
        }
    }


}

void insertEnd(Node **linkedList)
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode)
    {
        newNode->value = insertValueNode();
        newNode->nextNode = NULL;
        if(*linkedList)
        {
            Node *aux = *linkedList;
            while(aux->nextNode)
                aux = aux->nextNode;

            aux->nextNode = newNode;
        }
        else

            *linkedList = newNode;
    }
}

void insertMid(Node **linkedList, int afterValue)
{
    Node *newNode = malloc(sizeof(Node));

    if(newNode)
    {
        if(*linkedList)
        {
            Node *aux = *linkedList;
            while(aux->value != afterValue && aux->nextNode)
                aux = aux->nextNode;

            if(aux->value == afterValue)
            {
                newNode->value = insertValueNode();
                newNode->nextNode = aux->nextNode;
                aux->nextNode = newNode;
            }
            else
                printf("Valor informado não encontrado na lista\n");
        }
        else
        {
            newNode->value = insertValueNode();
            newNode->nextNode = NULL;
            *linkedList = newNode;
        }
    }
}

void printLinkedList(Node *linkedList)
{
    if(linkedList)
    {
        printf("%d\n", linkedList->value);
        printLinkedList(linkedList->nextNode);
    }
}

int main()
{
    Node *linkedList = NULL;
    int userValue;

    do{
        printf("------------------------------------------\n");
        printf("1 - Inserir no Início\n2 - Inserir no Meio\n3 - Inserir no Final\n4 - Imprimir Lista\n0 - Sair\n");
        printf("------------------------------------------\n");
        printf("Inserir: ");
        scanf("%d", &userValue);

        switch(userValue)
        {
            case 1:
                printf("------------------------------------------\n");
                insertBeggining(&linkedList);
                printf("------------------------------------------\n");
                break;

            case 2:
                    if(linkedList)
                    {
                        printf("------------------------------------------\n");
                        int afterValue;
                        printf("Deseja inserir depois de qual valor: ");
                        scanf("%d", &afterValue);
                        printf("------------------------------------------\n");
                        insertMid(&linkedList, afterValue);
                        printf("------------------------------------------\n");
                    }
                    else
                    {
                        printf("------------------------------------------\n");
                        printf("Lista vazia, insira sem ser no meio.\n");
                        printf("------------------------------------------\n");
                    }

                break;
            case 3:
                printf("------------------------------------------\n");
                insertEnd(&linkedList);
                printf("------------------------------------------\n");
                break;
            case 4:
                if(linkedList)
                {
                    printf("------------------------------------------\n");
                    printLinkedList(linkedList);
                    printf("------------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------------\n");
                    printf("Lista vazia.\n");
                    printf("------------------------------------------\n");
                }
                break;
            default:
                if(userValue!=0)
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
    while(userValue != 0);

    return 0;
}
