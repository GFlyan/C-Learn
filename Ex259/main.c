#include <stdio.h>
#include <stdlib.h>

/*Exercício 259: Tabela Hash

Uma tabela hash tem a mesma funcionalidade das estruturas de dados
convencionais, armazenar dados, entretanto a principal finalidade
de uma tabela hash é proporcionar uma busca de forma eficiente.

CONCEITOS IMPORTANTES:

CHAVE HASH-> Possui o indentificador a ser tratado pela tabela hash.

FUNCAO HASH/ESPALHAMENTO ->  Critério de organização das chaves na tabela hash,
gera também o índice de acesso de uma chave na tabela.

TABELA HASH -> Array que armazena as chaves dispostas de acorco com o critério
da função hash.

TAMANHO DA TABELA HASH -> Quantidade máxima de elementos na tabela, dada pela
formula 2*quantidadeElementos, aproximando-se do número primo mais próximo.

FATOR DE CARGA -> Definido pela quantidadeElementos/tamanhoTabela, define a
porcentagem de preenchimento da tabela, é um valor entre 0 e 1, sendo que
quanto mais proximo de 0.5, mais eficiente será a tabela.

COLISOES -> Ocorre quando há mais de um resultado apos a aplicacao da funcao hash.

TRATAMENTO DE COLISOES

TABELA HASH COM ARRAY SOMENTE ESTÁTICO -> A chave será guardada na próxima posição vazia
do array.

TABELA HASH COM ARRAY ESTÁTICO E LISTA ENCADEADA -> As posições do array apontam
para as chaves, sendo que cada chave, se houver colisão em dada posição, apontará
para outra chave.

*/

//TABELA HASH SOMENTE COM ARRAY ESTÁTICO

typedef struct {
    int id, value;
} Key;

void insertArrayKey(Key *arrayKey, int sizeArrayKey) {
    for(int i = 0; i < sizeArrayKey; i++) {
        printf("---------------------------------------------------\n");
        printf("INSIRA A %dª CHAVE : ", i+1);
        scanf("%d", &arrayKey[i].id);
        printf("INSIRA O %dº VALOR: ", i+1);
        scanf("%d", &arrayKey[i].value);
        printf("---------------------------------------------------\n");
    }
}

void printKeyArray(Key *arrayKey, int sizeArray) {
    for(int i = 0; i < sizeArray; i++) {
        printf("ID KEY: %d\n", arrayKey[i].id);
        printf("VALUE KEY: %d\n", arrayKey[i].value);
    }
}

int main()
{
    int option;
    do {
        printf("---------------------------------------------------\n");
        printf("1 - TABELA HASH SOMENTE COM ARRAY ESTATICO\n2 - TABELA HASH COM ARRAY ESTATICO E LISTA ENCADEADA\n0 - SAIR\n");
        printf("---------------------------------------------------\n");
        scanf("%d", &option);
        switch(option){

            case 1:

                printf("---------------------------------------------------\n");
                int sizeArrayKeyStatic;
                printf("INFORME A QUANTIDADE DE CHAVES: ");
                scanf("%d", &sizeArrayKeyStatic);
                Key *arrayKeyStatic = malloc(sizeof(int)*sizeArrayKeyStatic);
                insertArrayKey(arrayKeyStatic, sizeArrayKeyStatic);
                printKeyArray(arrayKeyStatic, sizeArrayKeyStatic);
                break;

            default:
                if(option) {
                    printf("---------------------------------------------------\n");
                    printf("OPCAO INVALIDA\n");
                    printf("---------------------------------------------------\n");
                } else {
                    printf("---------------------------------------------------\n");
                    printf("FINALIZANDO PROGRAMA\n");
                    printf("---------------------------------------------------\n");
                }
                break;
        }
    } while(option);
    return 0;
}
