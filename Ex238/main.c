#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercicio 238: Fila funcional

FIFO - First In First Out - primeiro elemento a ser adicionado é o primeiro a ser removido
*/

int generateInteger()
/*
Criando uma função que gera um número inteiro
aleatório e retorna esse número.
*/
{
    srand(time(NULL));//Definindo o tempo como semente da função rand.
    int value = rand();//Gerando um número aleatório e atribuindo ele à uma variável.
    return value;//Retornando o número aleatório gerado.
}

typedef struct node
/*
Criando uma estrutura que diz respeito
à um nó, que contém um valor e o endereço
de memória para o próximo nó do mesmo tipo.
*/
{
    int value;//Campo que diz respeito ao valor do nó.
    struct node *nextNode;//Campo que diz respeito ao endereço de memória do próximo nó.
}Node;

void insertNode(Node **line)
/*
Procedimento que insere um novo nó
no final da fila.

Caso a fila esteja vazia o novo nó
será o primeiro nó e será inserido
no início da fila.

Recebe como parâmetro o endereço do
início da fila, que tem como conteúdo
(*), o endereço de memória do primeiro
nó.
*/
{
    Node *newNode=malloc(sizeof(Node));//Alocando memória para o novo nó.
    if(newNode)//Caso a alocação de memória tenha dado certo.
    {
        newNode->value = generateInteger();//Atribuindo um valor ao campo do nó que diz respeito ao valor.
        newNode->nextNode = NULL;/*Atribuindo vazio para o campo próximo nó
                                   do novo nó, pois este novo nó é o último
                                   nó da fila, e após ele não tem nenhum
                                   outro nó.*/
        if(*line)//Caso tenha nós na fila.
        {

            Node *aux = *line;//Criando um ponteiro que recebe o endereço do primeiro nó.
            while(aux->nextNode)//Percorrendo a fila até chegar no último nó.
                aux = aux->nextNode;//Ponteiro auxiliar recebe cada nó subsquente até chegar no último nó.
            aux->nextNode = newNode;//Atribuindo ao campo próximo nó do último nó o novo nó.
        }
        else//Caso a fila esteja vazia.
            *line = newNode;//Atribuindo ao início da fila o primeiro nó.
    }
}

Node* removeNode(Node **line)
/*
Função que remove o primeiro nó da fila.

Retorna um endereço de memória que diz
respeito ao nó removido.

Caso não haja nós na fila, a função retorna
vazio.
*/
{
    if(*line)//Caso haja nós na fila à serem removidos.
    {
        Node *removed = *line;/*Criando um ponteiro que recebe o endereço de memória
                                do primeiro nó, que será o nó à ser removido.*/
        *line = removed->nextNode;/*Atribuindo ao início da fila um novo endereço de memória
                                    que diz respeito ao campo próximo nó do nó a ser removido.*/
        return removed;//Retornando o endereço de memória do nó a ser removido.
    }
    return NULL;//Retorna vazio casa a fila esteja vazia.
}

void printLine(Node *line)
/*
Procedimento que mostra o campo
valor de cada nó da fila.

Recebe como parâmetro o endereço do
primeiro nó.

É um procedimento recursivo.
*/
{
    if(line)//Caso haja endereço de memória válido com conteúdo a ser mostrado.
    {
        printf("%d\n", line->value);
        printLine(line->nextNode);//Chamada recursiva do procedimento para os próximos nós.
    }
}

int main()
{
    Node *line = NULL;//Criando um ponteiro do tipo nó que diz respeito a fila.
    Node *removed = NULL;//Criando um ponteiro do tipo nó que diz respeito ao nó da fila.
    int userValue;//Criando uma variavel que diz respeito à um valor informado pelo usuário.
    do//Fazer enquando o valor informado pelo usuário for diferente de 0.
    {
        printf("---------------------------\n");
        printf("0 - Sair\n1 - Adicionar\n2 - Remover\n3 - Impirmir\n");
        printf("---------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &userValue);//Usuário informa um valor.
        switch(userValue)//Realizar conforme informado pelo usuário.
        {
            case 1:
                insertNode(&line);//Inserindo um novo nó na fila.
                printf("---------------------------\n");
                printf("Elemento adicionado.\n");
                printf("---------------------------\n");
                break;
            case 2:
                if(line)//Caso tenha elementos na fila.
                {
                    removed = removeNode(&line);//Removendo o primeiro nó da fila.
                    printf("---------------------------\n");
                    printf("Elemento removido.\n");
                    printf("---------------------------\n");
                }
                else//Caso a fila esteja vazia.
                {
                    printf("---------------------------\n");
                    printf("Fila vazia.\n");
                    printf("---------------------------\n");

                }
                break;
            case 3:
                if(line)//Caso tenha elementos na fila.
                {
                    printf("---------------------------\n");
                    printLine(line);//Acionando o procedimento que mostra todos os elementos da fila.
                    printf("---------------------------\n");
                }
                else//Caso não tenha elementos na fila.
                {
                    printf("---------------------------\n");
                    printf("Fila vazia.\n");
                    printf("---------------------------\n");
                }
                break;
            default: //Caso o valor informado pelo usuário não seja válido ou deseje sair da fila.
                if(userValue != 0)//Caso o valor informado não seja válido.
                {
                    printf("---------------------------\n");
                    printf("Opção inválida.\n");
                    printf("---------------------------\n");
                }
                else//Caso o usuário deseje sair da fila.
                {
                    printf("---------------------------\n");
                    printf("Fila finalizada.\n");
                    printf("---------------------------\n");
                }
                break;
        }

    }
    while(userValue!=0);//Ponto de parada da fila
    return 0;
}
