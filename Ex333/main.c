#include <stdio.h>
#include <stdlib.h>

/*
Exercício 333: Insertion sort

->Ordenação por inserção

->Complexidade quadrática: n²

->Custo elevado, não tão eficiente
*/

void insertionSort(int *arrayInteger, int sizeArray)
/*
Procedimento que diz respeito a um algoritmo de
ordenação.

O insertion sort possui 2 loops, onde o loop interno
faz uma percursão inversa em um raio de posições
comparando se a posição referente possui um valor menor
que a posição antecessora, caso haja, é realizado swap.
No loop externo ocorre a gerência do raio a ser analizado
pelo loop interno.

Recebe 2 parâmetros, o vetor e o tamanho do vetor.
*/
{
    for(int i = 1; i < sizeArray; i++) //Definindo o raio de analise pelo loop interno
    {
        for(int j = i; arrayInteger[j]< arrayInteger[j-1] && j-1 >= 0; j--)/*Percursão inversa do vetor conferindo se o
                                                                             o valor na posição referenté é menor que o
                                                                             valor na posição anterior, caso seja
                                                                             acontecerá swap*/
        {
            int aux = arrayInteger[j];//Variável auxiliar recebe o valor menor
            arrayInteger[j] = arrayInteger[j-1];//Posição maior recebe o valor maior
            arrayInteger[j-1] = aux;//Posição menor recebe o valor menor
        }
    }
}


void insertionSortRecursive(int *arrayInteger, int begin, int sizeArray)
/*
Procedimento que diz respeito a um algoritmo de
ordenação.

O insertion sort possui 2 loops, onde o loop interno
faz uma percursão inversa em um raio de posições
comparando se a posição referente possui um valor menor
que a posição antecessora, caso haja, é realizado swap.
No loop de recursão ocorre a gerência do raio a ser analizado
pelo loop interno

Recebe 3 parametros, o vetor, a variável que diz
respeito a maior posição do raio a começar a análise
e o tamanho do vetor.
*/
{
    if(begin>=sizeArray)return;//Caso o início de analise do raio de posições seja maior que o número de posições do vetor - PONTO DE PARADA

        for(int i = begin; arrayInteger[i]<arrayInteger[i-1] && i-1>=0; i--)/*Percursão inversa do vetor dentro de um raio definido
                                                                              comparando os valores da posição referente com a posição
                                                                              antecessora, caso o valor da posição referente seja
                                                                              menor que o valor da posição antecessora, ocorre swap.*/
        {
            int aux = arrayInteger[i];//Variável auxiliar recebe o valor menor
            arrayInteger[i] = arrayInteger[i-1];//Posição maior recebe o valor maior
            arrayInteger[i-1] = aux;//Posição menor recebe o valor menor
        }
        insertionSortRecursive(arrayInteger, ++begin, sizeArray);/*Chamada recursiva, ponto crucial da chamada recursiva
                                                                   é o incremento unitário da variável que diz respeito
                                                                   ao raio de analise.*/

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
    int arrayInteger[] = {8, 1, 7, 3, 2, 9, 4};//Criando um vetor de inteiros
    int sizeArray = 7;//Tamanho do vetor acima
    int arrayIntegerRecursive[] = {7, 5, 2, 9, 3, 8, 1};//Criando um vetor de inteiros
    int sizeArrayRecursive = 7;//Tamanho do vetor acima
    printf("------------------------------------------\n");
    printf("Array Desordenado: ");
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra os elementos do vetor
    printf("------------------------------------------\n");
    printf("Array Ordenado: ");
    insertionSort(arrayInteger, sizeArray);//Acionando o procedimento iterativo de ordenação do vetor
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra os elementos do vetor
    printf("------------------------------------------\n");
    printf("RECURSIVA -> Array Desordenado: ");
    printArrayInteger(arrayIntegerRecursive, sizeArrayRecursive);//Acionando o procedimento que mostra os elementos do vetor
    printf("------------------------------------------\n");
    printf("RECURSIVA -> Array Ordenado: ");
    insertionSortRecursive(arrayIntegerRecursive, 1, sizeArrayRecursive);//Acionando o procedimento recursivo de ordenação do vetor
    printArrayInteger(arrayIntegerRecursive, sizeArrayRecursive);//Acionando o procedimento que mostra os elementos do vetor
    printf("------------------------------------------\n");

    return 0;
}
