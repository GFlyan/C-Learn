#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 200: Alocação dinâmica de memória com a função realloc()

->Retorna um novo endereço de memória
->Aloca uma região de memória maior à antiga contida no ponteiro a ser alocado

Recebe dois parâmetros:

1° Endereço de memória antigo
2° Novo tamanho a ser reservado

->Caso o novo tamanho seja 0 a memória é liberada

->Caso não haja memória suficiente, é retornado NULL
*/

void generateArrayInteger(int *arrayInteger, int size){/*Criando um procedimento que atribui
                                                         um valor aleatório pra cada posição
                                                         do array*/
    srand(time(NULL));//Definindo o tempo como semente da função rand
    for(int c=0;c<size;c++)//Percorrendo cada região de memória alocada do vetor
    {
        *(arrayInteger+c) = rand();//Atribuindo um valor aleatório pra cada posição do vetor
    }


}

void sizeArray(int *size){/*Criando um proceidmento que atribui o valor
                            do tamanho do vetor à uma variável*/
    printf("Informe o tamanho do vetor: ");
    scanf("%d", size);//Atribuino o valor do tamanho do vetor

}

void printAdressArrayInteger(int *arrayInteger, int size){/*Criando um procedimento que informa o
                                                            endereço de memória de cada posição do
                                                            vetor*/
    printf("-------------------------------------------\n");
    for(int c = 0; c < size; c++)
    {
        printf("%dº endereço: %p\n", c+1, arrayInteger+c);
    }
    printf("-------------------------------------------\n");

}

void printArrayInteger(int *arrayInteger, int size){//Criando um procedimento que mostra o vetor completo
    for(int c=0; c<size;c++)
    {
        if(c==0)
            printf("[");
        if(c==size-1)
            printf("%d]\n", *(arrayInteger+c));
        else
            printf("%d, ", *(arrayInteger+c));
    }
}

int main()
{
    int *arrayInteger, *size;//Criando um ponteiro vetor e um ponteiro cujo conteúdo apontado diz respeito ao tamanho do vetor
    size = malloc(sizeof(int));//Alocando um endereço de memória pro conteúdo do ponteiro
    if(size){//Caso a alocação de memória do ponteiro tenha dado certo
        sizeArray(size);//Acionando o procedimento que fornece um conteúdo apontado pro ponteiro
        arrayInteger = calloc(*size, sizeof(int));/*Atribuindo ao ponteiro vetor uma sequência de
                                                   endereços de memória baseado no tamanho informado,
                                                   retornado pela função calloc*/
        if(arrayInteger)//Caso a alocação de memória do ponteiro vetor tenha dado certo
        {
            generateArrayInteger(arrayInteger, *size);/*Acionando o procedimento que gera
                                                        valores aleatórios pra cada posição
                                                        do vetor*/

            printArrayInteger(arrayInteger, *size);/*Acionando o procedimento que mostra
                                                     o valor armazenado em cada posição
                                                     do vetor*/

            printAdressArrayInteger(arrayInteger, *size);/*Acionando o procedimento que mostra
                                                           o endereço de memória de cada posição
                                                           do vetor*/

            sizeArray(size);//Acionando o procedimento que fornece um conteúdo apontado pro ponteiro

            arrayInteger = realloc(arrayInteger, *size);/*Aumentando o tamanho ocupado pelo ponteiro vetor
                                                         com a função realloc que recebe como parâmetro
                                                         um espaço de memória que ira copiar o conteudo
                                                         apontado por este espaço, e um novo tamanho,
                                                         retornando um novo espaço de memória de acordo
                                                         com o tamanho informado e com os conteúdos apontados
                                                         pelo endereço informado*/

            printArrayInteger(arrayInteger, *size);/*Acionando o procedimento que o valor de
                                                    cada posição do vetor*/

            printAdressArrayInteger(arrayInteger, *size);/*Acionando o procedimento que mostra
                                                           o endereço de memória de cada posição
                                                           do vetor*/

        }
        else
            printf("Alocação de memória do vetor falhou.\n");
    }
    else
        printf("Alocação de memória do ponteiro falhou.\n");

    return 0;
}
