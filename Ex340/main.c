#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxItens 1000000
#define Key int
#define Data int
#define key(item) (item.key)
#define less(keyA, keyB) (keyA < keyB)
#define eq(keyA, keyB) (keyA == keyB)

/*Exercício 340: SYMBOL TABLE - ARRAY (inserção no final)

Uma SYMBOL TABLE é uma estrutura de dados que armazena conteúdos
que chamamos de itens onde cada item possui um identificador (chave
- key) e valores associados (dados -data).

Vantagens:

    Maioria das operações são de custo O(1):

        STinit
        STempty
        STcount
        STinsert (inserção realizada na última posição livre do array)

    Dispõe de uma função de ordenação de arrays de custo O(nlogn):

        STsort (baseada em Quick Sort ou Merge Sort)

    Admite elementos repetidos.

Desvantagens:

    Operação mais importante que seria a operação de busca
    possui custo O(n):

        STsearch
        STremove (utiliza STsearch)

*/

typedef struct
/*Estrutura que representa um item.

Possui dois campos:

Key key: Identificador do item.
Data data: Valores associados ao item.*/
{
    Key key; //Identificador do item
    Data data; //Valores associados ao item
}Item;

static Item *STarray; //SYMBOL TABLE estática
static int amountItens; /*Diz respeito a quantidade de itens que existem na SYMBOL TABLE
                        (lastPosition) ultimaPosicao = amountItens-1*/

void STinit()
/*Procedimento que inicia uma SYMBOL TABLE.

Custo O(1)*/
{
    STarray = malloc(sizeof(Item)*maxItens); //Aloca memória pra SYMBOL TABLE
    amountItens = 0; //Associa um valor a quantidade de itens na SYMBOL TABLE
}

bool STempty()
/*Função que retorna se a SYMBOL TABLE está vazia.

Custo O(1)*/
{
    return !(amountItens);
}

int STcount()
/*Função que retorna a quantidade de itens na SYMBOL TABLE.

Custo O(1)*/
{
    return amountItens;
}

void STinsert(Item newItem)
/*Procedimento que insere um item em uma SYMBOL TABLE.

Custo O(1)*/
{
    STarray[amountItens++] = newItem; /*Adiciona um item a SYMBOL TABLE e aumenta a variável
                                      referente a quantidade de itens que existem na mesma.*/

}

Item *STsearch(Key searchID)
/*Função que procura se um item com dado ID existe na
SYMBOL TABLE.

Armazena o endereço da primeira incidencia do elemento.

Recebe como parâmetro o ID a ser procurado.

Retorna o endereço de memória do ID na SYMBOL TABLE
caso seja encontrado ou retorna NULL caso não seja encontrado.*/
{
    Item *positionAddress = NULL; /*Criando um endereço de memória que armazenará o endereço de
                                  memória de incidência do ID procurado*/
    for(int i = 0 ; i < amountItens ; i++) {
        if(eq(searchID, key(STarray[i]))) return positionAddress = STarray+(i*sizeof(Item));
        //Caso o ID procurado seja encontrado é retornado o endereço de memória que contém o ID
    }
    return positionAddress; //Caso o ID procurado não seja encontrado é retornado NULL
}

bool STremove(Key removeID)
/*Procedimento que remove um item com o ID fornecido.

Recebe como parâmetro o ID do item a ser removido da SYMBOL TABLE.*/
{
    Item *address = STsearch(removeID); //Armazena o endereço referente ao item que contém o ID
    if(address) {
        int position = (address-STarray)/sizeof(Item); //Armazena o indice do ID no array
        STarray[position] = STarray[--amountItens]; //Swap do último item do array com o item a ser removido
        return true;
    }
    return false;
}

Item insertItem(){
    Item newItem;
    printf("------------------------------------------\n");
    printf("INSIRA O ID: ");
    scanf("%d", &newItem.key);
    printf("------------------------------------------\n");
    newItem.data = NULL;
    return newItem;
}

int partition(Item *arrayST, int leftPosition, int rightPosition) {
    Key pivot = (key(arrayST[leftPosition])+key(arrayST[(leftPosition+rightPosition)/2])+key(arrayST[rightPosition]))/3;
    while(rightPosition > leftPosition) {
        while(key(arrayST[leftPosition]) <= pivot && rightPosition > leftPosition) leftPosition++;
        while(key(arrayST[rightPosition]) > pivot && rightPosition > leftPosition) rightPosition--;
        if(leftPosition <= rightPosition) {
            Item aux = arrayST[leftPosition];
            arrayST[leftPosition] = arrayST[rightPosition];
            arrayST[rightPosition] = aux;
            leftPosition++;
            rightPosition--;
        }
    }
    return rightPosition;
} //Partition da STsort

void STsort(Item *arrayST, int firstPosition, int lastPosition) {
    if(firstPosition >= lastPosition) return;
    int mid = partition(arrayST, firstPosition, lastPosition);
    STsort(arrayST, firstPosition, mid-1);
    STsort(arrayST, mid, lastPosition);
} //Organiza a SYMBOL TABLE

void printSTempty() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("------------------------------------------\n");
}

void printSTfull() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE CHEIA\n");
    printf("------------------------------------------\n");
}

void printST() {
    printf("------------------------------------------\n");
    for(int i = 0 ; i < amountItens ; i++) {
        if(i == 0) printf("[ ");
        printf(" %d ", key(STarray[i]));
        if(i == amountItens-1) printf("]\n");
    }
    printf("------------------------------------------\n");
}

int main()
{
    STinit();
    int option;
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - PROCURAR\n3 - REMOVER\n4 - MOSTRAR\n5 - ORDENAR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                if(amountItens < maxItens) {
                    STinsert(insertItem());
                    printf("------------------------------------------\n");
                    printf("ITEM INSERIDO\n");
                    printf("------------------------------------------\n");
                } else printSTfull();
                break;
            case 2:
                if(!STempty()) {
                    Key searchID;
                    printf("------------------------------------------\n");
                    printf("INSRIA O ID A SER PROCURADO: ");
                    scanf("%d", &searchID);
                    printf("------------------------------------------\n");
                    Item *verification = STsearch(searchID);
                    printf(verification ? "ID ENCONTRADO\n" : "ID NÃO ENCONTRADO\n");
                } else printSTempty();
                break;
            case 3:
                if(!STempty()) {
                    Key removeID;
                    printf("------------------------------------------\n");
                    printf("INSIRA O ID A SER REMOVIDO: ");
                    scanf("%d", &removeID);
                    printf("------------------------------------------\n");
                    printf( STremove(removeID) ? "ID REMOVIDO\n" : "ID NÃO ENCONTRADO\n");
                } else printSTempty();
                break;
            case 4:
                STempty() ? printSTempty() : printST();
                break;
            case 5:
                if(STempty()) printSTempty();
                else {
                    STsort(STarray, 0, amountItens-1);
                    printf("------------------------------------------\n");
                    printf("SYMBOL TABLE ORDENADA\n");
                    printf("------------------------------------------\n");
                }
                break;
            default:
                printf("------------------------------------------\n");
                printf( option ? "OPCAO INVALIDA\n" : "PROGRAMA FINALIZADO\n");
                printf("------------------------------------------\n");
                break;
        }
    } while(option);
    return 0;
}
