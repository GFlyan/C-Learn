#include <stdio.h>
#include <stdlib.h>

/*
Exercício 100: Como imprimir o conteúdo de um vetor(array).
*/


int main()
{
    float arrayFloat [] = {7.0, 7.1, 7.2, 7.3, 7.4, 7.5}; /*Criando um vetor do tipo float que contém 6
                                                           posições com conteúdo definido*/

    for(int counter = 0; counter<6; counter++){ //Percorrendo cada posição do vetor

        printf("Posição %d: %.2f\n", counter, arrayFloat[counter]); /*Para imprimir o conteúdo de um vetor deve-se percorrer posição
                                             por posição e imprimir utilizando a máscara referente ao tipo
                                             primitivo do vetor imprimindo assim o conteúdo de cada posição*/
    }


    return 0;
}
