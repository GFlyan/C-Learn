#include <stdio.h>
#include <stdlib.h>

/*
Exercício 173: Função que retorna struct

->Lembrando que uma função ela só retorna valores do mesmo tipo da função

int function -> return intValue
char function -> return charValue

->Logo então para criar uma função que retorna struct

typeStruct function -> return typeStructValue

*/

typedef struct //Criando uma struct que diz respeito aos dados de uma pessoa
{
    char name[100];//Campo que diz respeito ao nome da pessoa
    int age;//Campo que diz respeito a idade da pessoa
    float width;//Campo que diz respeito a altura da pessoa
}Person;//Nome da struct

Person insertPerson() /*Criando uma função que irá armazenar os dados referentes aos campos
                        da struct person em uma variável*/
{

    Person person;//Criando uma variável do tipo Person(struct)
    printf("Informe um nome: ");
    fgets(person.name, 100, stdin);//Armazenando um nome ao campo name da variável person
    printf("Informe uma idade: ");
    scanf("%d", &person.age);//Armazenando uma idade ao campo age da variável person
    printf("Informe uma altura: ");
    scanf("%f", &person.width);//Armazenando uma altura ao campo width da variável person
    return person;
}

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
    Person person = insertPerson();/*Criando uma variável do tipo person que irá receber o retorno da função insertPerson
                                    com todos os campos referentes a struct já preenchidos*/

    printPerson(person);//Acionando o procedimento que informa todos os dados da pessoa
    return 0;
}
