#include "ordenacao.h"

void bubble_sort(int vetor[], int tamanho) {
    int temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int vetor[], int tamanho) {
    int temp, min;
    for (int i = 0; i < tamanho - 1; i++) {
        min = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min])
                min = j;
        }
        temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }
}

static int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
    int temp;
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return i + 1;
}

void quick_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(vetor, inicio, fim);
        quick_sort(vetor, inicio, p - 1);
        quick_sort(vetor, p + 1, fim);
    }
}