#include <stdio.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO (LINHAS * COLUNAS)

void exibe_dois_lacos(int matriz[LINHAS][COLUNAS]) {
    printf("\n[Dois lacos aninhados]\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void exibe_um_laco(int matriz[LINHAS][COLUNAS]) {
    printf("\n[Um unico laco]\n");
    for (int k = 0; k < TAMANHO; k++) {
        int i = k / COLUNAS;
        int j = k % COLUNAS;
        printf("%4d", matriz[i][j]);
        if (j == COLUNAS - 1)
            printf("\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];
    clock_t inicio, fim;
    double tempo;

    int valor = 1;
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            matriz[i][j] = valor++;

    inicio = clock();
    exibe_dois_lacos(matriz);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo (dois lacos): %.6f segundos\n", tempo);

    inicio = clock();
    exibe_um_laco(matriz);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo (um laco):    %.6f segundos\n", tempo);

    printf("\nComplexidade Assintotica\n");
    printf("Dois lacos aninhados: O(n^2) para matrizes n x n\n");
    printf("Um unico laco:        O(n*m)\n");
    printf("Ambas as abordagens tem a mesma complexidade assintotica: O(n*m)\n");

    return 0;
}