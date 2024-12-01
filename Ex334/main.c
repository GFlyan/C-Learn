#include <stdio.h>
#include <stdlib.h>

/*
Exercício 334: Merge sort

-> Ponto de parada das divisões: if(begin>=end) - vetor unitário

-> Criar variável que vai receber a posição média do total de posições
do vetor

-> Divide até alcançar o vetor unitário e junta(merge) de forma
ordenada através de um vetor auxiliar

*/

void merge(int *arrayInteger,  int *aux, int begin, int mid, int end)
/*
Procedimento que realiza a junção dos subvetores criados, de forma ordenada
em um vetor auxiliar que será copiado pelo vetor originial.

A cada realização desse procedimento após a finalização de uma chamada recursiva
o vetor está mais ordenado.

Recebe como parâmetros o vetor original, as posições de início e fim
do raio de posições, a posição do elemento do meio, e o endereço do vetor auxiliar;
*/
{

    int positionAux = begin;//Variável que recebe a posição inicial referente do vetor auxiliar


    int i = begin;//Variável contadora referente a posição inicial do subvetor a esquerda
    int j = mid+1;//Variável contadora referente a posição inicial do subvetor a direita


    while(i<=mid && j<= end)
    /*Esse loop realiza a inserção simultânea ordenada
      dos valores dos subvetores no vetor auxiliar após
      o merge.

      Caso exista elementos em um dos subvetores, a
      inserção no vetor auxiliar irá continua até
      um dos subvetores for inserido completamente.*/

    {
        if(arrayInteger[i] < arrayInteger[j])//Caso o menor valor seja do subvetor a esquerda
        {
            aux[positionAux] = arrayInteger[i];//Vetor auxiliar recebe o menor valor
            i++;//Incrimente unitário na posição referente ao subvetor a esquerda
        }
        else//Caso o menor valor seja do subvetor a direita
        {
            aux[positionAux] = arrayInteger[j];//Vetor auxiliar recebe o menor valor
            j++;//Incrimente unitário na posição referente ao subvetor a direita
        }
        positionAux++;
    }

    /*Somente um dos seguintes laço while será executado,
      dependendo de qual subvetor tenha sido inserido
      completamente no vetor auxiliar*/

    while(j <= end)
    /*Caso o vetor da esquerda tenha sido inserido completamente
      no vetor auxiliar, será necessário inserir o vetor da direita
      posteriormente*/
    {
        aux[positionAux] = arrayInteger[j];//Vetor auxiliar recebe o menor valor
        j++;//Posição referente ao subvetor a direita recebe incremento unitário
        positionAux++;//Variável referente a posição do vetor recebe incremento unitário
    }

    while(i <= mid)

    /*Caso o vetor da direita tenha sido inserido completamente
    no vetor auxiliar, será necessário inserir o vetor da esquerda
    posteriormente*/
    {
        aux[positionAux] = arrayInteger[i];//Vetor auxiliar recebe o menor valor
        i++;//Posição referente ao subvetor a esquerda recebe incremento unitário
        positionAux++;//Variável referente a posição do vetor recebe incremento unitário
    }

    for(i = begin; i <= end; i++)//Percorre no raio de posições referente para preencher o vetor principal
        arrayInteger[i] = aux[i];//Preenche o vetor principal de forma ordenada
}

void mergeSort(int *arrayInteger, int *aux, int begin, int end)
/*
Procedimento de ordenação.

O merge sort divide o vetor original em subvetores
(utilizando os índices do vetor e chamadas recursivas),
onde após alcançar o vetor unitário é feito a junção ordenada
(merge) dos subvetores criados.

Recebe como parâmetros um veotr, a posição inicial do vetor
e a posição final do vetor.
*/
{
    int mid = (begin+end)/2;//Posição média de divisão do vetor
    if(begin>=end) return;//Realizando divisões até chegar no vetor unitário - PONTO DE PARADA
        mergeSort(arrayInteger, aux, begin, mid);//Divide o vetor a esquerda, criando um subvetor
        mergeSort(arrayInteger, aux, mid+1, end);//Divide o vetor a direita, criando um subvetor

    merge(arrayInteger, aux, begin, mid, end);//Aciona o procedimento que realiza a junção dos subvetores de forma ordenada

}

void printArrayInteger(int *arrayInteger, int sizeArray)
/*
Procedimento que mostra todos os elementos de um vetor.

Recebe 2 parâmetros, um vetor e o tamanho desse vetor.
*/
{
    for(int i = 0 ; i<sizeArray; i++)//Percorre o vetor
    {
        if(i == 0)
            printf("[");
        if(i!=sizeArray-1)
            printf("%d, ", arrayInteger[i]);
        else
            printf("%d]\n", arrayInteger[i]);
    }
}


int main()
{
    int arrayInteger[] = {9, 2, 8, 1, 0, 3, 6, 4};
    int sizeArray = 8;
    int aux[sizeArray];/*Cria um vetor auxiliar de tamanho do vetor principal
                         que irá receber a junção dos subvetores ordenados do
                         merge sort*/
    printf("------------------------------------------\n");
    printf("Array Desordenado:\n");
    printArrayInteger(arrayInteger, sizeArray);
    printf("------------------------------------------\n");
    printf("Array Ordenado:\n");
    mergeSort(arrayInteger, aux, 0, sizeArray-1);
    printArrayInteger(arrayInteger, sizeArray);
    printf("------------------------------------------\n");
    return 0;
}
