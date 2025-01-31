#include <stdio.h>
#include <stdlib.h>

//Exercício 277: Árvore Binária de Busca de Pessoas

typedef struct person{
    char name[100];
    int cpf;
}Person;

typedef struct binaryTreeNode{
    Person person;
    struct binaryTreeNode *left, *right;
}BinaryTreeNode;

Person insertPerson() {
    Person person;
    printf("Informe o nome: ");
    scanf("%s", &person.name);
    gets();
    printf("Informe o CPF: ");
    scanf("%d", &person.cpf);
    return person;
}

BinaryTreeNode* insertBT(BinaryTreeNode *bT, Person person) {
    if(!bT) {
        bT = malloc(sizeof(BinaryTreeNode));
        bT->person = person;
        bT->left = NULL;
        bT->right = NULL;
        printf("------------------------------------------\n");
        printf("%s FOI INSERIDO\n", person.name);
        printf("------------------------------------------\n");
        return bT;
    }
    else {
        if(person.cpf < bT->person.cpf) bT->left = insertBT(bT->left, person);
        else bT->right = insertBT(bT->right, person);
        return bT;
    }
}

BinaryTreeNode* removeBT(BinaryTreeNode *bT, Person person) {
    printf("%p\n", bT);
    printf("%s %d\n", bT->person.name, bT->person.cpf);
    printf("%s %d\n", person.name, person.cpf);
    (person.name == bT->person.name) ? printf("É IGUAL\n") : printf("Ñ É IGUAL\n");
    if(!bT) {
        printf("------------------------------------------\n");
        printf("%s NÃO EXISTE\n", person.name);
        printf("------------------------------------------\n");
        return NULL;
    }
    else if(bT->person.name == person.name && bT->person.cpf == person.cpf) {
        printf("SÓ SLVINHO\n");
        if(!(bT->left && bT->right)) {
            free(bT);
            printf("------------------------------------------\n");
            printf("%s FOI REMOVIDO\n", person.name);
            printf("------------------------------------------\n");
            return NULL;
        } else {
            if(bT->left && bT->right) {
                BinaryTreeNode **aux = &(bT->right), *node;
                while((*aux)->left)
                    aux = &((*aux)->left);
                node = *aux;
                if((*aux)->right) *aux = (*aux)->right;
                else *aux = NULL;
                node->left = bT->left;
                node->right = bT->right;
                free(bT);
                printf("------------------------------------------\n");
                printf("%s FOI REMOVIDO\n", person.name);
                printf("------------------------------------------\n");
                return node;
            } else {
                BinaryTreeNode *aux;
                if(bT->left) aux = bT->left;
                else aux = bT->right;
                free(bT);
                printf("------------------------------------------\n");
                printf("%s FOI REMOVIDO\n", person.name);
                printf("------------------------------------------\n");
                return aux;
            }
        }
    } else {
        printf("MERDA\n");
        if(person.cpf < bT->person.cpf) bT->left = removeBT(bT->left, person);
        else bT->right = removeBT(bT->right, person);
        return bT;
    }
}

void printBT(BinaryTreeNode *bT) {
    if(!bT) return;
    printBT(bT->left);
    printf("%s %d\n", bT->person.name, bT->person.cpf);
    printBT(bT->right);
}

int amountInBT(BinaryTreeNode *bT) {
    int amount = 0;
    if(!bT) return amount;
    else {
        if(bT->left) amount += amountInBT(bT->left);
        else return amount += amountInBT(bT->right);
        return ++amount;
    }
}

BinaryTreeNode* searchInBT(BinaryTreeNode *bT, Person person) {
    if(!bT) return NULL;
    else if(bT->person.cpf == person.cpf && bT->person.name == person.name) return bT;
    else {
        if(person.cpf < bT->person.cpf) return searchInBT(bT->left, person);
        else return searchInBT(bT->right, person);
    }
}

int main()
{
    BinaryTreeNode *bT = NULL;
    Person person;
    int option;
    do {
        printf("------------------------------------------\n");
        printf("1 - INSERIR PESSOA\n2 - REMOVER PESSOA\n3 - MOSTRAR PESSOAS\n4 - QUANTIDADE DE PESSOAS\n5 - PROCURAR PESSOA\n0 - SAIR\n");
        printf("------------------------------------------\n");
        printf("INSIRA: ");
        scanf("%d", &option);
        printf("------------------------------------------\n");
        switch(option) {
            case 1:
                person = insertPerson();
                bT = insertBT(bT, person);
                break;
            case 2:
                if(bT) {
                    printf("------------------------------------------\n");
                    person = insertPerson();
                    bT = removeBT(bT, person);
                    printf("------------------------------------------\n");
                } else {
                    printf("------------------------------------------\n");
                    printf("ÁRVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            case 3:
                if(bT) {
                    printf("------------------------------------------\n");
                    printBT(bT);
                    printf("------------------------------------------\n");
                } else {
                    printf("------------------------------------------\n");
                    printf("ÁRVORE VAZIA\n");
                    printf("------------------------------------------\n");
                }
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }

    } while(option);
    return 0;
}
