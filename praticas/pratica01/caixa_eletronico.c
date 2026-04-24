#include <stdio.h>

void calcularNotas(int saque){
    if(saque > 1000){
        printf("Valor invalido\n");
        return;
    }

    int n200, n100, n50, n20, n10, n5, n2;

    n200 = saque / 200;
    saque = saque % 200;

    n100 = saque / 100;
    saque = saque % 100;

    n50 = saque / 50;
    saque = saque % 50;

    n20 = saque / 20;
    saque = saque % 20;

    n10 = saque / 10;
    saque = saque % 10;

    n5 = saque / 5;
    saque = saque % 5;

    n2 = saque / 2;
    saque = saque % 2;

    if(saque == 1){
        if(n5 > 0){
            n5--;
            n2 += 3;
        }
    }

    printf("200: %d\n", n200);
    printf("100: %d\n", n100);
    printf("50: %d\n", n50);
    printf("20: %d\n", n20);
    printf("10: %d\n", n10);
    printf("5: %d\n", n5);
    printf("2: %d\n", n2);
}

int main(){
    int valor = 861;

    calcularNotas(valor);

    return 0;
}