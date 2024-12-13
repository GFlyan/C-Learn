#include <stdio.h>
#include <stdlib.h>

/*Exercício 239: Fila 2ª versão - METADADOS

Fila com metadados faz com que a inserção e remoção
em uma fila seja sempre constante, onde no caso de
uma fila sem metadados seria necessário percorrer a
fila para fazer a inserção no final da fila tendo um
custo linear, em uma fila com metadados possuimos o
endereço do nó final da fila, sendo possível acessá-lo
com custo constante.
*/

typedef struct node//Apelido do nó.
/*Estrura que diz respeito a um nó
contendo um campo referente ao valor
contido nesse nó e um campo referente
ao endereço  de memória do próximo nó.*/
{
    int value;//Campo que diz respeito ao valor contido no nó.
    struct node *nextNode;//Campo que diz respeito ao endereço do próximo nó.
}Node;//Nome da estrutura nó.

typedef struct
/*Estrutura que diz respeito a uma fila
contendo a característica de metadados, onde
ela possui o endereço do primeiro nó, o endereço
do último nó e o tamanho da fila (número de nós existentes).*/
{
    Node *firstNode;//Campo que diz respeito ao primeiro nó da fila.
    Node *lastNode;//Campo que diz respeito ao último nó da fila.
    int sizeLine;//Campo que diz respeito ao tamanho da fila.
}Line;//Nome da estrutura fila.

void insertLine(Line *line)
/*Procedimentoq que diz respeito a inserção
de um nó em uma fila com metadados, onde quando
a fila estiver vazia, os campos de metadados da
fila referenciarão o mesmo nó, e quando houver
um ou mais nós, os metadados referenciarão corretamente
o primeiro e o último nó.

A diferença do estilo de uma fila com metadados para
uma fila clássica é que o custo para inserção
e remoção é constante, diferentemente da fila clássica.*/
{
    Node *newNode = malloc(sizeof(Node));//Criando o novo nó e alocando memória.
    if(newNode)//Caso a alocação de memória seja bem sucedida.
    {
        newNode->value = insertInteger();//Inserindo um valor para o novo nó.
        newNode->nextNode = NULL;//Inserindo NULL como próximo nó do novo nó pois ele será inserido no final da fila.

        if(line->lastNode)//Caso exista nós na fila.
            line->lastNode->nextNode = newNode;//O próximo nó do último nó recebe o novo nó.
        else//Caso a fila esteja vazia.
            line->firstNode = newNode;//O metadado referente ao primeiro nó recebe o novo nó.
        line->lastNode = newNode;//O metadado referente ao último nó recebe o novo nó.
        line->sizeLine++;//Incremento unitário ao metadado referente ao tamanho da fila.
    }
}

void removeLine(Line *line)
/*Procedimento que diz respeito a remoção
em uma fila com metadados.*/
{
    if(line->sizeLine)//Caso exista nós na fila
    {

        Node *removed = line->firstNode;/*Por se tratar de uma fila, a remoção é feita no
                                          início logo o nó auxiliar recebe o primeiro nó que
                                          será o nó a ser removido.*/
        line->firstNode = removed->nextNode;//O novo primeiro passa a ser o próximo nó do nó a ser removido.
        line->sizeLine--;//Decremento unitário ao metadado referente ao tamanho da fila.
        printf("------------------------------------\n");
        printf("REMOVIDO\n");
        printf("------------------------------------\n");
    }
    else//Caso a fila esteja vazia
    {
        printf("------------------------------------\n");
        printf("FILA VAZIA\n");
        printf("------------------------------------\n");
    }
}

int main()
{
    Line *line = malloc(sizeof(Line));//Alocando memória para a criação de uma fila.
    int userValue;//Criando uma variável que irá armazenar um valor informado pelo usuário.

    do
    {
        printf("------------------------------------\n");
        printf("1 - ENFILEIRAR\n2 - DESENFILEIRAR\n3 - MOSTRAR FILA\n4 - TAMANHO DA FILA\n0 - SAIR\n");
        printf("------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userValue);//Armazenando um valor informado pelo usuário.
        switch(userValue)//Executar de acordo com o valor informado pelo usuário.
        {
            case 1:
                insertLine(line);//Insere na fila.
                break;
            case 2:
                removeLine(line);//Remove na fila.
                break;
            case 3:
                if(line->sizeLine)//Caso existam nós na fila.
                {
                    printf("------------------------------------\n");
                    printData(line->firstNode);//Mostra a fila.
                    printf("------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------\n");
                    printf("FILA VAZIA\n");
                    printf("------------------------------------\n");
                }
                break;
            case 4:
                printf("------------------------------------\n");
                printf("TAMANHO DA FILA: %d\n", line->sizeLine);
                printf("------------------------------------\n");
                break;
            default:
                if(userValue!=0)
                {
                    printf("------------------------------------\n");
                    printf("VALOR INVÁLIDO\n");
                    printf("------------------------------------\n");
                }
                else
                {
                    printf("------------------------------------\n");
                    printf("PROGRAMA FINALIZADO\n");
                    printf("------------------------------------\n");
                }
                break;
        }
    } while(userValue!=0);

    return 0;
}

int insertInteger()
/*Procedimento que pede ao usuário um valor e o retorna.*/
{
    int userValue;
    printf("------------------------------------\n");
    printf("INSIRA UM VALOR: ");
    scanf("%d", &userValue);
    printf("------------------------------------\n");
    printf("VALOR INSERIDO\n");
    return userValue;
}

void printData(Node *node)
/*Procedimento que mostra os elementos contidos em um
nó.*/
{
    if(node)
    {
        printf("%d\n", node->value);
        printData(node->nextNode);
    }
}

void sizeLine(Line *line)
/*Procedimento que mostra o metadado referente ao
tamanho de uma fila.*/
{
    printf("%d\n", line->sizeLine);
}
