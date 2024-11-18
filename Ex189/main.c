#include <stdio.h>
#include <stdlib.h>

/*
Exercícios 189: Aritmética de ponteiros com vetor
*/

void printArrayInteger(int arrayInteger[],int sizeArray)/*Criando um procedimento que informa cada
                                                        elemento contido em um vetor porém percorrendo
                                                        com ponteiro*/
{
    for(int counter = 0; counter<sizeArray; counter++)//Percorrendo cada posição do array
    {
        int value = *(arrayInteger+counter);/*Aritmética de ponteiro aplicada, relembrando que
                                           que o nome do array é um ponteiro que armazena um
                                           endereço de memória, sendo também o endereço de
                                           memória do primeiro elemento, tornando assim possível
                                           a percursão do array*/

        printf("%d ", value);//Mostrando o valor de cada posição do array
    }
}

int main()
{
    int sizeArray = 10;//Criando uma variável que diz respeito ao tamanho do array
    int arrayInteger[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//Criando um array de inteiros
    printArrayInteger(arrayInteger, sizeArray);/*Acionando o procedimento que percorre o array
                                                 informando o valor de cada posição pela lógica
                                                 de atimética de ponteiros*/
    return 0;
}
