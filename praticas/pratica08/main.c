#include <stdio.h>

#include "fila.h"

int main(void) {
    Fila *fila = fila_criar();

    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    printf("=== Teste: fila recem-criada ===\n");
    printf("Fila vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");
    fila_exibir(fila);

    printf("\n=== Teste: enfileiramento de elementos ===\n");
    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);
    fila_enfileirar(fila, 50);
    printf("Fila apos enfileiramentos (inicio -> fim): ");
    fila_exibir(fila);
    printf("Fila vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");

    printf("\n=== Teste: consulta do inicio ===\n");
    int valor_inicio;
    if (fila_inicio(fila, &valor_inicio)) {
        printf("Valor no inicio da fila: %d\n", valor_inicio);
    }
    printf("Fila apos consulta (nao deve mudar): ");
    fila_exibir(fila);

    printf("\n=== Teste: desenfileiramento de elementos ===\n");
    int valor_removido;

    if (fila_desenfileirar(fila, &valor_removido)) {
        printf("Valor desenfileirado: %d\n", valor_removido);
    }
    fila_exibir(fila);

    if (fila_desenfileirar(fila, &valor_removido)) {
        printf("Valor desenfileirado: %d\n", valor_removido);
    }
    fila_exibir(fila);

    printf("\n=== Teste: esvaziar a fila ===\n");
    while (!fila_esta_vazia(fila)) {
        fila_desenfileirar(fila, &valor_removido);
        printf("Valor desenfileirado: %d\n", valor_removido);
    }
    printf("Fila apos remover todos os elementos: ");
    fila_exibir(fila);
    printf("Fila vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");

    printf("\n=== Teste: operacoes em fila vazia ===\n");
    if (!fila_desenfileirar(fila, &valor_removido)) {
        printf("Desenfileirar falhou, como esperado (fila vazia).\n");
    }
    if (!fila_inicio(fila, &valor_inicio)) {
        printf("Consultar inicio falhou, como esperado (fila vazia).\n");
    }

    printf("\n=== Teste: reaproveitar a fila apos esvaziar ===\n");
    fila_enfileirar(fila, 100);
    fila_enfileirar(fila, 200);
    printf("Fila apos novos enfileiramentos: ");
    fila_exibir(fila);

    printf("\n=== Teste: destruicao da fila ===\n");
    fila_destruir(fila);
    printf("Fila destruida com sucesso.\n");

    return 0;
}
