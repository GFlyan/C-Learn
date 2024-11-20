#include <stdio.h>
#include <stdlib.h>

/*
Exercício 198: Alocação dinâmica de memória com a função calloc()

->A função calloc retorna um endereço de memória.

->Recebe dois parâmetros a quantidade de elementos que serão alocados, o tamanho do elemento.
*/

int main()
{
    int *any;//Criando um ponteiro
    any = calloc(1, sizeof(int));/*Armazenando um endereço de memória retornado pela função
                                    calloc no conteúdo do ponteiro, a função calloc recebe
                                    como parâmetros:

                                    1° Quantidade de conteúdos que serão apontado
                                    2° Tamanho em bytes*/

    if(any)//Caso a alocação de memória tenha dado certo
    {
        printf("Alocação de memória bem sucedida.\n");
        printf("Informe um valor: ");
        scanf("%d", any);/*Atribuindo ao conteúdo apontado pelo ponteiro um valor,
                           cujo ponteiro tem como conteúdo um espaço de memória
                           retornado pela função calloc*/
        printf("O conteúdo do ponteiro é: %p\nO conteudo apontado pelo ponteiro é: %d", any, *any);
    }
    else
        printf("Alocação de memória falhou.\n");
    return 0;
}
