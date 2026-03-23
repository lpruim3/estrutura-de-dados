//imc.c: Ler o peso e a altura de uma pessoa, calcular o IMC e informar a situação dela conforme a escala abaixo do peso (< 18.5), peso normal (18.5 até 24.9), sobrepeso (25.0 até 29.9) ou obesidade (30.0+);
#include <stdio.h>

void calcularIMC(float peso, float altura){
    float imc;
    if(peso <= 0 ||altura <= 0){
        printf("Valores Invalidos\n");
        return;
    }
    imc= peso/(altura * altura);

    printf("IMC: %.2f\n",imc);

    if (imc <18.5) {
        printf("Abaixo do Peso\n");
    }
    else if (imc <25) {
        printf("Peso Normal\n");
    }
    else if (imc < 30) {
        printf("Sobrepeso\n");
    }
    else {
        printf("Obesidade\n");
    }
}

int main(){
    calcularIMC(60, 1.57);
    calcularIMC(74, 1.74);

    return 0;
}