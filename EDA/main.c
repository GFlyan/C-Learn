#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *nextNode;
}Node;

//USEFULL FUNCTIONS

int insertIntegerValue(){
    int value;
    printf("---------------------------------------------\n");
    printf("INFORME UM VALOR: ");
    scanf("%d", &value);
    printf("---------------------------------------------\n");
    return value;
}

void printData(Node *data)
{
    if(data)
    {
        printf("%d\n", data->value);
        printData(data->nextNode);
    }
}

void printInserted(){
    printf("---------------------------------------------\n");
    printf("ELEMENTO INSERIDO.\n");
    printf("---------------------------------------------\n");
}

void printRemoved(){
    printf("---------------------------------------------\n");
    printf("ELEMENTO REMOVIDO.\n");
    printf("---------------------------------------------\n");
}

void printInvalid(){
    printf("---------------------------------------------\n");
    printf("OPCAO INVALIDA\n");
    printf("---------------------------------------------\n");
}


//*********PILHA*********
// LIFO - LAST IN FIRST OUT
// INSERÇÃO/REMOÇÃO: TOPO

void insertHeap(Node **top){
    Node *newNode = malloc(sizeof(Node));
    if(newNode)
    {
            newNode->value = insertIntegerValue();
            newNode->nextNode = *top;
            *top = newNode;
            printInserted();
    }
}


void removeHeap(Node **top){
    if(*top){
        Node *removed = *top;
        *top = removed->nextNode;
        printRemoved();
    }
    else{
        printf("---------------------------------------------\n");
        printf("PILHA VAZIA\n");
        printf("---------------------------------------------\n");
    }
}

//*********FILA*********
//FIFO - FIRST IN FIRST OUT
//INSERÇÃO: FIM
//REMOÇÃO: INICIO

void insertLine(Node **line){
    Node *newNode = malloc(sizeof(Node));
    if (newNode){
        newNode->value = insertIntegerValue();
        newNode->nextNode = NULL;
        if(*line){
            Node *aux = *line;
            while(aux->nextNode)
                aux = aux->nextNode;

            aux->nextNode = newNode;
        }
        else
            *line = newNode;
        printInserted();
    }
}

void removeLine(Node **line){
    if(*line){
        Node *removed = *line;
        *line = removed->nextNode;
        printRemoved();
    }
    else{
        printf("---------------------------------------------\n");
        printf("FILA VAZIA\n");
        printf("---------------------------------------------\n");
    }
}


//*********LISTA*********
//
//INSERÇÃO/REMOÇÃO: INÍCIO/MEIO/FIM

void insertBeginLinkedList(Node **linkedList){
    Node *newNode = malloc(sizeof(Node));
    if(newNode){
        newNode->value = insertIntegerValue();
        newNode->nextNode = *linkedList;
        *linkedList = newNode;
        printInserted();
    }
}

void insertMidLinkedList(Node **linkedList, int value){
    Node *newNode = malloc(sizeof(Node));
    if(newNode){
        newNode->value = insertIntegerValue();
        if(*linkedList)
        {
            Node *aux = *linkedList;
            while(aux->value != value && aux->nextNode)
                aux = aux->nextNode;

            newNode->nextNode = aux->nextNode;
            aux->nextNode = newNode;
        }
        else
        {
            newNode->nextNode = NULL;
            *linkedList = newNode;
        }
        printInserted();
    }
}

void insertEndLinkedList(Node **linkedList){
    Node *newNode = malloc(sizeof(Node));
    if(newNode){
        newNode->value = insertIntegerValue();
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
        printInserted;
    }
}

void removeBeginLinkedList(Node **linkedList){
    if(*linkedList)
    {
        Node *removed = *linkedList;
        *linkedList = removed->nextNode;
        printRemoved();
    }
    else{
        printf("---------------------------------------------\n");
        printf("LISTA VAZIA\n");
        printf("---------------------------------------------\n");
    }
}

void removeMidLinkedList(Node **linkedList, int value){
    if(*linkedList){
        Node *aux = *linkedList;
        int count = 0;
        while(aux->value != value && aux->nextNode){
            aux = aux->nextNode;
            count++;
        }

        if(aux->value == value){
            Node *removed = aux;

            if(count >= 1){
                aux = *linkedList;
                for(int i = 0; i < count-1; i++)
                    aux = aux->nextNode;
                aux->nextNode = removed->nextNode;
            }
            else
                *linkedList = removed->nextNode;
            printRemoved();
        }
        else{
            printf("---------------------------------------------\n");
            printf("VALOR NAO ENCONTRADO NA LISTA\n");
            printf("---------------------------------------------\n");
        }

    }
    else{
        printf("---------------------------------------------\n");
        printf("LISTA VAZIA\n");
        printf("---------------------------------------------\n");
    }
}

void removeEndLinkedList(Node **linkedList){
    if(*linkedList){
        Node *aux = *linkedList;
        int count = 0;
        while(aux->nextNode){
            aux = aux->nextNode;
            count++;
        }
        Node *removed = aux;

        if(count >= 1){
            aux = *linkedList;
            for(int i = 0 ; i < count-1; i++)
            {
                aux = aux->nextNode;
            }

             aux->nextNode = removed->nextNode;
        }
        else
            *linkedList = removed->nextNode;
        printRemoved();
    }
    else{
        printf("---------------------------------------------\n");
        printf("LISTA VAZIA\n");
        printf("---------------------------------------------\n");
    }
}


