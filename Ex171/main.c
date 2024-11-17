#include <stdio.h>
#include <stdlib.h>

/*
Exercício 171: Imprimindo um triângulo:

   *
  **
 ***
****

*/



int main()
{
    int base, firstCounter, secondCounter, spaceAmount;/*Criando variáveis que reberão o valor da base
                                                         do triângulo a ser imprimido, dois contadores
                                                         referentes a for diferentes, e um contador
                                                         referente a quantidade de espaços que devem ser
                                                         impressas*/
    printf("Informe um valor para a base do triângulo: ");
    scanf("%d", &base);//Atribuindo o valor da base do triângulo

    for(firstCounter = 1; firstCounter <= base; firstCounter++)//Percorrendo cada linha do triângulo
    {
        for(spaceAmount = base-firstCounter; spaceAmount != 0; spaceAmount--)//Mostrando a quantidade de espaços
        {
            printf(" ");
        }
        for(secondCounter = firstCounter; secondCounter != 0; secondCounter--)//Mostrando a quantidade de *
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
