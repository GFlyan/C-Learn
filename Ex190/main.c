#include <stdio.h>
#include <stdlib.h>

/*
Exercício 190: Ponteiro para struct

->Manipulação direta de uma variável do tipo struct, utiliza-se . para acessar os campos

->Manipulaçãp indireta de uma variável do tipo struct com um ponteiro do tipo struct,
utiliza-se -> para acessar o conteúdo do campo apontado
*/

typedef struct{//Criando uma estrutura que diz respeito à uma data
    int day;//Campo que diz respeito ao dia
    int month;//Campo que diz respeito ao mês
    int year;//Campo que diz respeito ao ano
}Data;

void printData(Data *p){/*Criando um procedimento que recebe como parametro um ponteiro do tipo Data
                          (endereço de memória de uma variável do mesmo tipo), para imprimir o conteúdo
                          apontado dos campos desse ponteiro*/

    printf("%d/%d/%d\n", p->day, p->month, p->year);/*Por se tratar de um ponteiro de struct, para imprimir o conteúdo apontado
                                                      utiliza-se -> para se referir a cada campo*/

}

int main()
{
    Data today;//Criando uma variável do tipo Data

    today.day = 18;//Atribuindo um valor ao campo day da variável do tipo Data
    today.month = 11;//Atribuindo um valor ao campo mês da variável do tipo Data
    today.year = 2024;//Atribuindo um valor ao campo ano da variável do tipo Data

    Data *p;/*Criando um ponteiro do tipo Data, ressaltando que
              um ponteiro armazena um endereço de memória*/

    p = &today;/*Armazenando no ponteiro do tipo Data o endereço de memória
                 da variável do tipo Data*/

    printData(&today);/*Acionando o procedimento que recebe como parâmetro
                   um ponteiro do tipo Data, onde é impresso o conteúdo
                   de cada campo apontado*/

    return 0;
}
