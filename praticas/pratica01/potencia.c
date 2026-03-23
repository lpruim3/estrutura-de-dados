#include <stdio.h>

void calcularbase(int base, int exp){
    int resultado = 1;

    if(base == 0 && exp == 0){
        printf("Valor: 1\n");
        return;
    }

    for(int i = 0; i < exp; i++){
        resultado = resultado * base;
    }

    printf("Valor: %d\n", resultado);
}

int main(){

    calcularbase(2, 5);
    calcularbase(3, 2);
    calcularbase(10, 2);

    return 0;
}