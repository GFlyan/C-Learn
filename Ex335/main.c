#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Exercício 335: Heap Sort

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

void fixUp(int *arrayHeap, int lastPosition/*K*/)
/*Procedimento que concerta a Heap após a inserção
de um novo elemento.

Recebe como parâmetros:

-Array que diz respeito a Heap
-Valor que diz respeito a última posição do array que contém
um elemento.*/
{
    while(lastPosition > 1 && (arrayHeap[lastPosition] > arrayHeap[lastPosition/2])) {
        int backup = arrayHeap[lastPosition];
        arrayHeap[lastPosition] = arrayHeap[lastPosition/2];
        arrayHeap[lastPosition/2] = backup;
        lastPosition = lastPosition/2;
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

        //Swap
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


void PQsort(int *arrayInt, int firstPosition, int lastPosition)
/*Priority Queue Sort:

Esta versão utiliza espaço extra, se tratando de um
algorítmo out-place, pois é criado uma Heap interna
com base no array parametrado.

Recebe como parâmetros:

-Array a ser ordenado
-Posição inicial da ordenação no array
-Posição final da ordenação no array*/
{
    PriorityQueue priorityQueue;//Definindo uma Heap
    priorityQueueInit(&priorityQueue, lastPosition-firstPosition+1);//Criando a Heap
    for(int position = firstPosition; position <= lastPosition; position++)
    /*Copia os valores contidos no array para formar a Heap*/
        priorityQueueInsert(&priorityQueue, arrayInt[position]);//Inserindo na Heap cada valor contido no array
    for(int position = lastPosition; position >= firstPosition; position--)
    /*Insere da posição final do array até o início do array*/
        arrayInt[position] = priorityQueueRemove(&priorityQueue);//Recebe o maior elemento contido na Heap a cada chamada
}

void heapSort(int *arrayInt, int firstPosition, int lastPosition)
/*Versão 2 do Heap Sort:

Esta versão não utiliza espaço extra pois
se trata de um algoritmo in-place, onde o array
parametrado é transformado em uma Heap.

Recebe como parâmetros:

-Array a ser ordenado [0] não pode estar sendo utilizado
-Posição inicial da ordenação no array
-Posição final da ordenação no array*/
{
    int *heap = arrayInt-1+firstPosition;
    int lastPositionHeap = lastPosition-firstPosition+1;//Diz respeito ao tamanho do vetor original e também a última posição da Heap

    for(int fixPosition = lastPositionHeap/2; fixPosition >= 1; fixPosition--)
    /*É garantido que fixPosition diz respeito a posição de um nó
    pai válido, até alcançar o nó raiz, afim de gerar as subHeaps.

    Vale ressaltar que lastPositionHeap diz respeito ao sizeArray.*/
        fixDown(heap, fixPosition, lastPositionHeap);//Conserta a Heap quebrada


    while(lastPositionHeap>1)
    /*O elemento prioritário é inserido no final da Heap
    tendo assim que a cada realização do laço o final estará
    ordenado corretamente, é realizada a chamada de fixDown
    devido o swap, realizando o decrescimo do tamanho da Heap*/
    {
        //Swap do prioritário com o último elemento realizando no final o decrescimo do tamanho da Heap
        int backup = heap[1];
        heap[1] = heap[lastPositionHeap];
        heap[lastPositionHeap] = backup;

        //Concerta a Heap devido o swap
        fixDown(heap, 1, --lastPositionHeap);
    }

}

int main()
{
    //PQ SORT
    int arrayPQSort[5] = {3, 9, 1, 7, 4};//Criando um array qualquer não ordenado
    printf("ARRAY NAO ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",arrayPQSort[i]);
    }
    printf("]\n");
    PQsort(arrayPQSort, 0, 4);//Aplicando Insertion Sort
    printf("ARRAY ORDENADO COM PQ SORT: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",arrayPQSort[i]);
    }
    printf("]\n");

    printf("------------------------------------------------------\n");

    //HEAP SORT
    int arrayHeapSort[5] = {4, 9, 1, 0, 3};//Criando um array qualquer não ordenado
    printf("ARRAY NAO ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",arrayHeapSort[i]);
    }
    printf("]\n");
    heapSort(arrayHeapSort, 0, 4);//Aplicando Insertion Sort
    printf("ARRAY ORDENADO COM HEAP SORT: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",arrayHeapSort[i]);
    }
    printf("]\n");
    return 0;
}
