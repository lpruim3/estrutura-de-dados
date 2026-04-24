#include "selecao.h"

int linear_search(int vetor[], int tamanho, int valor) {
    int menor_idx = 0;
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < vetor[menor_idx])
            menor_idx = i;
    }
    return menor_idx;
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

int quick_select(int vetor[], int inicio, int fim, int k) {
    if (inicio == fim)
        return vetor[inicio];

    int p = particionar(vetor, inicio, fim);

    if (k == p)
        return vetor[p];
    else if (k < p)
        return quick_select(vetor, inicio, p - 1, k);
    else
        return quick_select(vetor, p + 1, fim, k);
}