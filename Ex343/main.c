#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Key int
#define Data int
#define key(item) item.key
#define less(firstValue, secondValue) (firstValue < secondValue)
#define eq(valueA, valueB) (valueA == valueB)
#define NULLItem (Item) {-1}
#define isNULLNode(node) (node == NULLNode)

/*Exercício 343: SYMBOL TABLE - BINARY SEARCH TREE

Para evitar os problemas de custo dos outros
modelos de ST como:

    - ARRAY INSERÇÃO NO FINAL: Busca O(n), remoção O(n)
    - ARRAY DE ACESSO DIRETO:  Muita alocação de memória e limitação de inserção de acordo com o tamanho máximo defino para o vetor
    - LINKED LIST: Busca O(n), inserção O(n), remoção O(n)

implementamos a ST com BST.

Vantagem no caso médio:

    inserção, remoção e busca -> O(logn)

Desvantagem:

    Desbalanceamento da árvore pode causar custos O(n), pois pode acabar virando uma lista encadeada.
*/

typedef struct { //Estrutura que diz respeito a um item
    Key key;
    Data data;
}Item;

typedef struct node { //Estrutura que diz respeito aos nós de uma árvore binária
    Item item;
    struct node *leftNode, *rightNode;
    int amount;
}STnode;

typedef STnode *link;//Definição de um link do tipo ponteiro para um nó de árvore binária

link BST, NULLNode; //Nó referente a uma ABB e um nó vazio NULLNode

link NEW(Item newItem, link leftNode, link rightNode, int amount) {
  link newNode = malloc(sizeof(STnode));
  newNode->item = newItem;
  newNode->leftNode = leftNode;
  newNode->rightNode = rightNode;
  newNode->amount = amount;
  return newNode;
}//Cria e retorna um novo nó com as informações parametrizadas

void STinit(){
  NULLNode = NEW(NULLItem, 0, 0, 0);
  BST = NULLNode;
}//Inicializa a BST,  STinit - caixa preta

int STcount() {
  return BST->amount;
}//Retorna quantidade de nós existentes na BST

link insertItem(Item newItem, link insertNode) {
    if(insertNode == NULLNode) return insertNode = NEW(newItem, NULLNode, NULLNode, 1);
    if (less(key(newItem), key(insertNode->item))) insertNode->leftNode = insertItem(newItem, insertNode->leftNode);
    else insertNode->rightNode = insertItem(newItem, insertNode->rightNode);
    insertNode->amount = 1 + insertNode->leftNode->amount + insertNode->rightNode->amount;
    return insertNode;
}//Função que insere um novo item na árvore binária

void STinsert(Item newItem){
    BST = insertItem(newItem, BST);
}//STinsert - caixa preta

link removeItem(Key id, link removeNode) {
    if(removeNode == NULLNode) {
        printf("ITEM NÃO ENCONTRADO\n");
        return NULLNode;
    }
    if(eq(id, key(removeNode->item))) { //Caso o ID seja encontrado
        if(isNULLNode(removeNode->leftNode) && isNULLNode(removeNode->rightNode)) removeNode = NULLNode; //Caso o nó que contém o ID não tenha filhos
        else if(removeNode->leftNode && removeNode->rightNode) { //Caso o nó que contém o ID tenha dois filhos
            STnode **aux = &removeNode->rightNode;
            while((*aux)->leftNode) aux = &(*aux)->leftNode;
            (*aux)->leftNode = removeNode->leftNode;
            if(!eq(removeNode->rightNode, *aux)) {
              link temp = *aux;
              *aux = (*aux)->rightNode;
              temp->rightNode = removeNode->rightNode;
              free(removeNode);
              removeNode = temp;
            } else removeNode = *aux;
        }
        else { //Caso o nó que contém o ID tenha apenas um único filho
            if(!isNULLNode(removeNode->leftNode) && isNULLNode(removeNode->rightNode)) //Caso o único nó filho existente seja o nó a esquerda
                removeNode = removeNode->leftNode;
            else //Caso o único nó filho existente seja o nó a direita
                removeNode = removeNode->rightNode;
        }
        printf("ITEM REMOVIDO\n");
    }
    else if(less(id, key(removeNode->item))) removeNode->leftNode = removeItem(id, removeNode->leftNode);
    else removeNode->rightNode = removeItem(id, removeNode->rightNode);
    removeNode->amount = 1 + removeNode->leftNode->amount + removeNode->rightNode->amount;
    return removeNode;
}//Função que remove um item da árvore binária

void STremove(Key id) {
     BST = removeItem(id, BST);
}//STremove - caixa preta

link searchItem(Key id, link searchNode) {
    if (searchNode == NULLNode) return NULLNode;
    if (eq(id, key(searchNode->item))) return searchNode;
    if (less(id, key(searchNode->item))) return searchItem(id, searchNode->leftNode);
    return searchItem(id, searchNode->rightNode);
}

bool STsearch(Key id) {
    return searchItem(id, BST) != NULLNode ? true : false;
}

Item createItem() {
    Item newItem;
    printf("---------------------------------------------\n");
    printf("INFORME O ID:");
    scanf("%d", &newItem.key);
    printf("---------------------------------------------\n");
    newItem.data = 0;
    return newItem;
}//Função que cria e retorna um item a partir de informações fornecidas pelo usuário

void printSTempty() {
    printf("---------------------------------------------\n");
    printf("SYMBOL TABLE VAZIA\n");
    printf("---------------------------------------------\n");
}//Mensagem ST vazia

void printST(link printNode) {
    if(printNode == NULLNode) return;
    printST(printNode->leftNode);
    printf(" %d ", key(printNode->item));
    printST(printNode->rightNode);
}//Procedimento que percorre em ordem a árvore e mostra todas as chaves dos itens existentes nela

int main()
{
    int option;
    STinit();
    do {
        printf("---------------------------------------------\n");
        printf("1 - INSERIR\n2 - REMOVER\n3 - PROCURAR\n4 - MOSTRAR\n0 - SAIR\n");
        printf("---------------------------------------------\n");
        printf("INSERIR:");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("---------------------------------------------\n");
                STinsert(createItem());
                printf("ITEM INSERIDO\n");
                printf("---------------------------------------------\n");
                break;
            case 2:
                if(!BST->amount) printSTempty();
                else {
                    Key removeID;
                    printf("---------------------------------------------\n");
                    printf("INSIRA O ID A SER REMOVIDO:");
                    scanf("%d", &removeID);
                    printf("---------------------------------------------\n");
                    STremove(removeID);
                    printf("---------------------------------------------\n");

                }
                break;
            case 3:
                if (!BST->amount) printSTempty();
                else {
                    Key searchID;
                    printf("---------------------------------------------\n");
                    printf("INSIRA O ID A SER PROCURADO:");
                    scanf("%d", &searchID);
                    printf("---------------------------------------------\n");
                    printf(STsearch(searchID) ? "ITEM ENCONTRADO\n" : "ITEM NÃO ENCONTRADO\n");
                    printf("---------------------------------------------\n");
                }
                break;
            case 4:
                if(!BST->amount) printSTempty();
                else {
                    printf("---------------------------------------------\n[");
                    printST(BST);
                    printf("]\n---------------------------------------------\n");
                }
                break;
            default:
                printf("---------------------------------------------\n");
                printf(option ? "OPCAO INVALIDA\n" : "PROGRAMA FINALIZADO\n");
                printf("---------------------------------------------\n");
                break;
        }
    } while(option);
    return 0;
}
