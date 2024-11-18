#include <stdio.h>
#include <stdlib.h>

/*
Exercício 188: Um vetor é sempre um ponteiro?

-> Devido a característica de um array ser um ponteiro, qualquer mudança nele mesmo sempre será salva
independente do escopo e independente se for alterado por um procedimento(sem return)
*/

void doubleArrayInteger(int arrayInteger[], int arraySize)/*Criando um procedimento que dobra o valor
                                                        das posições de um array*/
{
    for(int counter = 0; counter<arraySize; counter++)//Percorrendo o array
    {
        arrayInteger[counter] *= 2;//Cada posição do array dobra o valor
    }
}

void printArray(int arrayInteger[], int arraySize)/*Criando um procedimento que informa o valor
                                                    de cada posição do array*/
{
    for(int counter=0; counter<arraySize;counter++)//Percorrendo o array
    {
        printf("%d ", arrayInteger[counter]);
    }
    printf("\n");
}

int main()
{
    int arrayInteger [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//Criando um array de inteiros com 10 posições
    printArray(arrayInteger, 10);//Acionando o procedimento que informa os valores contido no array

    doubleArrayInteger(arrayInteger, 10);//Acionando o procedimento que dobra os valores contido no array
    printArray(arrayInteger, 10);//Acionando o procedimento que informa os valores contido no array

    return 0;
}
