#include <stdio.h>
#include <stdlib.h>

/*
Exercício 099: Como criar um vetor(array).
*/

int main()
{
    /*tipo nomeVetor[tamanhoVetor]
    -> Cria um vetor com tamanho pré-determinado*/
    int idades[2];
    idades[0] = 2;
    idades[1] = 7;
    printf("Idade 1: %d\nIdade 2: %d\n", idades[0], idades[1]);

    /*tipo nomeVetor[] = {x1,x2, ..., xn}
    -> Cria um vetor com tamanho determinado pela quantidade de elementos do conjunto fornecido*/
    float peso[] = {73.5, 62.8};
    printf("Peso 1: %.2f\nPeso 2: %.2f\n", peso[0], peso[1]);

    /*tipo nomeVetor[tamanhoVetor] = {x1, x2, ..., xn}
    -> O vetor será preenchido sequencialmente, caso o conjunto fornecido seja menor
    que o tamanho do vetor, as posições quais não foram preenchidas receberão 0*/
    int exemplo [4] = {1, 2};
    for(int c = 0; c<4; c++){
        printf("%d", exemplo[c]);
    }

    return 0;
}
