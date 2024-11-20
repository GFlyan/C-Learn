#include <stdio.h>
#include <stdlib.h>

/*
Exercício 197: Função malloc()

->malloc = memory alloc = alocação de memória

->Possui 2 retornos:

1° Retorna um ponteiro pra região de memória alocada
2° Retorna NULL (ponteiro nulo) caso não seja possui concluir a alocação de memória

O retorno pode ser NULL quando a alocação de memória falha, normalmente quando a alocação
é muito grande e o computador em questão não consegue alocar a quantidade de memória desejada.
*/

/*malloc pode ser utilizada quando um ponteiro não recebe um endereço de memória de uma variável,
ficando assim necessitado de um endereço de memória, sendo então fornecido pela função malloc **/


int main()
{
    int integerVariable;//Criando uma variável de forma estática (alocando memória de forma estática)

    //Alocando memória de forma dinâmica
    int *any;//Criando um ponteiro (que recebe um endereço de memória)

    any = malloc(sizeof(int));/*Atribuindo ao conteúdo do ponteiro um endereço de memória fornecido
                                pelo retorno de malloc que recebe como parâmetro um tamanho em bits,
                                reservando um endereço de memória baseado na quantidade de bits
                                fornecidos*/

    if(any)//Caso a alocação de memória tenha dado certo
    {
        printf("Alocação de memória bem sucedida.\n");
        printf("Informe um valor: ");
        scanf("%d", any);/*Atribuindo um valor para o conteúdo apontado pelo
                           ponteiro, cujo tem como conteúdo um endereço de
                           memória fornecido por malloc*/
        printf("O conteúdo do ponteiro é: %p\nO conteúdo apontado é: %d\n", any, *any);
    }
    else
        printf("Alocação de memória falhou.\n");
    return 0;
}
