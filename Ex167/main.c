#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Exercício 167: Typedef struct

->Structs servem para que o programador crie diferentes tipos de dados
de acordo com sua necessidade caso os tipos de dados nativos da linguagem
não sejam capazes de suprir sua necessidade
*/
/*
typedef struct
{

    ...

}nomeStruct;

->Quando uma struct é definida dessa forma ela pode ser utilizada
da seguinte forma:

nomeStruct nomeVariável = valorAtribuido;
*/

/*
struct nomeStruct
{

    ...

};

->Quando a struct é definida dessa forma ela pode posteriormente ser
utilizada da seguinte forma:

struct nomeStruct nomeVariável = valorAtribuido;
*/

//Uma struct pode receber outra struct

typedef struct //Criando uma struct que diz respeito à dados de um determinado alimento
{
    char name[100];//Recebe o nome do alimento
    bool healthy;//Recebe se é um alimento saudável
}Food;

struct Object   //Criando uma struct que refere-se à um objeto do mundo real
{
    char name[100];//Nome do objeto
    bool heavy;//Se o objeto é pesado ou não
};


int main()
{
    Food food;//Criando uma variável do tipo struct Food
    strcpy(food.name, "Uva");//Atribuindo um nome ao campo name da struct Food
    food.healthy = true;//Atribuindo um valor lógico ao campo healthy da struct Food
    printf("Nome da comida: %s\nÉ saudável: %b\n", food.name, food.healthy);

    printf("\n");

    struct Object object;//Criando uma variável do tipo struct Food
    strcpy(object.name, "Bola de Futebol");//Atribuindo um nome ao campo name da struct Object
    object.heavy = false;//Atribuindo um valor lógico ao campo heavy da struct Object
    printf("Nome do objeto: %s\nÉ pesado: %d", object.name, object.heavy);
    return 0;
}
