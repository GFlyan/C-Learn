#include <stdio.h>
#include <stdlib.h>

//Exercício 009: fgetc()

int main()
{
    char caractere; //Criando uma variável do tipo char
    printf("Digite um caractére: ");
    caractere = fgetc(stdin);/*Similar a função getc(), a função fgetc() serve
                               para armazenar caractéres em variáveis char e precisa
                               do parâmetro de entrada, no caso da entrada padrão: stdin,
                               o f de 'f'getc() está relacionado à "file" -> "arquivos",
                               logo a mesma pode ler arquivos também.*/
    printf("O caractére digitado foi: %c", caractere);
    return 0;
}
