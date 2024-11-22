#include <stdio.h>
#include <stdlib.h>

/*
Exercício 237: Removendo na fila

FIFO - First In First Out
*/

typedef struct node
{
    int value;
    struct node *nextNode;
}Node;

Node* removeNode(Node **line)
/*
Remoção é feita no inicio da fila.

Recebe como parâmetro o endereço que
contém o endereço do primeiro nó.
*/
{


    if(*line)//Caso haja elementos na fila
    {
        Node *removed = *line;//Recebe o endereço de memória do nó a ser removido, no caso o primeiro
        *line = removed->nextNode;
        /*
        Se houver somente 1 único nó recebe NULL

        Se houver mais de 1 nó, o início da fila
        recebe o endereço do próximo nó
        */
        return removed;
    }
    return NULL;
}

int main()
{
    Node *node = malloc(sizeof(Node));//Alocando memória para um novo nó
    node->value = 10;//Atribuindo um valor para esse nó
    node->nextNode = NULL;//Atribuindo um endereço de memória vazia para o próximo nó pois ele não existe
    Node *line = node;//Inserindo o nó na fila
    Node *removed;//Criando um ponteiro que vai receber o endereço de memória do nó removido
    removed = removeNode(&line);//Removendo o primeiro elemento da fila
    printf("O nó que foi removido tinha o valor: %d\n", removed->value);
    if(line)//Se houver elementos na fila
        printf("Há nós na fila.\n");
    else//Se a fila estiver vazia
        printf("Não há nós na fila.\n");
    return 0;
}
