#include <stdio.h>
#include <stdlib.h>

/*
Exercício 332: Selection sort

->Organiza a partir do início do array.
*/

void selectionSort(int *arrayInteger, int sizeArray)
/*
Procedimento que diz respeito à um algorítmo
de ordenação conhecido como selection sort.

O selection sort consiste na percursão do array,
a partir da primeira posição, inserindo os menores
valores do início ao fim do array nas devidas posições
com os valores ordenadados de forma crescente.

Recebe como parâmetros, um vetor, o tamanho do vetor e
um valor que diz respeito a posição que se quer iniciar
a ordenação do vetor.
*/
{
    for(int i = 0; i < sizeArray-1; i++)
    /*Percursão do array, a cada iteração significa que
    a posição equivalente ao contador, ao final, estará
    com o valor ordenado corretamente.

    Este laço serve para analisar um valor de posição por
    vez comparando-o com os valores das outras posições.*/
    {
        int minor = i;/*Variável que recebe o índice da posição com o menor
                        valor, recebendo inicialmente o índice da posição
                        referente, para caso não haja nenhum outro valor
                        menor, não haja trocas.*/

        for(int j = i+1; j < sizeArray; j++)
        /*Percursão do vetor, iniciando uma posição após a posição
        referente a receber as trocas.

        Este laço serve para analisar caso haja valores menores
        que o valor da posição principal referente.*/
        {
            if(arrayInteger[j]<arrayInteger[minor])//Caso haja um valor menor que o valor da posição principal
                minor = j;
                /*A variável recebe o índice da posição que contém
                o elemento menor que o elemento na posição principal*/
        }
        int aux = arrayInteger[i];//Variável auxiliar que recebe o elemento com valor maior contido na posição principal
        arrayInteger[i] = arrayInteger[minor];//Atribuindo à posição principal o menor valor
        arrayInteger[minor] = aux;//Atribuindo a posição que continha o menor valor, o valor maior antes contido na posição principal
    }

}

void selectionSortRecursive(int *arrayInteger, int sizeArray, int begin)
/*
Procedimento que diz respeito ao algorítmo de
ordenação selection sort.

O selection sort consiste na percursão partindo
da primeira posição do array, onde os menores valores
são inseridos do início ao fim do array ordenados de
forma crescente.

Recebe como parâmetros, um vetor, o tamanho do vetor e
um valor que diz respeito a posição que se quer iniciar
a ordenação do vetor.
*/
{
    if(begin >= sizeArray-1) return;//Analisa se o início do vetor não se trata da posição final (já ordenada) - PONTO DE PARADA
    int minor = begin;/*Variável que recebe o índice da posição que contém o menor valor,
                        onde inicialmente será o índice da posição principal, para que,
                        caso não haja nenhum valor menor que o da posição principal,
                        não seja feita nenhuma troca*/
    for(int i = begin+1 ; i < sizeArray ; i++)
    /*Percursão do vetor a partir de uma posição
    após a posição principal referente, a procura
    de um valor menor que o valor contido na posição
    principal*/
    {
        if(arrayInteger[i]<arrayInteger[minor])//Caso haja um valor menor que o valor da posição principal

            minor = i;//Varíavel recebe o índice da posição que contém o valor menor que o valor da posição principal

    }
    int aux = arrayInteger[begin];//Variável auxiliar recebe o valor contido na posição principal
    arrayInteger[begin] = arrayInteger[minor];//Posição principal recebe um valor menor
    arrayInteger[minor] = aux;//Posição que antes contia o menor valor, recebe o valor antes contido na posição principal
    selectionSortRecursive(arrayInteger, sizeArray, ++begin);/*Chamada recursiva, acrescendo 1 a posição inicial,
                                                               pois a posição inicial analisada está ordenada
                                                               corretamente*/
}

void printArrayInteger(int *arrayInteger, int sizeArray)
/*
Procedimento que mostra todos os valores contidos
em um vetor.

Recebe como parâmetro o vetor e o tamanho do vetor.
*/
{
    for(int i = 0 ; i<sizeArray; i++)//Percorrendo o vetor
    {
        if(i==0)
            printf("[");
        if(i!= sizeArray-1)
            printf("%d, ", arrayInteger[i]);
        else
            printf("%d]\n", arrayInteger[i]);
    }
}
int main()
{

    int arrayInteger[] = {2, 7, 4, 6, 9, 0};//Criando um array
    int sizeArray = 6;//Variável que recebe o tamanho do array acima
    int arrayIntegerRecursive[] = {10, 2, 5, 1, 0, 9, 8};//Criando um array que será parâmetro de um procedimento recursivo
    int sizeArrayRecursive = 7;//Variável que recebe o tamanho do array acima
    printf("------------------------------------\n");
    printf("Array: ");
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra um vetor
    printf("Array Recursivo: ");
    printArrayInteger(arrayIntegerRecursive, sizeArrayRecursive);//Acionando o procedimento que mostra um vetor
    selectionSort(arrayInteger, sizeArray);//Acionando o procedimento de ordenação iterativo
    printf("------------------------------------\n");
    printf("Array: ");
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra um vetor
    selectionSortRecursive(arrayIntegerRecursive, sizeArrayRecursive, 0);//Acionando o procedimento de ordenação recursivo
    printf("Array Recursivo: ");
    printArrayInteger(arrayIntegerRecursive, sizeArrayRecursive);//Acionando o procedimento que mostra um vetor
    printf("------------------------------------\n");
    return 0;
}
