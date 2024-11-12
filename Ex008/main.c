#include <stdio.h>
#include <stdlib.h>

//Exercício 008: getc()

int main()
{
    char caractere; //Criando um variável do tipo char
    printf("Digite um caractére: ");
    caractere = getc(stdin); /*A função getc() funciona similarmente a função getchar(),
                               que a mesma tem funcionalidade de armazenar em variáveis char
                               o valor fornecido pelo teclado, entretando getc() precisa do parâmetro
                               de entrada de dados, onde o teclado é a entrada padrão representado
                               pela variável do sistema stdin. */
    printf("O caractére digitado é: %c", caractere);
    return 0;
}
