#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 226: Pilha funcional
*/

int insertValue()
/*Criando uma função que gera um valor aleatório e retorna esse valor*/
{
    int value;//Criando uma variável que diz respeito ao valor que será atribuido ao valor de um nó
    srand(time(NULL));//Definindo o tempo como semente da função rand
    value = rand();//Atribuindo um valor aleatório a variável
    return value;//Retornando o valor aleatório gerado
}


typedef struct node
/*Criando uma estrutura que diz respeito à um nó, onde
cada nó possui um valor e o endereço do próximo nó*/
{
    int value;//Valor do nó
    struct node *nextNode;//Endereço do próximo nó

}Node;

//Cria um novo nó

Node* push(Node *top)
/*
Criando uma função que adiciona um novo nó
ao topo da pilha.

Essa função deve ser atribuida à um ponteiro (nó do topo)
qual retorna um novo endereço de memória para o conteúdo
do ponteiro (nó do topo), existindo assim um novo topo

O parâmetro passado para essa função é um ponteiro
cujo conteúdo é um endereço de memória que será
substituído
*/
{
    Node *newNode = malloc(sizeof(Node));//Fornecendo um espaço de memória para o novo nó

    if(newNode)//Caso a alocação de memória para o novo nó tenha dado certo
    {
        newNode->value = insertValue();//Fornecendo um valor aleatório para o novo nó

        newNode->nextNode = top;//Fornecendo um endereço de memória para o campo próximoNó do novoNó

        /*EXEMPLO: Caso a  pilha esteja vazia o valor atribuído ao primeiro nó no campo
        próximoNó será NULL, pois diz respeito ao conteúdo do nó topo da pilha, que se
        trata de um conteúdo de ponteiro, ou seja, um endereço de memória NULL agora quando
        a pilha tiver 1 elementos já inserido e a função push() for acionada para inserir
        o segundo nó, o conteúdo do ponteiro topo não será mais NULL, será o endereço alocado
        do primeiro nó, e assim vai sucessivamente*/

        return newNode;/*Retorna como conteúdo do endereço de memória alocado para o novo nó
                         sendo que este novo endereço de memória contém os campos da struct nó*/
    }
    else//Caso a alocação de memória para o novo nó tenha falhado
        printf("Alocação de memória falhou.\n");

    return NULL;/*Caso a alocação de memória falhe não será possível prosseguir com a inserção
                  de um novo elemento, então será retornado para o conteúdo do ponteiro um
                  endereço de memória NULL*/
}

Node* pop(Node **top)
/*
Criando uma função que remove um elemento
do topo da pilha.


Essa função deve ser atribuida à um ponteiro (nó
removido) que irá receber o endereço de memória
do nó a ser removido (que no momento seria o nó
do topo), onde o endereço de memória do nó do topo
irá receber o endereço de memória do campo próximoNó
do nó a ser removido, fazendo assim com que o novo
topo passe a ser o nó seguinte ao nó a ser removido.

É passado um ponteiro pra ponteiro sendo que o primeiro conteúdo
apontado de um ponteiro pra ponteiro é o espaço que armazena o
endereço de memória (conteúdo) que diz respeito ao endereço dos
campos da struct nó, e não aos campos em específico (este seria
o segundo conteúdo apontado de um ponteiro pra ponteiro);


*/
{
    if(*top != NULL)//Caso o endereço de memória não seja vazio, ou seja caso a pilha não esteja vazia
    {
        Node *removed = *top; /*Fornecendo ao ponteiro (remover) um primeiro conteúdo apontado
                               de um ponteiro para ponteiro, ou seja, um conteúdo de um ponteiro
                               que é um endereço de memória, que se trata do endereço de memória
                               do atual nó do topo que será removido.
                               */

        *top = removed->nextNode;/*Atribuindo ao nó do topo o endereço do proximo nó referente
                                  ao nó que será removido*/

        return removed;//Retornando o endereço do nó removido
    }
    else
        printf("Pilha vazia.\n");
    return NULL;
    /*Caso o endereço de memória seja vazio, não será possível remover nenhum endereço
      de memória, então será retornado para o conteúdo do ponteiro atribuido à função o
      endereço de memória NULL*/
}

int main()
{
    Node *top = NULL;/*Criando um ponteiro struct que diz respeito ao nó
               do topo, por se tratar de uma pilha e atribuindo NULL como
               conteúdo desse ponteiro pois a pilha está vazia*/

    Node *remove;/*Criando um ponteiro struct que diz respeito ao nó
                   que será removido caso ele exista*/

    int userValue;//Criando uma variável que diz respeito à opção escolhida pelo usuário

    do{//Garantindo que o loop vai rodar sem o usuário ter atribuido um valor ainda
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimrir\nInsira: ");
    scanf("%d", &userValue);//Atribuindo um valor escolhido pelo usuário

    switch(userValue)//Realizar baseando-se na opção do usuário
    {
    case 1://Empilhando
        top = push(top);/*Acionando a função push que recebe como parâmetro o endereço
                          atribuido ao ponteiro nó do topo, onde será retornado para o
                          nó do topo um novo nó contendo um novo elemento e o endereço
                          de memória referente ao nó antigo*/
        break;
    case 2://Desempilhando
        removed = pop(&top);/*Acionando a função pop que remove o atual nó topo da pilha
                             fazendo com que endereço de memória do campo próximo nó seja
                             o novo nó topo da pilha, caso não haja nenhum elemento na pilha
                             será retornado um endereço de memória NULL*/
        if(removed != NULL)//Caso a pilha não esteja vazia
        {
            printf("\nO elemento removido foi: %d\n", removed->value);
        }
        else//Caso a pilha esteja vazia
            printf("\nNão há nenhum nó a ser removido.\n");
        break;
    case 3://Imprimindo o valor do topo da pilha
        if(top != NULL)//Caso a pilha não esteja vazia
            printf("\nValor do topo da pilha: %d\n", top->value);
        else//Caso a pilha esteja vazia
            printf("\nNão há nenhum nó a ser informado.\n");
        break;
    default://Opções inválidas ou sair da pilha
        if(userValue!=0)//Caso o valor seja inválido
            printf("\nValor inválido.\n");
        else//Caso o usuário queira finalizar a pilha
            printf("\nPilha finalizada!\n");
        break;
    }

    }
    while(userValue!=0);//Condição de parada do loop

    return 0;
}
