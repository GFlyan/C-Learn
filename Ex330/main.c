#include <stdio.h>
#include <stdlib.h>

/*
Exercício 330: Quick Sort

->Algorítmo eficiente de ordenação
->Partição/particionamento/particionar

PASSO A PASSO

->Escolher um pivô que será usado nas comparações
->Percursão do vetor da esquerda pra direita em busca de um elemento maior que o pivô
->Percursão do vetor da direita pra esquerda em busca de um elemento menor que o pivô
->Troca os dois elementos (swap)

->Escolha do pivô: media dos 3 elementos [INÍCIO, MEIO, FIM]
*/

int partition(int *arrayInteger, int leftPosition, int rightPosition)
/*
Função que define um pivo baseando-se no vetor informado.

Realiza swap entre posições cuja posição mais ao início do
vetor contém um elemento maior que o pivô e a mais ao fim
um elemento menor que o pivô, fazendo assim, separações
de itens menores e maiores aos lados do vetor a cada
chamada.

Recebe como parâmetro um array, a posição inicial do vetor
e a posição final do vetor que será processado.
*/
{
    while(leftPosition < rightPosition) /*A condição de início do vetor < fim do vetor é importante
                                       ao decorrer do quick sort, devido o decorrer das chamadas
                                       recursivas, o array será subdivido em outros arrays
                                       até chegar no array unitário, onde nenhum dos laços será
                                       executado*/
    {
        int pivot = ((arrayInteger[leftPosition] + arrayInteger[(leftPosition+rightPosition)/2] + arrayInteger[rightPosition])/3);//Definindo o elemento pivô

        while(arrayInteger[leftPosition] <= pivot && leftPosition < rightPosition)//Procura do início ao fim de um vetor um elemento maior que o pivô
            leftPosition++;//Incremento unitário a variável que representa a posição que terá um valor maior que o pivô
        while(arrayInteger[rightPosition] > pivot && leftPosition < rightPosition)//Procurando do fim até o início um elemento menor que o pivô
            rightPosition--;//Incremento unitário a variável que representa a posição que terá um valor menor que o pivõ

        if(leftPosition <= rightPosition)
        //Caso a posição a esquerda seja menor que a posição a direita e obedeçam a regra em relação ao pivô
        {
            int backup = arrayInteger[leftPosition];//Criando uma variável auxiliar para realizar swap entre dois dados
            arrayInteger[leftPosition] = arrayInteger[rightPosition];//Swap de conteúdos, posição mais ao início recebe um valor menor do que o antes contido
            arrayInteger[rightPosition] = backup;//Swap de conteúdo, a posição mais ao fim recebe um valor maior do que o antes contido
        }
     }
    //A este ponto begin é igual a end, início igual ao fim, significando que o posição ja está organizada

    return rightPosition;//Retorna a posição já organizada que irá ser o ponto de divisão dos subvetores
}

void quickSort(int *arrayInteger, int firstPosition, int lastPosition)
/*
Procedimento que ordena um vetor através do uso
da função partição que faz swap entre elementos
maiores para os extremos do vetor, organizando-o
através de chamadas recursivas até chegar no vetor
unitário.

Recebe como parâmetro um array inteiro, á posição
inicial do vetor e a posição final do vetor.
*/
{
    if(firstPosition >= lastPosition) return;//Caso seja o vetor unitário ordenado - PONTO DE PARADA
    {
        int mid = partition(arrayInteger, firstPosition, lastPosition);/*Criando uma variável que aciona a função
                                                             partition, qual organiza equilibradamente os
                                                             valores do vetor em relação à um pivô e retorna
                                                             a posição do elemento pivô*/

        quickSort(arrayInteger, firstPosition, mid-1);//Valores a esquerda, menores que o pivô
        quickSort(arrayInteger, mid+1, lastPosition);//Valores a direita, maiores que o pivô
    }
}

void printArrayInteger(int *arrayInteger, int sizeArray)
/*
Procedimento que mostra os valores de um vetor.

Recebe como parâmetros um vetor e o tamanho do vetor.
*/
{
    for(int i = 0 ; i < sizeArray ; i++)//Percorrendo cada posição do vetor
    {
        if(i == 0)//Caso seja o primeiro loop
            printf("[");
        if(i <sizeArray-1)//Caso não seja o último elemento do vetor
            printf("%d, ", arrayInteger[i]);
        else//Caso seja o último elemento do vetor
            printf("%d]\n", arrayInteger[i]);
    }
}

int main()
{
    int arrayInteger[] = {0, 3, 8, 4, 5, 1, 6};//Criando um vetor de inteiros
    int sizeArray = 7;//Variável que diz respeito ao tamanho do vetor acima
    printf("------------------------------------------\n");
    printf("Array Desorganizado: ");
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra os elementos de um vetor
    printf("------------------------------------------\n");
    quickSort(arrayInteger, 0, sizeArray-1);//Acionando o procedimento que ordena o vetor
    printf("Array Organizado: ");
    printArrayInteger(arrayInteger, sizeArray);//Acionando o procedimento que mostra os elementos de um vetor
    return 0;
}
