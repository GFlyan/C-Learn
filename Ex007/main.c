#include <stdio.h>
#include <stdlib.h>

//Exercício 007: getchar()

int main()
{
    char caractere; //Criando uma variável do tipo char
    printf("Digite um caractére: ");
    caractere = getchar(); /*Função getchar() serve para armazenar caractéres
                            em variáveis do tipo char*/
    printf("O caractére digitado foi: %c", caractere);
    return 0;
}
