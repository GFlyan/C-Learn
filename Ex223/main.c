#include <stdio.h>
#include <stdlib.h>

/*
Exercício 223: Pilhas

->As estruturas de dados dinâmicas funcionam de forma diferente das estruturas de dados
estáticas (arrays), onde o tamanho das E.E. serão sempre constantes, uma E.D. pode
variar seu tamanho, sendo que cada tipo de E.D. possui uma finalidade diferente.

->As E.D. não estão organizadas de forma sequênciais na memória, portanto
para serem correlacionadas são atribuídos nós referentes a cada elemento,
onde um nó faz referência a outro nó de memória

Algumas estruturas de dados dinâmicas:

-Pilhas

Representa um empilhamento de dados

Toda operação é feita no topo da pilha, ou seja toda inserção/remoção é feita no topo.

Push -> insere/empilha
Pop -> remove/desempilha

LIFO - Last In First Out - Último a entrar é o primeiro a sair

Sobre o topo:

Ponteiro apontando para o topo da pilha
No inicio quando a pilha está vazia o valor do ponteiro é null

Estrutura de um nó:

typedef struct no{
    tipo valor;
    struct no *ponteiro;
}No;


*/

typedef struct no{//A nomeação da struct precisa ocorrer no inicio para que seja criado um nó do mesmo tipo dentro da struct
 int value;//Valor inteiro qualquer
 struct no *proximo;//Ponteiro do tipo No que aponta para o próximo nó
}No;//Renomeando a struct para No

int main()
{
    return 0;
}
