#include <stdio.h>
#include <stdlib.h>

/*
Exercício 101: Como preencher um array(vetor) fornecendo valores pelo teclado.
*/

int main()
{
    int counter;
    int amountPosition; //Criando uma variável que armazenará a quantidade de posições que o vetor terá
    printf("Informe quantas posições terá o vetor: ");
    scanf("%d", &amountPosition); //Atribuindo a quantidade de posições que o vetor terá à uma variável
    int arrayInteger [amountPosition]; /*Criando um vetor de números inteiros à ser preenchido
                                         É necessário estabelecer o tamanho do vetor*/

    for( counter = 0; counter<amountPosition; counter++)//Percorrendo o vetor
    {
        printf("Informe o valor da posição %d: ", counter);
        scanf("%d", &arrayInteger[counter]);/*Atribuindo um valor a cada posição do vetor,
                                             necessário informar o endereço de memória com
                                             &*/
    }

    printf("\nConteúdo do vetor:\n\n");
    for( counter = 0; counter < amountPosition; counter++)//Percorrendo o vetor para revelar seu conteúdo
    {
        printf("%d ", arrayInteger[counter]);
    }
    return 0;
}
