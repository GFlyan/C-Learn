#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 174: Array unidimensional do tipo struct

->Lembrando que para criar um array unidimensional:

tipoPrimitivo nomeArray[tamanhoArray];

->Então para criar um array unidimensional do tipo struct:

nomeStruct nomeArray[tamanhoArray];

Onde cada posição do array terá os campos da struct
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
    scanf("%c");//Limpando o buffer do teclado
    printf("Informe um nome: ");
    fgets(person.name, 100, stdin);//Armazenando um nome ao campo name da variável person
    person.name[strcspn(person.name, "\n")] = '\0';/*Retira o caractére de quebra de linha que é retornado
                                                     junto a função fgets*/
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
    int amountPerson;//Criando uma variável que irá armazenar quantas pessoas serão cadastradas
    printf("Quantas pessoas serão cadastradas? ");
    scanf("%d", &amountPerson);//Atribuindo à variável a quantidade de pessoas que serão cadastradas
    //while (getchar() != '\n');//Limpa buffer do teclado caso scanf("%c"); de core dumped
    Person personArray[amountPerson];/*Criando um vetor com a quantidade de posições referentes a quantidade
                                       de pessoas que serão cadastradas*/

    for(int counter = 0; counter<amountPerson; counter++)//Percorrendo o vetor de pessoas
    {
        printf("%dº Cadastro: \n", counter+1);
        personArray[counter] = insertPerson();/*Atribuindo a cada posição(Person) do vetor personArray um valor(Person)
                                                retornado pela função insertPerson()*/
    }

    for(int counter = 0; counter<amountPerson; counter++)//Percorrendo o vetor de pessoas
    {
        printf("%dº Cadastro: \n", counter+1);
        printPerson(personArray[counter]);//Acionando o procedimento que informa os dados referente aos campos da struct Person
    }
    return 0;
}
