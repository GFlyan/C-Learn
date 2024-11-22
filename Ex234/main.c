#include <stdio.h>
#include <stdlib.h>

/*
Exercício 234: Filas

->Estrutura necessária sempre que a prestação de serviço é mais lenta que a demanda,
gerando assim um acúmulo por ordem de chegada.

->Representa um enfileiramento de dados

->Operações de inserção e remoção:

    Inserção no final da fila
    Remoção no início da fila

->FIFO - First In First Out - primeiro a entrar é o primeiro a sair
->Primeiro nó a entrar ná fila é o primeiro nó a sair

->Ponteiro para o próximo nó sendo o nó final da fila é NULL
->Ponteiro para o próximo nó sendo o primeiro ou outros nós exceto o último
recebe o endereço de memória que é o conteúdo do ponteiro proximo nó

Os nós de filas recebem a mesma estrtura dos nós de pilhas

typedef struct node
{
    type value;
    struct node *nextNode;
}Node;



*/

int main()
{
    printf("Hello world!\n");
    return 0;
}