int main()
{
    int userProgram;
    do{
        int userValue;
        printf("---------------------------------------------\n");
        printf("1 - PILHA\n2 - FILA\n3 - LISTA\n0 - SAIR\n");
        printf("---------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userProgram);
        switch(userProgram)
        {
            case 1:
                Node *heap = NULL;
                do{
                    printf("---------------------------------------------\n");
                    printf("1 - INSERIR NA PILHA\n2 - REMOVER NA PILHA\n3 - IMPRIMIR\n0 - SAIR\n");
                    printf("---------------------------------------------\n");
                    printf("INSIRA: ");
                    scanf("%d", &userValue);

                    switch(userValue){
                        case 1:
                            insertHeap(&heap);
                            break;
                        case 2:
                            removeHeap(&heap);
                            break;
                        case 3:
                            if(heap){
                                printf("---------------------------------------------\n");
                                printf("PILHA:\n\n");
                                printData(heap);
                                printf("---------------------------------------------\n");
                            }
                            else{
                                printf("---------------------------------------------\n");
                                printf("PILHA VAZIA\n");
                                printf("---------------------------------------------\n");
                            }
                            break;
                        default:
                            if(userValue != 0)
                                printInvalid();
                            else{
                                printf("---------------------------------------------\n");
                                printf("PILHA FINALIZADA\n");
                                printf("---------------------------------------------\n");
                            }
                            break;
                    }


                }while(userValue!=0);
                break;
            case 2:
                Node *line = NULL;
                do{
                    printf("---------------------------------------------\n");
                    printf("1 - INSERIR NA FILA\n2 - REMOVER DA FILA\n3 - IMPRIMIR\n0 - SAIR\n");
                    printf("---------------------------------------------\n");
                    printf("INSIRA: ");
                    scanf("%d", &userValue);

                    switch(userValue){
                        case 1:
                            insertLine(&line);
                            break;
                        case 2:
                            removeLine(&line);
                            break;
                        case 3:
                            if(line){
                                printf("---------------------------------------------\n");
                                printf("FILA:\n\n");
                                printData(line);
                                printf("---------------------------------------------\n");
                            }
                            else{
                                printf("---------------------------------------------\n");
                                printf("FILA VAZIA\n");
                                printf("---------------------------------------------\n");
                            }
                            break;
                        default:
                            if(userProgram!=0)
                                printInvalid;
                            else{
                                printf("---------------------------------------------\n");
                                printf("FILA FINALIZADA\n");
                                printf("---------------------------------------------\n");
                            }
                            break;
                    }

                }while(userValue!=0);
                break;
            case 3:
                Node *linkedList = NULL;
                int valueLate;
                do{
                    printf("---------------------------------------------\n");
                    printf("1 - INSERIR NO INICIO DA LISTA\n2 - INSERIR NO MEIO DA LISTA\n3 - INSERIR NO FINAL DA LISTA\n");
                    printf("4 - REMOVER NO INICIO DA LISTA\n5 - REMOVER NO MEIO DA LISTA\n6 - REMOVER NO FINAL DA LISTA\n");
                    printf("7 - IMPRIMIR\n0 - SAIR\n");
                    printf("---------------------------------------------\n");
                    printf("INSIRA: ");
                    scanf("%d", &userValue);

                    switch(userValue){
                        case 1:
                            insertBeginLinkedList(&linkedList);
                            break;
                        case 2:

                            printf("---------------------------------------------\n");
                            printf("INSERIR APÓS: ");
                            scanf("%d", &valueLate);
                            printf("---------------------------------------------\n");

                            insertMidLinkedList(&linkedList, valueLate);
                            break;
                        case 3:
                            insertEndLinkedList(&linkedList);
                            break;
                        case 4:
                            removeBeginLinkedList(&linkedList);
                            break;
                        case 5:
                            if(linkedList){
                                printf("---------------------------------------------\n");
                                printf("REMOVER VALOR: ");
                                scanf("%d", &valueLate);
                                printf("---------------------------------------------\n");
                                removeMidLinkedList(&linkedList, valueLate);
                            }
                            else{
                                printf("---------------------------------------------\n");
                                printf("LISTA VAZIA\n");
                                printf("---------------------------------------------\n");
                            }

                            break;
                        case 6:
                            removeEndLinkedList(&linkedList);
                            break;
                        case 7:
                            if(linkedList){
                                printf("---------------------------------------------\n");
                                printf("LISTA:\n\n");
                                printData(linkedList);
                                printf("---------------------------------------------\n");
                            }
                            else{
                                printf("---------------------------------------------\n");
                                printf("LISTA VAZIA\n");
                                printf("---------------------------------------------\n");
                            }

                            break;
                        default:
                            if(userValue!=0)
                                printInvalid();
                            else{
                                printf("---------------------------------------------\n");
                                printf("LISTA FINALIZADA\n");
                                printf("---------------------------------------------\n");
                            }

                            break;
                    }


                }while(userValue!=0);
                break;
            default:
                if(userProgram!=0)
                    printInvalid();
                else{
                    printf("---------------------------------------------\n");
                    printf("PROGRAMA FINALIZADO\n");
                    printf("---------------------------------------------\n");
                }

                break;


        }
    }while(userProgram!=0);
    return 0;
}
