#include <stdio.h>
#include <stdlib.h>


/*Exercício 342: SYMBOL TABLE - LINKED LIST

Uma ST armazena dados que chamamos de itens, a partir
do ID (Key) de cada item, sendo que os itens podem
ter também dados (Data) associados a eles.

Vantagem:

    Inserção dinâmica, ou seja, não é limitada
    pelo tamanho do array como nos casos passados.

Desvantagem:

    Grande maioria das operações são de custo O(n) devido
    a impossibilidade de acesso direto por índice:

        Inserção no inicio O(1)
        Inserção no meio O(n/2)
        Inserção no final O(n)
        Remover no inicio O(1)
        Remover no meio O(n/2)
        Remover no final O(n)
        Busca em lista ordenada/desordenada O(n)
        Ordenação O(n)
*/
int main()
{
    printf("Hello world!\n");
    return 0;
}
