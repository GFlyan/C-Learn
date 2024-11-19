#include <stdio.h>
#include <stdlib.h>

/*
Exercício 193: Escreva um procedimento que troca os valores dos parâmetros recebidos.
Sua assinatura deve ser: void troca(float*a, float *b);
*/

void troca(float *a, float *b){/*Criando um procedimento que recebe como parâmetro dois endereços de memória,
                                 com isso, aponta dois conteúdo diferente onde troca os valores entre si*/

 float copy = *a;//Criando uma variável que recebe um conteúdo apontado
 *a = *b;//Trocando o conteúdo apontado por outro conteúdo apontado
 *b = copy;//Trocando o conteúdo apontado por um conteúdo armazenado

}

int main()
{
    float firstValue, secondValue;//Criando duas variáveis float
    printf("Informe o primeiro valor: ");
    scanf("%f", &firstValue);//Atribuindo um valor a variável
    printf("Informe o segundo valor: ");
    scanf("%f", &secondValue);//Atribuindo um valor a variável
    troca(&firstValue, &secondValue);/*Acionado o procedimento que recebe como parâmetro
                                       o endereço de duas variáveis e altera o conteúdo
                                       delas entre si*/
    printf("O primeiro valor agora vale: %.2f\n", firstValue);
    printf("O segundo valor agora vale: %.2f\n", secondValue);
    return 0;
}
