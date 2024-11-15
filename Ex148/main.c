#include <stdio.h>
#include <stdlib.h>

/*
Exercício 148: Escopo e variáveis locais e globais

->O escopo de uma variável diz se ela é uma variável local ou global,
sendo que o escopo será, no caso das variáveis locais, a função qual
a variável pertence, e no caso das variáveis globais, o escopo também
será global

->Uma variável local existe somente dentro de uma função/procedimento,
por ter sido definida dentro do escopo da função/procedimento.

->Uma variável global existe em todas as funções por ter sido definida
no escopo global

->Variáveis locais podem ser alteradas somente em escopos locais, enquanto
variáveis globais podem ser alteradas em qualquer escopo
*/

char name[] = {"Guilherme"};//Criando uma string global que recebe um nome

void changeName()/*Criando um procedimento que irá mudar o conteúdo da string global
                   por uma fornecida pelo usuário*/
{
    printf("Digite um novo nome: ");
    scanf("%s", &name);//Atribuindo à string global um novo valor
}

int main()
{
    int code = 123;/*Criando uma variável local no escopo main que armazena
                     um código que pode ser visualizado e alterado somente
                    dentro desse escopo*/
    printf("A variável local(code) vale: %d\nEla existe somente no escopo main.\n\n", code);
    printf("O nome da variável global é: %s\n", name);
    changeName();//Acionando a função que muda o valor da string global
    printf("O novo nome da variável global é: %s\n", name);

    return 0;
}
