#include <stdio.h>
#include <stdlib.h>

/*
Exercício 191: Ponteiro para ponteiro

->Um ponteiro para um ponteiro possui 4 atributos:

1ºUm endereço próprio de memória (&)
2ºUm conteúdo, que será o endereço de memória de outro ponteiro
3°Um primeiro conteúdo apontado que será o endereço de memória da variável apontada pelo primeiro ponteiro (*)
4°Um segundo conteúdo apontado que será o conteúdo da variável apontada pelo primeiro ponteiro (**)
*/

int main()
{
    int number = 100;//Criando uma variável int que recebe um valor
    int *p1;//Criando um ponteiro int que recebe um endereço de memória de uma variável int
    int **p2;/*Criando um ponteiro int duplo que recebe o endereço de memória de um ponteiro
               cujo o conteudo apontado é o endereço de memória da variável*/

    p1 = &number;/*Ponteiro cujo conteúdo é o endereço de memória
                   da variável apontada, e aponta o valor armazenado
                   nesta variável*/

    p2 = &p1;/*Ponteiro que recebe o endereço de outro ponteiro que contém o
               endereço físico de uma variável. Este ponteiro tem 1 conteúdo
               e 2 apontações:

               Conteúdo:

               Endereço de memória do primeiro ponteiro;

               Conteúdos apontados:

               1° Conteúdo do primeiro ponteiro(endereço da variável) *
               2° Conteúdo apontado pelo primeiro ponteiro(conteúdo da variável) **
               */

    printf("--------------------------------------------------\n");
    printf("Endereço da variável: %p\nConteúdo da variável: %d\n", &number, number);
    printf("--------------------------------------------------\n");
    printf("Endereço do primeiro ponteiro: %p\nConteúdo do primeiro ponteiro: %p\nConteúdo apontado pelo primeiro ponteiro: %d\n", &p1, p1, *p1);
    printf("--------------------------------------------------\n");
    printf("Endereço do segundo ponteiro: %p\nConteúdo do segundo ponteiro: %p\nPrimeiro conteúdo apontado pelo segundo ponteiro: %p\nSegundo conteúdo apontado pelo segundo ponteiro: %d\n", &p2, p2, *p2, **p2);
    printf("--------------------------------------------------\n");
    return 0;
}
