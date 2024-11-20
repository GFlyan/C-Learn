#include <stdio.h>
#include <stdlib.h>

/*
Exercício 225: Desempilhando

->pop
*/

typedef struct no//Criando uma estrutura do tipo nó que contem um valor e o endereço do antigo nó
{
    int value;//COnteúdo do nó
    struct no *proximo;//Endereço do próximo nó
}No;

No* desempilhar(No **topo)/*Recebe um endereço de memória que tem como conteúdo um endereço de memória,
                            ou seja, recebe um endereço de um ponteiro com conteúdo (que também
                            é um endereço de memória)*/
{
    if(*topo != NULL)//Se o conteúdo do ponteiro passado como parâmetro não for vazio
        No *remover = *topo;//Atribuindo o endereço que será removido
        *topo = topo->proximo;/*Antes de remover, atribuindo o endereço do próximo
                                elemento ao que será removido, como sendo o o topo*/

        return remover;
    else
        printf("Pilha vazia")
    return NULL;
}


int main()
{
    No *topo = NULL;//Criando um ponteiro do tipo struct e atribuindo como conteúdo uma região de memória vazia para esse ponteiro
    No *remover = remover(&topo);//Criando um ponteiro struct e atribuindo a ele um elemento removido
    if(remover)
        printf("Elemento removido: %d\n", remover->value);
    else
        printf("Sem nó a remover.\n");
    printf("Hello world!\n");
    return 0;
}
