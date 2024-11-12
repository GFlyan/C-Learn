#include <stdio.h>
#include <stdlib.h>

//Exercício 004: Variáveis int e scanf()

int main()
{
    int integerNumber; //Criação de variáveis do tipo inteiro
    integerNumber = 10; //Atribuindo um valor à variável integerNumber
    printf("O valor pré-definido da variável é %d.\n", integerNumber); /*%d e %i (máscaras) são utilizadas para se relacionar
                                                                         à variáveis int*/
    printf("Digite um número: ");
    scanf("%i", &integerNumber); /*Atribuindo um valor à variável userIntegerNumber pelo terminal.
                                   A função scanf() necessita da máscara referencial e o endereço
                                   físico da memória da variável referencial (basta utilizar o
                                   &+variável)*/
    printf("O valor atribuido digitado pelo usuário é %i.\n", integerNumber);
    return 0;
}
