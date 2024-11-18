#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 175: Array multidimensional do tipo struct

->Lembrando como criar um array multidimensional de qualquer tipo:

tipoPrimitivo nomeArray[numeroLinhas][numeroColunas]

->Para criar um array multidimensional com struct:

tipoStruct nomeArray[numeroLinhas][numeroColunas]

Onde existirá x linhas, y colunas, sendo que x diz
respeito à um grupo, e y os participantes desse grupo
*/

typedef struct//Criando uma estrutura que diz respeito aos dados de uma pessoa
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
    printf("\t\tInforme um nome: ");
    fgets(person.name, 100, stdin);//Armazenando um nome ao campo name da variável person
    person.name[strcspn(person.name, "\n")] = '\0';/*Retira o caractére de quebra de linha que é retornado
                                                     junto a função fgets*/
    printf("\t\tInforme uma idade: ");
    scanf("%d", &person.age);//Armazenando uma idade ao campo age da variável person
    printf("\t\tInforme uma altura: ");
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
    int amountGroup, amountPeople;/*Criando duas variáveis onde cada uma receberá
                                    valores que serão usados para criar um array
                                    multidimensional*/
    printf("São quantos grupos? ");
    scanf("%d", &amountGroup);/*Atribuindo um valor que será utilizado como quantidade
                                de linhas em um array mutlidimensional*/
    printf("Quantos integrantes tem em cada grupo? ");
    scanf("%d", &amountPeople);/*Atribuindo um valor para que será utilizado
                                 como quantidade de colunas em um array
                                 multidmensional*/
    Person groupPeople[amountGroup][amountPeople];/*Criando um array multidimensional que tem tantas linhas e
                                                    tantas colunas onde cada linha corresponde à um grupo e cada
                                                    coluna aos integrantes desse grupo*/

    for(int line = 0; line<amountGroup; line++)//Percorrendo cada linha do array multidimensional
    {
        printf("--------------------------\n");
        printf("%dº Grupo:\n", line+1);
        printf("--------------------------\n");
        for(int column = 0; column<amountPeople; column++)//Percorrendo cada coluna do array multidimensional
        {
            printf("\t%dª Pessoa:\n", column+1);
            groupPeople[line][column] = insertPerson();//Inserindo integrantes em cada posição do array multidimensional
        }

    }
    for(int line = 0; line<amountGroup; line++)//Percorrendo cada linha do array multidimensional
        {
        printf("--------------------------\n");
        printf("%dº Grupo:\n", line+1);
        printf("--------------------------\n");
        for(int column = 0; column<amountPeople; column++)//Percorrendo cada coluna do array multidimensional
        {
            printf("\t%dª Pessoa:\n", column+1);
            printPerson(groupPeople[line][column]);/*Acionando o procedimento para mostrar
                                                     cada pessoa inserida no array multidimensional*/
        }

    }

    return 0;
}
