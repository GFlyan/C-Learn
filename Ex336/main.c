#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Exercício 336: Intro Sort

É um algoritmo linearitmico híbrido que possui 2 versões e é composto por 3 algoritmos diferentes:

1ª VERSÃO: Quick Sort + Merge Sort + Insertion Sort -> caso possa utilizar espaço extra (algoritmo se torna outplace), pois Merge Sort é mais eficiente que Heap Sort
2ª VERSÃO: Quick Sort + Heap Sort + Insertion Sort -> caso não possa utilizar espaço extra (algoritmo se mantem inplace)
*/


int partition(int *array, int leftPosition, int rightPosition)
/*Função que particiona o array em menores e maiores em relação
a um pivô*/
{
    int pivot = (array[leftPosition]+array[(leftPosition+rightPosition)/2]+array[rightPosition])/3;
    //Pivô com mediana de 3, evita desbalanceamento para as chamadas logaritmicas afim de evitar o pior caso do Quick Sort O(N²)
    while(leftPosition < rightPosition) {
        while(array[leftPosition] <= pivot && leftPosition < rightPosition)
            leftPosition++;
        while(array[rightPosition] > pivot && leftPosition < rightPosition)
            rightPosition--;
        if(leftPosition < rightPosition) {
            int backup = array[leftPosition];
            array[leftPosition] = array[rightPosition];
            array[rightPosition] = backup;
        }
    }
    return rightPosition;
}

void fixDown(int *array, int fixPosition, int lastPosition)
/*Procedimento que arruma a prioridade de uma Heap de cima
para baixo*/
{
    while(2*fixPosition <= lastPosition) {
        int sonPosition = 2*fixPosition;
        if(sonPosition < lastPosition && array[sonPosition] < array[sonPosition+1]) sonPosition++;
        if(array[fixPosition] > array[sonPosition]) break;
        int backup = array[fixPosition];
        array[fixPosition] = array[sonPosition];
        array[sonPosition] = backup;
        fixPosition = sonPosition;
    }
}

void heapSort(int *array, int firstPosition, int lastPosition)
/*Procedimento referente a um Heap Sort*/
{
    int *heap = array-1+firstPosition;//Cria uma Heap quebrada onde heap[1] = array[0]
    int lastPositionHeap = lastPosition-firstPosition+1;//Ultima posição da Heap, que também é o tamanho do array a ser ordenado
    for(int fixPosition = lastPositionHeap/2; fixPosition >= 1; fixPosition--) fixDown(heap, fixPosition, lastPositionHeap);//Conserta a Heap aplicando fixDown para cada nó pai garantindo subHeaps a cada aplicação
    while(lastPositionHeap > 1)
    /*Swap do prioritario com o último, aplicando fixDown
    no novo primeiro ao diminuir a posição do final da Heap.*/
    {
        //Swap prioritário com elemento final da Heap
        int backup = heap[1];
        heap[1] = heap[lastPositionHeap];
        heap[lastPositionHeap] = backup;

        fixDown(heap, 1, --lastPositionHeap);//Conserta o swap e diminui o tamanho da Heap, para fazer uma inserção do final para o início
    }
}

void insertionSort(int *array, int firstPosition, int lastPosition)
/*Procedimento referente a um Insertion Sort*/
{
    int sizeArray = lastPosition-firstPosition+1;
    for(int fixPosition = firstPosition+1; fixPosition < sizeArray; fixPosition++) {
        int backup = array[fixPosition], insertionPosition = fixPosition;
        while(insertionPosition > 0 && backup < array[insertionPosition-1]){
            array[insertionPosition] = array[insertionPosition-1];
            insertionPosition--;
        }
        array[insertionPosition] = backup;
    }
}

