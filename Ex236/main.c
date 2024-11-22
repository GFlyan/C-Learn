#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 236: Inserção na fila

FIFO - First In First Out
*/

int generateValue()
/*
Função que gera um valor inteiro aleatório e retorna esse valor
*/
{
    sleep(1);//Computador aguarda 1 segundo para atualizar o tempo passado como semente da função rand
    srand(time(NULL));//Passando o tempo como semente da função rand
    int value = rand();//Gerando um valor aleatório com a função rand e armazenando ele
    return value;
}


typedef struct node
/*
Criando uma estrutura que diz respeito à um nó que
possui campos que diz respeito ao valor contido nesse
nó e o endereço de memória do próximo nó
*/
{
    int value;//Valor atribuído ao nó
    struct node *nextNode;//Próximo nó
}Node;

void insertNode(Node **line)
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
        newNode->value = generateValue();//Atribuindo um valor para o novo nó
        newNode->nextNode=NULL;/*Recebe null pois se trata do último elemento,
                                sendo que o próximo nó não existe na fila*/

        if(*line==NULL)
        //É realizado somente para o primeiro nó

            *line = newNode;//Insere o nó do início da fila

        else
        {
            Node *aux;//Ponteiro auxiliar que percorre os nós da fila

            aux = *line;//Ponteiro auxiliar recebe o endereço de memória do primeiro nó da fila

            while(aux->nextNode)/*Indo até o último nó da fila

                                          Condição de parada é:

                                          Quando o proximo nó for NULL.

                                          Significando que chegou no último nó*/

                aux = aux->nextNode;/*Atribuindo cada nó da fila pro ponteiro
                                      auxiliar chegar no último nó*/

            aux->nextNode = newNode;//Insere no último nó da fila o novo nó como próximo nó
        }
    }
    else
        printf("Alocação de memória para o nó falhou.\n");

}

int main()
{
    Node *line = NULL;//Criando uma fila vazia
    insertNode(&line);//Inserindo o primeiro nó da fila
    printf("O primeiro elemento da fila é: %d\n", line->value);
    insertNode(&line);//Inserindo o segundo nó da fila
    Node *secondNode = line->nextNode;//Segundo nó da fila
    printf("O segundo elemento da fila é: %d\n", secondNode->value);
    return 0;
}
