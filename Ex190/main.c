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

void printData(Data *pData){/*Criando um procedimento que recebe como parametro um ponteiro do tipo Data
                          (endereço de memória de uma variável do mesmo tipo), para imprimir o conteúdo
                          apontado dos campos desse ponteiro*/

    printf("%d/%d/%d\n", pData->day, pData->month, pData->year);/*Por se tratar de um ponteiro de struct, para imprimir o conteúdo apontado
                                                      utiliza-se -> para se referir a cada campo e remove o asterísco */

}

void printYesterday(int *pInt, Data *pData)/*Criando um procedimento que recebe um ponteiro
                            primitivo como parâmetro que tem seu conteúdo
                            apontado para uma variável primitiva, e um
                            ponteiro struct que tem seu conteúdo apontado
                            para os campos da struct*/
{
    printf("%d/%d/%d\n", *pInt, pData->month, pData->year);/*Note que por se tratar de um ponteiro primitivo,
                                                            para acessar o conteúdo apontado utiliza-se o *,
                                                            e no caso do ponteiro struct utiliza-se -> */
}

int main()
{
    Data today;//Criando uma variável do tipo Data


    today.day = 18;//Atribuindo um valor ao campo day da variável do tipo Data
    today.month = 11;//Atribuindo um valor ao campo mês da variável do tipo Data
    today.year = 2024;//Atribuindo um valor ao campo ano da variável do tipo Data

    Data *pData;/*Criando um ponteiro do tipo Data, ressaltando que
              um ponteiro armazena um endereço de memória*/

    pData = &today;/*Armazenando no ponteiro do tipo Data o endereço de memória
                 da variável do tipo Data*/


    int yesterday;//Criando uma variável que diz respeito ao próximo dia da data informada

    yesterday = pData->day + 1;/*Por estar acessando um conteúdo apontado por um ponteiro struct utiliza-se ->*/

    int *pInt;//Criando um ponteiro inteiro

    pInt = &yesterday;/*O ponteiro inteiro recebe o endereço de memória de uma variável
                        sendo possível acessar o conteúdo apontado deste ponteiro*/

    printData(pData);/*Acionando o procedimento que recebe como parâmetro
                   um ponteiro do tipo Data, onde é impresso o conteúdo
                   de cada campo apontado*/

    printYesterday(pInt, pData);/*Acionando o procedimento que recebe como parâmetro
                                  um ponteiro primitivo que aponta o conteúdo que diz
                                  respeito ao dia seguinte do conteúdo contido
                                  no campo day da struct Data, e um ponteiro struct data,
                                  que tem como conteúdo o endereço de memória do tipo Data,
                                  e conteúdo apontado para os campos da struct Data*/
    return 0;
}
