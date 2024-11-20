#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 199: Alocação de um vetor dinâmico

->Alocar memória de forma dinâmica para um vetor pode ser mais eficiente
e causar menos bugs futuramente diferentemente da alocação estática
*/

int main()
{
    int *arrayInteger, size;/*Criando um ponteiro que terá seu conteúdo (espaço de memória)
                              alocado dinamicamente, e uma variável que irá representar o
                              tamanho de um vetor*/
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);//Atribuindo a variável o tamanho do vetor
    arrayInteger = malloc(size * sizeof(int));/*Alocando memória para um vetor de forma dinâmica
                                                É possível utilizar a função calloc também*/


    if(arrayInteger)//Caso a alocação de memória tenha dado certo
    {
        printf("Alocação de memória bem sucedida.\n");
        srand(time(NULL));//Definindo o tempo como semente da função rand
        for(int c= 0; c<size;c++)//Percorrendo o vetor
        {
            *(arrayInteger+c) = rand();//Gerando números aleatórios para cada posição do vetor
        }

        for(int c= 0; c<size;c++)//Percorrendo o vetor
        {
            if(c==0)
                printf("[");
            if(c==size-1)
                printf("%d]", *(arrayInteger+c));/*Mostrando o conteudo apontado pelo ultimo espaço
                                                   de memória do ponteiro vetor*/
            else
                printf("%d, ", *(arrayInteger+c));/*Mostrando os conteúdos apontados por cada
                                                    espaço de memória do ponteiro vetor exceto
                                                    o último*/
        }
        }
        else
            printf("Alocação de memória falhou.\n");
    return 0;
}
