#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 103: Gerando números aleatórios com rand e srand

->rand() é a funçao que gera números aleatórios entretanto possui a mesma semente sempre
->srand() é a função que define a semente
->Passando time(NULL) como parâmetro de srand(), é possivel gerar números aleatórios a cada compilação
*/

int main()
{
    srand(time(NULL));//Definindo a semente geradora
    int num = rand();//Atribuindo um número aleatório a uma variável int
    printf("%d", num);
    return 0;
}
