#include <stdio.h>
#include <stdlib.h>

/*
Exercício 170: Memória de uma variável struct

->Quando uma struct contém somente um tipo primitivo em seus campos: byteTipo x totalVariáveis

->Quando uma struct contém mais de um tipo primitivo em seus campos: Σ(byteTipo x totalVariáveisTipo)  + 3

->sizeof() é a função que retorna a quantidade de bytes
*/

typedef struct//Criando uma struct que faz referência aos dados de uma pessoa
{
    char name[100];//Campo que diz respeito ao nome da pessoa -> Ocupa 100 bytes
    int age;//Campo que diz respeito à idade da pessoa -> Ocupa 4 bytes
    float width;//Campo que diz respeito à altura da pessoa -> Ocupa 4 bytes

}Person;


int main()
{
    Person person;//Criando uma variável do tipo Person
    printf("Quantidade de bytes: %d", sizeof(person));
    return 0;
}
