#include <stdio.h>
#include <stdlib.h>

/*
Exercício 195: Considere a seguinte declaração: int A, *B, **C, ***D;
Escreva um programa que leia a variável A e calcule e exiba o dobro,
o triplo e o quadruplo desse valor utilizando  apenas os ponteiros
B, C e D. O ponteiro B deve ser usado pra calcular o dobro, C o
triplo e D o quadruplo
*/

int main()
{
    int A, *B, **C, ***D;//Definindo uma variável, um ponteiro simples, duplo e triplo, todos do tipo int
    B = &A;/*Conteúdo:

             -Endereço de memória da variável A

             Aponta 1 conteúdo:

             1̣º Valor contido na variável A (*) */

    C = &B;/*Conteúdo:

             -Endereço de memória do ponteiro B

             Aponta 2 conteúdos:

             1̣º Conteúdo do ponteiro B (endereço de A) (*)
             2̣º Conteúdo apontado pelo ponteiro B (valor de A) (**) */

    D = &C;/*Conteúdo:

             -Endereço do ponteiro C

             Aponta 3 conteúdos:

             1̣º Conteúdo do ponteiro C (endereço de B) (*)
             ̣2º Conteúdo do ponteiro B (endereço de A) (**)
             ̣3º Conteúdo apontado pelo ponteiro B (valor de A) (***) */



    printf("Informe um valor: \n");
    scanf("%d", &A);//Atribuindo a variável A um valor pelo teclado
    printf("Dobro: %d\n", *B*2);//Dobrando o conteúdo apontado por B (B->A)
    printf("Triplo: %d\n", **C*3);//Triplicando o conteúdo apontado por C (C->B->A)
    printf("Quadruplo: %d\n", ***D*4);//Quadruplicando o conteúdo apontado por D (D->C->B->A)
    return 0;
}
