#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxItens 1000000
#define Key int
#define Data int
#define key(item) item.key
#define eq(valorA, valorB) (itemA == itemB)
#define NULLItem (Item) {-1}

/*Exercício 341: SYMBOL TABLE - ARRAY (acesso direto ao indice)

Diferentemente da ST implementada com array onde a inserção é feita
no final, neste modelo a inserção é feita no indíce = ID.

Vantagens:

    STsearch se torna constante
    STremove se torna constante

Desvantagens:

    STinit tem custo O(maxItens), sendo que O(maxItens) >= O(n)

    Não admite elementos repetidos.

    Inserção admite apenas ID's menores que o tamanho limitante do vetor

    ID < maxItens
*/

typedef struct {
    Key key; //ID do item
    Data data; //Valores associados ao item
}Item;

Item *STarray; //ST global
int amountItens; //Diz respeito a quantidade de elementos na ST


void STinit() {
    STarray = malloc(sizeof(Item)*maxItens);
    for(int i = 0 ; i < maxItens; i++) STarray[i] = NULLItem; //Atribui itens vazios a todas as posições da ST "limpeza"
    amountItens = 0;
} //Inicia a ST -> Custo O(maxItens), devido a "limpeza"

bool STempty() {
    return !amountItens;
} //Retorna se existem itens na ST

int STcount() {
    return amountItens;
} //Retorna quantos itens existem na ST

void STinsert(Item item) {
    if(key(STarray[key(item)]) != key(NULLItem)) return;
    STarray[key(item)] = item; //Insere um item em uma posição igual ao seu ID
    amountItens++;
} //Insere itens na ST

bool STsearch(Key searchID) {
    return key(STarray[searchID]) == searchID; //Verifica se existe um item na posição do ID informado
} //Procura um ID na ST e retorna se o ID foi encontrado ou não

bool STremove(Key removeID) {
    if(!STsearch(removeID)) return false; //Caso não exista um ID na ST
    STarray[removeID] = NULLItem; //Atribui um item vazio a ST na posição do ID caso o mesmo exista na ST
    amountItens--;
    return true;
} //Remove um ID na ST e retorna se o ID foi removido ou não

Item insertItem() {
    Item newItem;
    printf("------------------------------------------\n");
    printf("INSIRA O ID: ");
    scanf("%d", &newItem.key);
    printf("------------------------------------------\n");
    newItem.data = 0;
    return newItem;
} //Cria um novo item de acordo com as especificações do usuário e retorna

void printSTempty() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("------------------------------------------\n");
} //Mensagem de ST vazia

void printSTfull() {
    printf("------------------------------------------\n");
    printf("SYMBOL TABLE CHEIA\n");
    printf("------------------------------------------\n");
} //Mensagem de ST cheia

void printST() {
    printf("[");
    for(int pos = 0; pos < maxItens; pos++) if (key(STarray[pos]) != key(NULLItem)) printf(" %d ", key(STarray[pos]));
    printf("]\n");
} //Mostra todos os IDs dos itens da ST, exceto os IDs referentes ao NULLItem

int main()
{
    STinit();
    int option;
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR\n2 - PROCURAR\n3 - REMOVER\n4 - MOSTRAR\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                if(amountItens < maxItens) {
                    STinsert(insertItem());
                    printf("------------------------------------------\n");
                    printf("ID INSERIDO\n");
                    printf("------------------------------------------\n");
                } else printSTfull();
                break;
            case 2:
                if(!STempty()) {
                    int searchID;
                    printf("------------------------------------------\n");
                    printf("INFORME O ID A SER PROCURADO: ");
                    scanf("%d", &searchID);
                    printf("------------------------------------------\n");
                    printf(STsearch(searchID) ? "ID FOI ENCONTRADO\n" : "ID NÃO FOI ECONTRADO\n");
                } else printSTempty();
                break;
            case 3:
                if(!STempty()) {
                    int removeID;
                    printf("------------------------------------------\n");
                    printf("INFORME O ID A SER REMOVIDO: ");
                    scanf("%d", &removeID);
                    printf("------------------------------------------\n");
                    printf(STremove(removeID) ? "ID FOI REMOVIDO\n" : "ID NÃO FOI ENCONTRADO\n");
                } else printSTempty();
                break;
            case 4:
              if(!STempty()) {printST();} else printSTempty();
              break;
            default:
                printf("------------------------------------------\n");
                printf(option ? "OPÇÃO INVALIDA\n" : "PROGRAMA FINALIZADO\n");
                printf("------------------------------------------\n");
                break;
        }
    } while(option);
    return 0;
}
