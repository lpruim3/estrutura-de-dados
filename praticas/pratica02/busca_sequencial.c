#include <stdio.h>

#define TAMANHO 100

int busca_sequencial(int vetor[], int tamanho, int valor, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if (vetor[i] == valor)
            return i;
    }
    return -1;
}

int main() {
    int vetor[TAMANHO];
    int valor = 42;
    int indice, comparacoes;

    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i + 1;
    }

    indice = busca_sequencial(vetor, TAMANHO, valor, &comparacoes);

    printf("Busca Sequencial\n");
    printf("Valor buscado: %d\n", valor);

    if (indice != -1)
        printf("Valor %d encontrado no indice %d.\n", valor, indice);
    else
        printf("Valor %d nao encontrado no vetor.\n", valor);

    printf("Comparacoes realizadas: %d\n", comparacoes);

    printf("\nComplexidade Assintotica\n");
    printf("Melhor caso: O(1) - elemento encontrado na 1a posicao\n");
    printf("Pior caso:   O(n) - elemento na ultima posicao ou ausente\n");
    printf("Caso medio:  O(n/2) = O(n)\n");

    return 0;
}