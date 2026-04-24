#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

void copiar_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        destino[i] = origem[i];
}

int main() {
    int original[TAMANHO], v1[TAMANHO], v2[TAMANHO];
    clock_t inicio, fim;
    double tempo;
    int k = 0;

    srand(42);
    for (int i = 0; i < TAMANHO; i++)
        original[i] = rand() % 1000;

    copiar_vetor(original, v1, TAMANHO);
    copiar_vetor(original, v2, TAMANHO);

    inicio = clock();
    int idx = linear_search(v1, TAMANHO, 0);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Linear Search: menor elemento = %d | tempo: %.6f segundos\n", v1[idx], tempo);

    inicio = clock();
    int resultado = quick_select(v2, 0, TAMANHO - 1, k);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quick Select:  %do menor elemento = %d | tempo: %.6f segundos\n", k + 1, resultado, tempo);

    return 0;
}