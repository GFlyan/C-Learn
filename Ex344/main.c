/*Exercício 344: SYMBOL TABLE - RED-BLACK BST
 *
 * Para evitar o pior caso O(n) de uma BST comum, implementamos
 * a RED-BLACK BST que simula uma 2-3 BST, qual propõe que
 * independente da quantidade de inserções, a árvore sempre
 * estará balanceada, garantindo assim: INSERÇÃO e BUSCA O(logn).
 *
 * Balanceamento Negro: Garante a mesma quantidade de links negros
 * entre todos os links NULLs e a raiz.
 *
 * Uma RBT (Red Black Tree) nunca terá altura maior que 2logn,
 * por mais que uma RBT simule uma 2-3, a altura rubro pode ser no
 * pior dos casos o máximo da altura negra, que equivale a logn,
 * sendo assim a altura máxima não ultrapassa 2logn (lembrando que
 * a altura de uma 2-3 fica entre 0.63logn e logn).
 *
 * BST x 2-3 x RBT
 *
 * BST
 *
 * MÉDIO CASO: 1.39logn
 * PIOR CASO: n
 *
 * 2 - 3
 *
 * MÉDIO CASO: 0.63logn
 * PIOR CASO: logn
 *
 * RBT
 *
 * MÉDIO CASO: 2logn
 * PIOR CASO: logn
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Key int
#define Data int
#define NULLItem (Item) {-1}
#define RED 0
#define BLACK 1
#define isRed(node) (node->color == RED)
#define key(item) (item.key)
#define less(item1, item2) (item1 < item2)
#define eq(item1, item2) (item1 == item2)

typedef struct {
  Key key;
  Data data;
}Item;//Diz respeito a um item

typedef struct node {
  Item item;
  struct node *leftNode, *rightNode;
  int amount, color;//Novo: cor do nó
}STnode;//Diz respeito a um nó

typedef STnode* link;//Diz respeito a um link

link RBT, NULLNode;//RBT e um nó vázio NULLNode

link NEW(Item newItem, link leftNode, link rightNode, int amount) {
  link newNode = malloc(sizeof(STnode));
  newNode->item = newItem;
  newNode->leftNode = leftNode;
  newNode->rightNode = rightNode;
  newNode->amount = amount;
  newNode->color = RED;//Pinta o novo nó de vermelho
  return newNode;
}//Cria um novo nó

void STinit(){
  NULLNode = RBT = NEW(NULLItem, 0, 0, 0);
  NULLNode->color = BLACK;
  RBT = NULLNode;
}//Inicializa a RBT, STinit - caixa preta

int STcount() {
  return RBT->amount;
}//Quantidade de nós na árvore

link searchItem(Key id, link searchNode) {
  if(searchNode == NULLNode) return NULL;
  if(eq(id, key(searchNode->item)) ) return searchNode;
  if(less(id, key(searchNode->item)) ) return searchItem(id, searchNode->leftNode);
  return searchItem(id, searchNode->rightNode);
}//Mesma operação de uma BST comum

bool STsearch(Key id) {
  return searchItem(id, RBT);
}//STsearch - caixa preta

link rotateLeft(link downNode) {
  link upNode = downNode->rightNode;
  downNode->rightNode = upNode->leftNode;
  upNode->leftNode = downNode;
  upNode->color = downNode->color;
  downNode->color = RED;
  upNode->amount = downNode->amount;
  downNode->amount = 1 + downNode->leftNode->amount + downNode->rightNode->amount;
  return upNode;
}//Rotaciona o nó parametrizado para baixo a esquerda e o nó a direita para cima a direita, formando uma árvore rotacionada para a esquerda

link rotateRight(link downNode) {
  link upNode = downNode->leftNode;
  downNode->leftNode = upNode->rightNode;
  upNode->rightNode = downNode;
  upNode->color = downNode->color;
  downNode->color = RED;
  upNode->amount = downNode->amount;
  downNode->amount = 1 + downNode->rightNode->amount;
  return upNode;
}//Rotaciona o nó parametrizado para baixo a direita e o nó a esquerda para cima a direita, formando uma árvore rotacionada para a direita

link flipColors(link flipNode) {
  flipNode->color = RED;
  flipNode->leftNode->color = BLACK;
  flipNode->rightNode->color = BLACK;
  return flipNode;
}//Muda a cor do nó parametrizado para vermelho e seus dois nós filhos antes vermelhos, para petro, balanceando a árvore, diz respeito a correção do nó triplo temporário

link insertItem(Item newItem, link insertNode) {
  if(insertNode == NULLNode) return insertNode = NEW(newItem, NULLNode, NULLNode, 1);
  if(less(key(newItem), key(insertNode->item)) ) insertNode->leftNode = insertItem(newItem, insertNode->leftNode);
  else insertNode->rightNode = insertItem(newItem, insertNode->rightNode);

  if(isRed(insertNode->rightNode) && !isRed(insertNode->leftNode)) insertNode = rotateLeft(insertNode);
  if(isRed(insertNode->leftNode) && isRed(insertNode->leftNode->leftNode)) insertNode = rotateRight(insertNode);
  if(isRed(insertNode->leftNode) && isRed(insertNode->rightNode)) insertNode = flipColors(insertNode);

  insertNode->amount = 1 + insertNode->leftNode->amount;
  return insertNode;
}//Insere um novo nó, obedecendo as configurações de uma RBT

void STinsert(Item newItem) {
  RBT = insertItem(newItem, RBT);
}//STinsert - caixa preta

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

int main(){
    int option;
    STinit();
    do {
        printf("---------------------------------------------\n");
        printf("1 - INSERIR\n2 - PROCURAR\n3 - MOSTRAR\n0 - SAIR\n");
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
                if (!STcount()) printSTempty();
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
            case 3:
                if(!STcount()) printSTempty();
                else {
                    printf("---------------------------------------------\n[");
                    printST(RBT);
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
