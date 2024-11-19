#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Exercício 192: Escreva um procedimento que receba um vetor inteiro, seu tamanho e os
endereços de duas variáveis inteiras, menor e maior, salve nestas variáveis
o menor e o maior valor do vetor;

->Encontrar o maior e menor elemento de um vetor com ponteiro
*/

void mmArray(int *arrayInteger, int sizeArray, int *minor, int *major){
/*
Criando um procedimento que recebe como parâmetro um vetor inteiro(endereço de memória),
o tamanho do vetor e dois endereços de memória para salvar o menor e o maior valor contido
no ponteiro nessas variáveis
*/
    for(int c = 0; c<sizeArray;c++)//Percorrendo o vetor
    {
        if(c==0){
            *major = *arrayInteger;//Atribuindo o conteúdo da primeira posição do vetor para major
            *minor = *arrayInteger;//Atribuindo o conteúdo da primeira posição do vetor para minor
        }else{
            if(*(arrayInteger+c)>*major)//Verificando se o conteúdo de cada posição do vetor é maior
                *major = *(arrayInteger+c);/*Atribuindo ao conteúdo de major, através de aritmética de
                                             ponteiros, o valor do conteúdo da posição*/
            if(*(arrayInteger+c)< *minor)//Verfificando se o conteúdo de cada posição do vetor é menor
                *minor = *(arrayInteger+c);/*Atribuindo ao conteúdo de minor, através de aritmética de
                                             ponteiros, o valor do conteúdo da posição*/
        }
    }
}

int sizeArray(){//Criando uma função que retorna um número que será usado como tamanho de um vetor
    int number;//Criando a variável que irá armazenar o valor do tamanho do vetor
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &number);//Armazenando o tamanho do vetor na variável
    return number;//Retornando este valor
}

void generateArray(int arrayInteger [],int sizeArray){//Crinado um procedimento que gera um valor aleatório pra cada posição do vetor
    srand(time(NULL));//Definindo a semente da função rand para que se baseie no tempo
    for(int c = 0; c < sizeArray; c++)//Percorrendo o vetor
    {
        arrayInteger[c] = rand();//Atribuindo a cada posição do vetor um número aleatório
    }
}

void printArray(int arrayInteger [], int sizeArray){//Criando um procedimento que informa cada elemento do vetor
        for(int c = 0; c < sizeArray; c++)//Percorrendo o vetor
    {
        if(c==0)
            printf("[");
        if(c<=sizeArray-2)
            printf("%d, ", arrayInteger[c]);
        else
            printf("%d]\n", arrayInteger[c]);
    }
}


int main()
{
    int size = sizeArray();//Acionando a função que retorna o tamanho de um vetor
    int arrayInteger[size];//Criando um vetor
    generateArray(arrayInteger, size);//Acionando o procedimento que gera um número aleatório pra cada posição do vetor
    printArray(arrayInteger, size);//Acionando o procedimento que informa os valores contidos em cada posição do vetor
    int minor, major;//Criando duas variáveis que receberão o maior e menor elemento do vetor
    mmArray(arrayInteger, size, &minor, &major);/*Acionando o procedimento que recebe como parâmetro o endereço
                                                  de memória das variáveis menor e maior para que atribua
                                                  à elas o menor e maior valor do vetor*/
    printf("Maior: %d\n", major);
    printf("Menor: %d\n", minor);


    return 0;
}
