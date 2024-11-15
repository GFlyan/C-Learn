#include <stdio.h>
#include <stdlib.h>

/*
Exercício 153: Recursão

->Um processo recursivo é aquele que chama a si mesmo

->Em um processo recursivo é necessário que exista um ponto de parada,
pois por se tratar um de um processo realizado sequencialmente é necessário
que exista um fim senão o processo se tornará um loop infinitoseguintes

->Cada chamada recursiva é empilhada e no momento que é antingido o ponto de parada
começa o desimpilhamento

Crie uma função recursiva que mostre os números de forma decrescente e outra que mostra de forma crescente

*/
void showDown(int value)/*Criando uma função que irá imprimir de forma decrescente os valores
                       seguintes de um dado valor informado através dos parâmetros*/
{
    if(value==0)//Ponto de parada da chamada do processo recursivo
        printf("%d", value);
    else
    {
        printf("%d ", value);
        showDown(value-1);//Utilizando a recursão para mostrar e diminuir o valor estabelecido como parâmetro
    }
}

void showUp(int value)/*Criando uma função que irá imprimir de forma crescente os valores
                       seguintes de um dado valor informado através dos parâmetros*/
{
    if(value==0)//Ponto de parada da chamada do processo recursivo
        printf("%d ", value);
    else
    {
        showUp(value-1);//Utilizando a recursão para diminuir o valor estabelecido como parâmetro
        printf("%d ", value);/*Após a ultima recursão através do desempilhamento, a função printf
                               irá funcionar e imprimir os valores de forma crescente*/

    }
}
int main()
{
    int userValue;//Criando uma variável que armazernará um valor informado pelo usuário
    printf("Informe um valor: ");
    scanf("%d", &userValue);//Atribuindo pelo teclado um valor à variável

    printf("Valores decrescentes:\n");
    showDown(userValue);/*Fornecendo como parâmetro a variável que contem o valor escolhido
                        pelo usuário para a função que imprime de forma decrescente os valores*/
    printf("\n");
    printf("Valores decrescentes:\n");
    showUp(userValue);/*Fornecendo como parâmetro a variável que contem o valor
                        escolhido pelo usuário para a fução que imprime de forma crescente
                        os valores*/
    return 0;
}
