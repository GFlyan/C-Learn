#include <stdio.h>
#include <stdlib.h>

/*
Exercício 184: Ponteiros

->Um ponteiro é uma variável que armazena um endereço de memória de outra variável

->Para criar um ponteiro utiliza-se:

tipoPrimitivo *nomePonteiro = &variávelMesmoTipo;

->Um ponteiro possui 3 atributos

1°Um endereço de memória próprio (&)
2°Um conteúdo que será o endereço de memória da variável apontada
3°Um conteúdo apontado que será o conteúdo da variavel apontada (*)
*/


int main()
{
    int num = 10;/*Computador separa uma região na memória pra armazenar
                   o conteúdo da variável, sendo que toda variável possui
                   um endereço único na memória, onde no caso de arrays
                   são endereços sequênciais*/

    int *p = &num;//Ponteiro que armazena o endereço de memória da variável referente

    printf("O conteúdo da variável num é: %d\n", num);
    printf("O endereço de memória da variável num é: %p\n", &num);/*%p é a máscara de endereço de memória
                                                                sendo que o & refere-se ao próprio
                                                                endereço de memória*/

    printf("O conteúdo do ponteiro é: %p\n", p);//Conteúdo de p informa o endereço de memória da variável apontada
    printf("O valor apontado é: %d\n", *p);//Valor apontado por p informa o conteúdo da variável apontada
    printf("O endereço do ponteiro é: %p\n", &p);/*Endereço de memória do ponteiro é um
                                                  espaço na memória como qualquer qualquer
                                                  outra variável*/
    return 0;
}
