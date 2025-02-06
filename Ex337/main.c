#include <stdio.h>
#include <stdlib.h>
/*Exercício 337: Counting Sort

É um algoritmo de complexidade O(N) eficiente quando o intervalor de valores R é menor ou igual a N.

Funciona baseando-se na contagem da frequência dos valores no array original.

O algoritmo abaixo é realizado para ordenadar elementos pertencentes ao conjunto dos números naturais.
*/

void countingSort(int *array, int firstPosition, int lastPosition) {

    int sizeArray = lastPosition-firstPosition+1;

    //DEFINE INTERVALO - ETAPA 1
    int R = array[firstPosition];//Intervalo de frequência dos valores de 0...maxValue

    for(int position = firstPosition+1; position < sizeArray; position++) //Complexidade N
    //Definindo o intervalo do array de frequência
        if(array[position] > R) R = array[position]+1;

    int count[R+1];/*Criando um array de R+1 espaços que conta a frequência dos valores de um array, sendo que count[value+1] = frequência de value
                    Vale ressaltar que count[0] não será utilizado para contar frequência de nenhum número pois os número naturais começam em 0
                    e a frequência de 0 é localizada em count[0+1] ou seja count[1]*/

    //LIMPA ARRAY DE FREQUENCIA - ETAPA 2
    for(int clear = 0; clear <= R; clear++) //Complexidade R
    //Limpando lixo de memória do array de frequência
        count[clear] = 0;


    //MONTA ARRAY DE REQUENCIA - ETAPA 3
    for(int position = firstPosition; position < sizeArray; position++) //Complexidade N
    //Contando a frequência dos valores do array original - ETAPA 1
        count[array[position]+1]++;

    /*printf("ARRAY DE FREQUENCIA: ");
    printf("[");
    for(int i = 0; i <= R; i++) {
        printf(" %d ",count[i]);
    }
    printf("]\n");*/

    //MONTA ARRAY DE POSICOES - ETAPA 4
    for(int position = 1; position <= R; position++) //Complexidade R
    //Definir posições dos valores do array através da frequência
        count[position] = count[position]/*Frequência do valor em position*/ + count[position-1]/*Frequência do valor da posição anterior*/; //Posição incial de um valor

    /*printf("ARRAY DE POSICOES: ");
    printf("[");
    for(int i = 0; i <= R; i++) {
        printf(" %d ",count[i]);
    }
    printf("]\n");*/

    //MONTA ARRAY AUXILIAR - ETAPA 5
    int aux[sizeArray];//Array auxiliar que recebe o array original ordenado

    for(int position = firstPosition; position < sizeArray; position++)
    //Distribuir os elementos ordenados em um array auxiliar
        aux[count[array[position]]/*Posição de um valor baseado na frequência*/] = array[position];//Array auxiliar recebe o valor ordenado

    /*printf("ARRAY AUXILIAR ORNADO: ");
    printf("[");
    for(int i = 0; i < sizeArray; i++) {
        printf(" %d ",aux[i]);
    }
    printf("]\n");*/

    //ARRAY ORIGINAL - ETAPA 6
    for(int position = firstPosition; position < sizeArray; position++)
    //Copia o array auxiliar para o array original
        array[position] = aux[position];
}

int main()
{
    int array[5] = {3, 9, 1, 7, 4};//Criando um array qualquer não ordenado
    printf("ARRAY NAO ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",array[i]);
    }
    printf("]\n");
    countingSort(array, 0, 4);//Aplicando Counting Sort
    printf("ARRAY ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",array[i]);
    }
    printf("]\n");

    return 0;
}
