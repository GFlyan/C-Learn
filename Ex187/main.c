#include <stdio.h>
#include <stdlib.h>

/*
Exercício 187: Ponteiro como parâmetro de função/procedimento
*/

void duplicateValue(int *p)/*Recebe como parâmetro um endereço de memória físico através de um
                             ponteiro, onde o valor apontado será duplicado*/
{
    *p *= 2;
}
int main()
{
    int num;//Criando uma variável que irá receber um valor inteiro informado pelo usuário
    printf("Informe um valor inteiro: ");
    scanf("%d", &num);//Atribuindo a variável um valor informado pelo usuário
    duplicateValue(&num);//Acionando o procedimento que muda o conteúdo da variável através do endereço de memoria físico
    printf("O dobro do valor da variável é: %d", num);
    return 0;
}
