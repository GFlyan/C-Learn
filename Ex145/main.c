#include <stdio.h>
#include <stdlib.h>

/*
Exercício 145: Funções e procedimentos

->Uma função retorna algum valor através do return

->Um procedimento não retorna nada e é iniciado por void

*/
/*
Para criar uma função:

tipoPrimitivo nomeFunção(argumentos)
{
    ...
    return valorMesmoTipoPrimitivo;
}

Para criar um procedimento:

void nomeProcedimento(argumentos)
{
    ...
}

*/



void showHelloWorld()//Criando um procedimento que tem como funcionalidade apenas printar "Hello World!"
{
    printf("Hello World!\n");
}

int yearToMonth(int year)/*Criando uma função que tem a funcionalidade de converter
                            a quantidade de anos informadas através de argumento
                            em meses*/
{
    return 12*year;
}

int main()
{
    showHelloWorld();//Acionando o procedimento que informa "Hello World!"
    printf("Informe uma quantidade de anos para ser convertido em quantidade de meses: ");
    int userValue;//Criando a variável que armazenará o valor informado pelo usuário
    scanf("%d", &userValue);/*Atribuindo uma quantidade de anos informada pelo usuário
                              à uma variável*/
    printf("A quantidade de meses é: %d", yearToMonth(userValue));//Mostrando a quantidade de anos convertida em meses
    return 0;
}
