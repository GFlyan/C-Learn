#include <stdio.h>
#include <stdlib.h>

/*
Exercício 224: Empilhando

->push
*/

typedef struct no/*Criando um nó para a estrutura de dados pilha
                   sendo que cada nó possui um conteúdo e o endereço
                   do próximo nó*/
{
    int value;//Conteúdo/valor de cada nó
    struct no *proximo;/*Endereço do próximo nó*/
}No;

No* empilhar(No *topo)//Para empilhar é preciso sabe o topo da pilha
{
    No *novo = malloc(sizeof(No));//Criando um novo nó e alocando memória para ele

    if(novo)//Caso a alocação de memória para o ponteiro tenha dado certo
    {
        printf("Informe um valor: ");

        scanf("%d", novo->value);//Atribuindo um conteúdo para o novo nó

        novo->proximo = topo;/*Definindo o próximo nó, caso seja o primeiro conteúdo, recebe null,
                               caso seja outro conteúdo recebe o endereço do conteúdo antigo*/

        return novo;//Retornando o endereço alocado para o topo
    }
    else
        printf("\nAlocação de memória falhou.\n");
    return NULL;
}


int main()
{
    No *topo = NULL;//Atribuindo nulo ao conteúdo do ponteiro struct
    topo = empilhar(topo);//Antigo nó recebe um novo nó
    printf("Hello world!\n");
    return 0;
}
