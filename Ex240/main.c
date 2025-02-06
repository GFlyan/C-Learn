#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Exercício 240: Fila de Prioridades Decrescente||Máxima

Fila de Prioridades, conhecida também como Heap, é baseada
na estrutura de uma Árvore Binária sendo implementada através
de arrays, ao contrario das árvores binárias tradicionais que
são implementadas através de listas encadeadas.

Temos que em uma Heap os elementos serão inseridos na posição
HEAP[1] adiante, para que possamos garantir a seguinte característica:

Filhos de HEAP[K] -> Filho a esquerda HEAP[2*K] | Filho a direita HEAP[2*K+1]
Pai de HEAP[K] -> HEAP[K/2]

A prioridade é ditada da seguinte forma:

Decrescente ou Máxima, caso o primeiro elemento do array seja o maior
elemento existente e todo nó pai é maior ou igual que seus nós filhos.

Crescente ou Mínima, caso o primeiro elemento do array seja o menor
elemento existente e todo nó pai é menor ou igual que seus nós filhos.

A inserção é feita no final do array, sendo utilizado uma função que
conserta a Heap de acordo com sua prioridade.

A remoção é feita no início do array, pois em uma Heap o que importa
é o valor prioritario. Após a remoção é necessário consertar a Heap.

É tida como uma árvore binária eficiente pois é garantido que ela
estará balanceada da seguinte forma: Níveis anteriores ao nível
que contém os nós folhas estarão completos.
*/

typedef struct priorityQueue
/*Estrutura que diz respeito a uma Heap, onde
possui os seguintes campos:

-Array
-Posição do último elemento
-Tamanho máximo do array
*/
{
    int *arrayPriorityQueue;//Campo que diz respeito ao vetor que obedece as características de uma Heap
    int lastPosition;//Posição do último elemento
    int size;//Tamanho da Heap
}PriorityQueue;

void priorityQueueInit(PriorityQueue *priorityQueue, int sizePriorityQueue)
/*Procedimento que atribui os conceitos da Heap para a estrutura parametrada.

Recebe como parâmetros o endereço da estrutura que contém os dados da Heap
e o tamanho máximo que a Heap terá.*/
{
    priorityQueue->arrayPriorityQueue = malloc(sizeof(priorityQueue->arrayPriorityQueue)*(sizePriorityQueue+1));//Aloca memória equivalente a [0 -> N+1] para que seja possível acessar [0 -> N] mesmo que o [0] não seja utilizado
    priorityQueue->lastPosition = 0;//Equivale ao K
    priorityQueue->size = sizePriorityQueue;//Equivale ao N, sendo uma posição possível de ser acessada no array, pois a capacidade do array é construido com base em N+1.
}

bool priorityQueueEmpty(PriorityQueue *priorityQueue)
/*Função que verifica se a Heap está vazia.*/
{
    return priorityQueue->lastPosition == 0;
}

bool priorityQueueFull(PriorityQueue *priorityQueue)
/*Função que verifica se a Heap está cheia.*/
{
    return priorityQueue->lastPosition == priorityQueue->size;
}

void fixUp(int *arrayHeap, int fixPosition/*K*/)
/*Procedimento que concerta a Heap após a inserção
de um novo elemento.

Recebe como parâmetros:

-Array que diz respeito a Heap
-Valor que diz respeito a última posição do array que contém
um elemento.*/
{
    while(fixPosition > 1 && (arrayHeap[fixPosition] > arrayHeap[fixPosition/2])) {
        int backup = arrayHeap[fixPosition];
        arrayHeap[fixPosition] = arrayHeap[fixPosition/2];
        arrayHeap[fixPosition/2] = backup;
        fixPosition = fixPosition/2;
    }
}

void priorityQueueInsert(PriorityQueue *priorityQueue, int value) {
        if(!priorityQueueFull(priorityQueue)) {
            priorityQueue->arrayPriorityQueue[++(priorityQueue->lastPosition)] = value;
            fixUp(priorityQueue->arrayPriorityQueue, priorityQueue->lastPosition);
        }
}

