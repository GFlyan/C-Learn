#include <stdio.h>
#include <stdlib.h>

/*
Exercício 102: Como alterar o conteúdo de um vetor(array)

->Podemos alterar o conteúdo de um vetor tanto pelo teclado, quanto pelo código.
*/

int main()
{
    int amountPosition;//Definindo uma variável que irá armazenar quantas posições terá o vetor
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &amountPosition);
    int arrayInteger[amountPosition];//Criando um vetor com a quantidade de posições fornecidas pela variável recém mencionada

    for(int counter = 0; counter < amountPosition; counter++)//Percorrendo o vetor para preenche-lo
    {
        printf("Forneça o valor da posição %d do vetor: ", counter);
        scanf("%d", &arrayInteger[counter]);//Atribuindo um valor pelo teclado à cada posição do vetor
    }

    printf("\nConteúdo do vetor:\n");
    for(int counter = 0; counter < amountPosition; counter++)//Percorrendo o vetor para revelar seu conteúdo
    {
        printf("%d ", arrayInteger[counter]);
    }

    int userChangePosition;/*Definindo a variável que receberá a posição qual o
                             usuário deseja alterar o conteúdo*/

    printf("\nInforme uma posição para mudar o valor: ");
    scanf("%d", &userChangePosition);//Atribuindo a posição que receberá a alteração
    printf("Informe um valor para preencher a posição %d: ", userChangePosition);
    scanf("%d", &arrayInteger[userChangePosition]);//Atribuindo à posição do vetor informada, um novo valor

    for(int counter = 0; counter < amountPosition; counter++)//Percorrendo o vetor para dobrar o valor de cada posição
    {
        arrayInteger[counter] *= 2;//Dobrando os valores de cada posição do vetor
    }


    printf("\nConteúdo do vetor:\n");
    for(int counter = 0; counter < amountPosition; counter++)//Percorrendo o vetor para revelar seu conteúdo
    {
        printf("%d ", arrayInteger[counter]);
    }

    return 0;
}
