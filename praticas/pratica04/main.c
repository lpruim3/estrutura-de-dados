#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 100

void copiar_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        destino[i] = origem[i];
}

int main() {
    int original[TAMANHO], v1[TAMANHO], v2[TAMANHO], v3[TAMANHO];
    clock_t inicio, fim;
    double tempo;

    srand(42);
    for (int i = 0; i < TAMANHO; i++)
        original[i] = rand() % 1000;

    copiar_vetor(original, v1, TAMANHO);
    copiar_vetor(original, v2, TAMANHO);
    copiar_vetor(original, v3, TAMANHO);

    inicio = clock();
    bubble_sort(v1, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Bubble Sort:    %.6f segundos\n", tempo);

    inicio = clock();
    selection_sort(v2, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Selection Sort: %.6f segundos\n", tempo);

    inicio = clock();
    quick_sort(v3, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Quick Sort:     %.6f segundos\n", tempo);

    return 0;
}