void intro(int *array, int firstPosition, int lastPosition, int maxDepth)
/*Procedimento que realiza a ordenação do array utilizando
Quick Sort + Heap Sort (ou Merge)*/
{

    if(lastPosition-firstPosition <= 15)
    /*Caso a quantidade de elementos contida no subArray seja menor que 15
    é considerado um array pequeno, dessa forma é melhor utilizar o Insertion
    Sort para ordenar*/
        return;

    else if(maxDepth == 0)
    /*Caso o limite ideal da altura da árvore de recursão do Quick Sort
    seja atingida para que o Intro Sort não perca eficiência de O(N LOG2(N))
    para O(N²), mudaremos para o Heap Sort garantindo a eficiencia O(N LOG2(N))*/

        heapSort(array, firstPosition, lastPosition);//Ativação do Heap Sort
    else
      /*Caso o limite ideal da altura da árvore de recursão do Quick Sort não
      tenha sido ultrapassado, então o Quick Sort ainda pode ser realizado*/
    {

        //Melhorias para o Quick Sort caso a Partition não utilize pivo com mediana de 3

        /*
        compexch(array[firstPosition], array[(firstPosition+lastPosition)/2]); //Compara o primeiro elemento do vetor com o elemento na metade do vetor, caso o primeiro seja maior, ocorre swap
        compexch(array[firstPosition], array[lastPosition]); //Compara o primeiro elemento do vetor com o último elemento na metade do vetor, caso o primeiro seja maior, ocorre swap
        compexch(array[lastPosition], array[(firstPosition+lastPosition)/2]); //Compara o último elemento do vetor com o elemento na metade do vetor, caso o último seja maior, ocorre swap
        */

        //Acionando o Quick Sort diminuindo o limite ideal da altura da árvore de recursão
        int mid = partition(array, firstPosition, lastPosition);//Particiona o array em menores a esquerda e maiores a direita em relação a um pivo com mediana de 3
        intro(array, firstPosition, mid-1, maxDepth-1);//Acionamento da intro para o array particionado a esquerda diminuindo o limite ideal de recursão do Quick Sort
        intro(array, mid+1, lastPosition, maxDepth-1);//Acionamento da intro para o array particionado a direita diminuindo o limite ideal de recursão do Quick Sort
    }
}

void introSort(int *array, int firstPosition, int lastPosition) {
    int sizeArray = lastPosition-firstPosition+1;//Tamanho do array
    int maxDepth =  2*((int)log2((double)(sizeArray))); //Limite ideal de recursões para manter o Quick Sort eficiente baseando-se no tamanho do array, caso ultrapassado, entregar o array ao Heap Sort

    /*O calculo logarítmico retorna a altura ideal da árvore de recursão do Quick Sort para que ele seja eficiente O(N LOG (N)),
    entãp multiplicamos por 2 (não influencia na eficiencia) para garantir uma margem segura para que o Quick Sort trabalhe antes de
    ser substituido pelo Heap Sort.

    Ou seja, multiplicar por 2 é dar mais chances ao Quick Sort para ele trabalhar.

    O resultado fornecido por maxDepth representa a altura do limite ideal da árvore de recursões que o Quick Sort
    deve realizar para ordenar o array mantendo eficiencia de O(N LOG2(N)), caso esse limite ideal seja ultrapassado,
    o custo de realização do Quick Sort passa de O(N LOG2(N)) para O(N²), devendo assim ser interrompido e entregue
    ao Heap Sort(ou Merge Sort) para garantir a eficiencia de O(N LOG2(N)).*/

    intro(array, firstPosition, lastPosition, maxDepth);//Quick Sort + Heap Sort (ou Merge Sort)
    insertionSort(array, firstPosition, lastPosition);//Insertion Sort
}

int main()
{
    int array[5] = {4, 9, 1, 3, 8};//Criando um array qualquer não ordenado
    printf("ARRAY NAO ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",array[i]);
    }
    printf("]\n");
    introSort(array, 0, 4);//Aplicando Insertion Sort
    printf("ARRAY ORDENADO: ");
    printf("[");
    for(int i = 0; i < 5; i++) {
        printf(" %d ",array[i]);
    }
    printf("]\n");
    return 0;
}
