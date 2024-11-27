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

int partition(int *arrayInteger, int begin, int end)
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
    while(begin<end) /*A condição de início do vetor < fim do vetor é importante
                       ao decorrer do quick sort, devido o decorrer das chamadas
                       recursivas, o array será subdivido em outros arrays
                       até chegar no array unitário, onde nenhum dos laços será
                       executado*/
    {
        int pivot = ((arrayInteger[begin] + arrayInteger[end] + arrayInteger[(begin+end)/2])/3);//Definindo o elemento pivô
        while(begin<end && arrayInteger[begin] <= pivot)//Procura do início ao fim de um vetor um elemento maior que o pivô
            begin++;
        while(begin<end && arrayInteger[end] > pivot);//Procurando do fim até o início um elemento menor que o pivô
            end--;

        int aux = arrayInteger[begin];//Criando uma variável auxiliar para realizar swap entre dois dados
        arrayInteger[begin] = arrayInteger[end];//Swap de conteúdos, posição mais ao início recebe um valor menor do que o antes contido
        arrayInteger[end = aux;//Swap de conteúdo, a posição mais ao fim recebe um valor maior do que o antes contido

    }
    //A este ponto begin é igual a end, início igual ao fim, significando que uma posição ja está organizada
    return begin;//Retorna a posição já organizada que irá ser o ponto de divisão dos subvetores
}

void quickSort(int *arrayInteger, int begin, int end)
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
    while(begin<end)//Enquanto não for o vetor unitário
    {
        int position = partition(arrayInteger, begin, end);/*Criando uma variável que aciona a função
                                                             partition, qual organiza equilibradamente os
                                                             valores do vetor em relação à um pivô e retorna
                                                             a posição do elemento pivô*/
        quickSort(arrayInteger, begin, position);//Chamada recursiva para cada subvetor a esquerda de um pivô
        quickSort(arrayInteger, position+1, end);//Chamada recursiva para cada subvetor a direita de um pivô
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
