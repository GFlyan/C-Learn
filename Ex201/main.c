#include <stdio.h>
#include <stdlib.h>

/*
Exercício 201: Liberação de memória alocada de forma dinâmica com a função free()

->A função free() recebe como parâmetro um endereço de memória a ser liberado.

->É de suma importância a liberação de memória alocada dinâmicamente pois diferentemente
de inicializações estáticas que são encerradas automaticamente ao fim de suas utilizações,
as inicializações dinâmicas perduram podendo causar um acumulo de memória por parte
do programa, ou seja quando um endereço de memória alocado dinâmicamente não for mais
utilizado, utilize a função free();

*/

int main()
{
    int *any, size;//Criando um ponteiro e uma variável
    any = malloc(sizeof(int));//Alocando memória pra este ponteiro tornando possível criar um conteúdo apontado
    printf("Endereço do conteúdo do ponteiro: %p\n", any);//Mostrando o endereço alocado ao ponteiro
    printf("Informe um tamanho: ");
    scanf("%d", &size);//Atribuindo um valor a variável que será usada para novo tamanho de memória ponteiro
    any = realloc(any, size);//Atribuindo um novo tamanho de memória ao ponteiro
    for(int c = 0; c < size; c++)//Percorrendo cada região de memória do ponteiro
        printf("%d endereço: %p\n", c+1, any+c);//Mostrando o endereço de cada região de memória do ponteiro

    free(any);//Liberando a memória do ponteiro

    return 0;
}