void fixDown(int *arrayHeap, int fixPosition, int lastPosition)
/*Procedimento que analisa se o elemento em dada
posição é maior ou menor que seu maior filho.

Caso seja menor que seu maior filho, é realizado
swap.

Recebe como parâmetro:

-Array que diz respeito a Heap
-Posição a ser consertada
-Posição do último elemento do array*/
{
    while(2*fixPosition <= lastPosition)
    /*Enquanto existir filho a esquerda no array*/
    {
        int sonPosition = 2*fixPosition;//Filho a esquerda da posição a ser consertada

        if(sonPosition<lastPosition && arrayHeap[sonPosition] <  arrayHeap[sonPosition+1])
        /*Basicamente checa se o filho a esquerda não é a última posição
        e verifica se o filho a esquerda é menor que o filho a direita,
        afim de armazenar a posição do filho de maior valor.*/
            sonPosition++;//Filho a direita da posição a ser consertada

        if(arrayHeap[fixPosition] > arrayHeap[sonPosition]) break;
        /*Caso o pai seja maior que o filho*/

        /*Swap*/
        int backup = arrayHeap[fixPosition];
        arrayHeap[fixPosition] = arrayHeap[sonPosition];
        arrayHeap[sonPosition] = backup;

        fixPosition = sonPosition;//Posição a ser analisada recebe a posição qual o valor permanece agora
    }
}

int priorityQueueRemove(PriorityQueue *priorityQueue) {
    int remove = priorityQueue->arrayPriorityQueue[1];
    priorityQueue->arrayPriorityQueue[1] = priorityQueue->arrayPriorityQueue[(priorityQueue->lastPosition)--];
    fixDown(priorityQueue->arrayPriorityQueue, 1, priorityQueue->lastPosition);
    return remove;
}

void printfPriorityQueue(PriorityQueue *priorityQueue) {
    for(int i = 1; i <= priorityQueue->lastPosition; i++) {
        if(i == 1) printf("[%d", priorityQueue->arrayPriorityQueue[i]);
        else printf(", %d", priorityQueue->arrayPriorityQueue[i]);
        if(i == priorityQueue->lastPosition) printf("]\n", priorityQueue->arrayPriorityQueue[i]);
    }
}

int main() {
    int option1;
    do {
        printf("---------------------------------------------------------\n");
        printf("1 - CRIAR HEAP\n0 - SAIR\n");
        printf("---------------------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &option1);
        printf("---------------------------------------------------------\n");
        switch(option1) {
            case 1:
                PriorityQueue priorityQueue;
                int option2, sizeHeap;
                printf("---------------------------------------------------------\n");
                printf("TAMANHO DA HEAP: ");
                scanf("%d", &sizeHeap);
                printf("---------------------------------------------------------\n");
                priorityQueueInit(&priorityQueue, sizeHeap);
                do {
                    printf("---------------------------------------------------------\n");
                    printf("1 - INSERIR\n2 - REMOVER PRIORITARIO\n3 - VER\n0 - VOLTAR\n");
                    printf("---------------------------------------------------------\n");
                    printf("INSIRA: ");
                    scanf("%d", &option2);
                    printf("---------------------------------------------------------\n");
                    switch(option2) {
                        case 1:
                            if(!priorityQueueFull(&priorityQueue)) {
                                int value;
                                printf("---------------------------------------------------------\n");
                                printf("INSERIR VALOR: ");
                                scanf("%d", &value);
                                printf("---------------------------------------------------------\n");
                                priorityQueueInsert(&priorityQueue, value);
                            } else {
                                printf("---------------------------------------------------------\n");
                                printf("HEAP CHEIA\n");
                                printf("---------------------------------------------------------\n");
                            }
                        break;
                        case 2:
                            if(!priorityQueueEmpty(&priorityQueue)) {
                                int remove = priorityQueueRemove(&priorityQueue);
                                printf("---------------------------------------------------------\n");
                                printf("VALOR REMOVIDO: %d\n", remove);
                                printf("---------------------------------------------------------\n");
                            } else {
                                printf("---------------------------------------------------------\n");
                                printf("HEAP VAZIA\n");
                                printf("---------------------------------------------------------\n");
                            }
                            break;
                        case 3:
                            if(!priorityQueueEmpty(&priorityQueue)) {
                                printf("---------------------------------------------------------\n");
                                printfPriorityQueue(&priorityQueue);
                                printf("---------------------------------------------------------\n");
                            } else {
                                printf("---------------------------------------------------------\n");
                                printf("FILA DE PRIORIDADE VAZIA\n");
                                printf("---------------------------------------------------------\n");
                            }
                            break;
                        default:
                            if(option2) {
                                printf("---------------------------------------------------------\n");
                                printf("OPCAO INVALIDA\n");
                                printf("---------------------------------------------------------\n");
                            } else {
                                printf("---------------------------------------------------------\n");
                                printf("VOLTANDO\n");
                                printf("---------------------------------------------------------\n");
                            }
                            break;
                    }
                } while(option2);
                break;
            default:
                if(option1) {
                    printf("---------------------------------------------------------\n");
                    printf("OPCAO INVALIDA\n");
                    printf("---------------------------------------------------------\n");
                } else {
                    printf("---------------------------------------------------------\n");
                    printf("SAINDO\n");
                    printf("---------------------------------------------------------\n");
                }
                break;
        }
    } while(option1);

    return 0;
}
