#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void calculaDiaMes(int *d){
    int mes = (*d/30) + 1;
    int dia = *d%30;
    if(dia>=10){
        if(mes>=10)
            printf("%d/%d", dia, mes);
        else
            printf("%d/0%d", dia, mes);
    } else{
        if(mes>=10)
            printf("%d/%d", dia, mes);
        else
            printf("%d/0%d", dia, mes);
    }

}

bool verificaBissexto(int year){
    if(year%400==0){
        return true;
    }else if(year%4==0 && year%100 != 0){
        return true;
    } else
        return false;
}

int main()
{
    int d, a;
    scanf("%d %d", &d, &a);
    calculaDiaMes(&d);
}
