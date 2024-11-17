#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 172: Passando struct como parâmetro de procedimentos(void)
*/

typedef struct//Criando uma struct que diz respeito aos dados de uma pessoa
{
    char name[100];//Campo que diz respeito ao nome da pessoa
    int age;//Campo que diz respeito a idade da pessoa
    float width;//Campo que diz respeito a altura da pessoa
}Person;

void printPerson(Person person)//Procedimento que irá imprimir detalhadamente os dados da pessoa
{
    printf("**************************\n");
    printf("O nome da pessoa é: %s\n", person.name);//Mostrando o nome da pessoa
    printf("A idade da pessoa é: %d\n", person.age);//Mostrando a idade da pessoa
    printf("A altura da pessoa é: %.2f\n", person.width);//Mostranod a altura da pessoa
    printf("**************************\n");
}

int main()
{
    Person person;//Criando uma variável do tipo Person(struct)
    printf("Informe um nome: ");
    fgets(person.name, 100, stdin);//Armazenando um nome ao campo name da variável person
    printf("Informe uma idade: ");
    scanf("%d", &person.age);//Armazenando uma idade ao campo age da variável person
    printf("Informe uma altura: ");
    scanf("%f", &person.width);//Armazenando uma altura ao campo width da variável person

    printPerson(person);//Acionando o procedimento que informa os dados referentes a pessoa


    return 0;
}
