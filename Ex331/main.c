#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
Exercício 331: Bubble Sort

->Algorítmo de ordenação mais simples

->O comportamento do algoritmo se assemelha ao comportamento de uma bolha.

->Não é eficiente, pois quanto maior um vetor, maior será o tempo de execução do código.

->Organiza do final do array para o início.
*/

void bubbleSort(int *arrayInteger, int sizeArray)
/*
Procedimento de ordenação de um conjunto sequêncial
de dados - array, cujo é percorrido desde o início
fazendo comparações entre um elemento e seu sucessor,
caso o elemento seja maior que o sucessor, é trocado
de lugar, até que o elemento fique ordenado, sendo
realizada a percursão do vetor n vezes para organizar
todos os valores do vetor.

Recebe como parâmetro um vetor e o tamanho desse vetor.
*/
{
    bool change = 1;//Otimizador que irá indicar quando o vetor estiver ordenado
    while(change)//Ponto de parada caso o vetor esteja ordenado
    {
        change = 0;//Recebe 0, caso o vetor esteja ordenado, esse valaor irá se manter
        for(int j = 0; j < sizeArray-1; j++)//Percorrendo cada posição do array
        {

            for(int i = 0; i < sizeArray-1; i++)/*Percorrendo de posição em posição organizando os maiores valores,
                                               garantindo que ao menos a ultima posição do vetor (sizeArray-1)
                                               estará com o valor correto */
            {
                if(arrayInteger[i] > arrayInteger[i+1])/*Caso a posição referente tenha um
                                                         valor maior que o valor da posição
                                                         sucessora*/
                {
                        int aux = arrayInteger[i];//Variável auxiliar recebe o valor maior
                        arrayInteger[i] = arrayInteger[i+1];//Posiçao do valor maior recebe o valor menor
                        arrayInteger[i+1] = aux;//Posição do valor menor recebe o valor maior
                        change = 1;//Validação de que uma troca foi realizada
                }
            }
            sizeArray--;/*Decresce sizeArray pois a cada laço realizado é organizado
                          um valor correto na última posição do vetor (sizeArray-1)*/
        }
    }
}

void bubbleSortRecursivo(int *arrayInteger, int sizeArray)
/*
Procedimento que organiza um conjunto de dados
sequenciais - array, cujo é percorrido sempre
do início analisando se um valor na posição
referente é maior que o valor na posição
sucessora, realizando troca de valores entre
as posições analisadas.

É feita através de recursão, onde a cada chamada recursiva
a posição final do vetor(sizeArray-1) estará organizada;
*/
{
    if (sizeArray<2) return;//Caso o vetor ja esteja organizado - PONTO DE PARADA

    for(int i = 0; i < sizeArray-1; i++)/*Percorrendo de posição em posição analisando
                                          se a posição referente possui um valor maior
                                          que o valor da posição sucessora, onde caso
                                          tenha, será trocadas as posições, garante assim
                                          que no final do loop ao menos a última posição
                                          estará organizada com o valor correto.*/
    {
        if(arrayInteger[i] > arrayInteger[i+1])/*Caso o valor da posição referente
                                                seja maior que o valor da posição
                                                sucessora*/
        {
            int aux = arrayInteger[i];//Variável auxiliar recebe o maior valor
            arrayInteger[i] = arrayInteger[i+1];//Posição do maior valor recebe o menor valor
            arrayInteger[i+1] = aux;//Posição do menor valor recebe o maior valor
        }
    }
    bubbleSortRecursivo(arrayInteger, sizeArray-1);/*Chamada recursiva passando arraySize-1 pois a cada
                                                     execução do loop é organizado corretamente um valor
                                                     em sua devida posição no final do vetor, logo essa
                                                     posição do vetor não deve ser passada como parâmetro
                                                     para evitar processamento desnecessário*/
}

void generateArrayInteger(int *arrayInteger, int sizeArray)
/*
Procedimento que gera valores aleatórios
para as posições de um vetor.
*/
{
    srand(time(NULL));//Definindo o tempo como semente da função rand
    for(int i = 0 ; i < sizeArray ; i++)//Percorrendo cada posição do vetor
    {
        arrayInteger[i] = rand() % 100000x  ;//Atribuindo um valor aleatório para a posição referente
    }
}

void printArrayInteger(int *arrayInteger, int sizeArray)
/*
Procedimento que mostra os valores de um vetor.

Recebe como parâmetros um vetor e o tamanho do vetor.
*/
{
    for(int i = 0 ; i < sizeArray ; i++)//Percorrendo cada posição do vetor
    {
        if(i == 0)//Caso seja o primeiro loop
            printf("[");
        if(i <sizeArray-1)//Caso não seja o último elemento do vetor
            printf("%d, ", arrayInteger[i]);
        else//Caso seja o último elemento do vetor
            printf("%d]\n", arrayInteger[i]);
    }
}

int main()
{
    int userValue;//Definindo uma variável que diz respeito ao tamanho do vetor que será informado pelo usuário
    printf("Tamanho do vetor: ");
    scanf("%d", &userValue);//Atribuindo o tamanho do vetor informado pelo usuário
    int arrayInteger[userValue];//Criando um vetor com o tamanho informado pelo usuário
    printf("------------------------------\n");
    generateArrayInteger(arrayInteger, userValue);//Atribuindo valores alaeatorios para o vetor criado pelo usuário
    printf("Vetor desorganizado:\n");
    printArrayInteger(arrayInteger, userValue);//Mostrando os valores contidos no vetor
    printf("------------------------------\n");
    bubbleSort(arrayInteger, userValue);//Acionando o procedimento de organização para o vetor
    printf("Vetor organizado:\n");
    printArrayInteger(arrayInteger, userValue);//Mostrando o vetor organizado
    printf("------------------------------\n");

    return 0;
}
