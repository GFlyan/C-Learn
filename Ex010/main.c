#include <stdio.h>
#include <stdlib.h>

//Exercício 010: Lendo vários valores com scanf()

int main()
{
    int value1, value2, value3; //Criando variáveis do tipo int
    printf("Digite 3 valores (separados por espaço): ");
    scanf("%d%d%d", &value1, &value2, &value3); /*Para ler vários valores e atribuir em variáveis
                                                  com a função scanf(), basta utilizar a mascára +
                                                  referencia do endereço físico de memória da variável,
                                                  de forma similar ao código exemplo.*/
    printf("Valor 1: %d\nValor 2: %d\nValor 3: %d", value1, value2, value3);
    return 0;
}
