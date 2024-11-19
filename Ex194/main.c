#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 194: Crie um programa que contenha um array de inteiros com 10 elementos.
Imprima o elemento e o endereço de cada posição do array.
*/

void generateArrayInteger(int *arrayInteger, int sizeArray){//Criando um procedimento que gera valores à cada posição do array
    srand(time(NULL));//Definindo o tempo como semente da função rand
    for(int c=0; c<sizeArray;c++)//Percorrendo cada espaço de memória do vetor
    {
        *(arrayInteger+c) = rand();//Cada conteúdo apontado pelo espaço de memória relacionado recebe um valor diferente
    }

}

void printArrayInteger(int *arrayInteger, int sizeArray){//Criando um procedimento que mostra cada conteudo da posição do array
    for(int c=0; c<sizeArray;c++)//Percorrendo cada endereço de memória do vetor
    {
        if(c==0)
            printf("[");
        if(c==sizeArray-1)
            printf("%d]\n", *(arrayInteger+c));//Mostrando o conteúdo apontado pelo utlimo espaço de memória do vetor
        else
            printf("%d, ", *(arrayInteger+c));//Mostrando o conteúdo apontado por cada espaço de memória do vetor, exceto o último
    }
}

void printElementAddress(int *arrayInteger, int size){/*Criando um procedimento que recebe o endereço de memória de um vetor
                                                        e seu tamanho, para informar o conteúdo+endereço de memória de cada
                                                        posição desse vetor*/

    for(int c= 0; c<size;c++)//Percorrendo cada endereço de memória do vetor
    {
        printf("------------------------------------------------------------\n");
        printf("O elemento da primeira posição é: %d\n", *(arrayInteger+c));//Mostrando o elemento de cada posição do vetor
        printf("O endereço da primeira posição é: %p\n", arrayInteger+c);//Mostrando o endereço de cada posição do vetor
        printf("------------------------------------------------------------\n");
    }
}

int main()
{

    int arrayInteger[10];//Criando um vetor com 10 posições
    generateArrayInteger(arrayInteger, 10);/*Acionando o procedimento que gera um valor como conteúdo para cada espaço
                                             de memória do vetor*/
    printArrayInteger(arrayInteger, 10);/*Acionando o procedimento que mostra cada conteúdo de cada posição vetor*/
    printElementAddress(arrayInteger, 10);/*Acionando o procedimento que mostra cada conteúdo + endereço de memória
                                            de cada posição do vetor*/

    return 0;
}
