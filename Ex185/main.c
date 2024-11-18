#include <stdio.h>
#include <stdlib.h>

/*
Exercício 185: Memória de um ponteiro

->Por armazenar um espaço de memóra um ponteiro sempre vai valer 8 bytes
*/

int main()
{
    int *intP;//Criando um ponteiro do tipo int
    printf("Tamanho do intP: %d\n", sizeof(intP));
    float *floatP;//Criando um ponteiro do tipo float
    printf("Tamanho do floatP: %d\n", sizeof(floatP));
    char *charP;//Criando um ponteiro do tipo char
    printf("Tamanho do charP: %d\n", sizeof(charP));
    double *doubleP;//Criando um ponteiro do tipo double
    printf("Tamanho do doubleP: %d\n", sizeof(doubleP));
    return 0;
}
