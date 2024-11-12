#include <stdio.h>
#include <stdlib.h>

//Exercício 006: Variáveis char

int main()
{
    //Variáveis do tipo char servem para armazenar caractéres
    char letra = 'A'; //Atribuindo à uma variável do tipo char um caractére, é necessário que o mesmo esteja entre aspas simples;
    printf("O caractére é: %c\n", letra); //A mascara referente à variáveis char é %c
    printf("Digite um caractére: ");
    scanf("%c", &letra); //Solicitando um novo valor à ser atribuido na variável char
    printf("O caractére digitado foi: %c", letra);
    return 0;
}
