#include <stdio.h>
#include <stdlib.h>

/*
Exercício 186: Motivo pelo qual não se usa & para armazenar conteúdo em string utilizando scanf()

->O nome de um array é por si só um ponteiro e aponta o conteúdo armazenado nele mesmo
->O endereço do array é o próprio nome do array, que também representa o endereço da primeira
posição do array
*/

int main()
{
    char word[100];//Criando na memória uma string de até 100 caractéres
    printf("Informe uma frase:\n");
    scanf("%100[^\n]", word);//Atribuindo uma frase à string
    printf("A frase contida na string é: '%s'\n", word);
    printf("O endereço da string é: %p\n", word);//Próprio nome da array string é um ponteiro que armazena um emdereço de memória
    printf("O endereço da string é: %p\n", &word);
    printf("O endereço do primeiro caractére da string é: %p\n", &word[0]);

    return 0;
}
