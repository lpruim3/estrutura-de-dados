#include <stdio.h>

void calcularMedia(int n, float numeros[]){
    float soma = 0;
    
    if(n > 100){
        printf("Quantidade invalida\n");
        return;
    }

    for(int i = 0; i < n; i++){
        soma = soma + numeros[i];
    }

    float media = soma / n;

    printf("Media: %.2f\n", media);
}

int main(){
    int n = 5;

    float valores[100] = {7.0, 8.5, 6.0, 9.0, 10.0};

    calcularMedia(n, valores);

    return 0;
}