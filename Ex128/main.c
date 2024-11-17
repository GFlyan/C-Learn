#include <stdio.h>
#include <stdlib.h>

/*
Exercício 128: String

->Uma string nada mais é que uma cadeia de caractéres;
->É um vetor de caractéres;

*/


int main()
{
    char word[] = {"Hello world!"};/*Criando um vetor de caractéres que irá receber
                                     uma cadeia de caractéres(string), diferentemente
                                     de caractéres que devem ser fornecidos entre
                                     áspas simples(''), uma string deve ser fornecida
                                     entre áspas duplas("")*/

                                   /*O tamanho do array não foi definido pois uma quantidade
                                     específica de posições já é atribuida automaticamente
                                     devido a quantidade de caractéres que formam a
                                     string.*/


    printf("%s", word);//A máscara referente as strings é %s
    return 0;
}
