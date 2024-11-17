#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 168: Como preencher os campos de uma struct por dados fornecidos pelo teclado
*/

typedef struct//Criando um tipo de dado que se refere à informações sobre uma pessoa
{
    char name[100];//Campo referente ao nome da pessoa
    int age;//Campo referente a idade da pessoa
}Person;//Nome da struct



int main()
{

    Person pessoa;//Criando uma variavel do tipo Person(struct)

    printf("Informe o nome: ");
    fgets(pessoa.name, 100, stdin);//Atribuindo ao campo name(string) da variável pessoa um valor através do teclado
    printf("Informe a idade: ");
    scanf("%d", &pessoa.age);//Atribuindo ao campo age(int)da variável pessoa um valor através do teclado
    printf("Olá %sVocê tem %d anos!", pessoa.name, pessoa.age);

    return 0;
}
