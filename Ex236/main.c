#include <stdio.h>
#include <stdlib.h>

/*
Exercício 236: Inserção na fila

FIFO - First In First Out
*/

typedef struct node
/*
Criando uma estrtura que diz respeito à um nó que
possui campos que diz respeito ao valor contido nesse
nó e o endereço de memória do próximo nó
*/
{
    int value;//Valor atribuído ao nó
    struct node *nextNode;//Próximo nó
}Node;

void inserir(Node **insere, int value);
/*

Recebe como parâmetro um ponteiro pra ponteiro
pois será alterado o primeiro conteúdo apontado
que se trata da referência do endereço de memória
dos campos da struct nó, e não dos campos em específico.

Não pode ser uma função que retorna um nó
pois não se tem um nó fixo de entrada e saída
de nós.

O campo referente ao próximo nó
do ultimo nó, que seria o novo nó
inserido recebe NULL.

O campo referente ao próximo nó
do nó anterior ao nó inserido
recebe o endereço do novo nó.
*/
{
    Node *newNode = malloc(sizeof(Node));//Alocando memória para o novo nó


    if(newNode)
    {
        newNode->value = NULL;
        newNode->nextNode=NULL;/*Recebe null pois se trata do último elemento,
                                sendo que o próximo nó não existe na fila*/

        if(*insere==NULL)
        //É realizado somente para o primeiro nó

            *insere = newNode;

        else
        {
            Node *aux;//Ponteiro auxiliar que percorre os nós da fila

            aux = *insere;//Ponteiro auxiliar recebe o endereço de memória do primeiro nó da fila

            while(aux->nextNode != NULL)/*Indo até o último nó da fila

                                          Condição de parada é:

                                          Quando o proximo nó for NULL.

                                          Significando que chegou no último nó*/

                aux = aux->nextNode;/*Atribuindo cada nó da fila pro ponteiro
                                      auxiliar chegar no último nó*/

            aux->nextNode = newNode;//Insere no último nó da fila o novo nó como próximo nó
        }
    }
    else
        printf("Alocação de memória para o nó falhou.");

}

int main()
{
    int *insere = NULL;

    printf("Hello world!\n");
    return 0;
}
