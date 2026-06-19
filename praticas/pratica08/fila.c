#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

/*
 * Struct interna que representa um nó da fila.
 * Cada nó guarda o valor armazenado e o ponteiro para o próximo
 * nó da fila.
 */
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

/*
 * Struct que representa a fila.
 * Guarda os ponteiros para o nó do início e do fim, o que torna
 * o enfileiramento e o desenfileiramento operações O(1).
 */
struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila *fila_criar(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));

    if (fila == NULL) {
        return NULL;
    }

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

bool fila_enfileirar(Fila *fila, int valor) {
    if (fila == NULL) {
        return false;
    }

    no_t *novo = (no_t *) malloc(sizeof(no_t));

    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(fila)) {
        /* Fila vazia: o novo nó é o início e o fim. */
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        /* Fila não vazia: o novo nó passa a ser o fim. */
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    return true;
}

bool fila_desenfileirar(Fila *fila, int *valor) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        return false;
    }

    no_t *removido = fila->inicio;

    if (valor != NULL) {
        *valor = removido->valor;
    }

    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        /* A fila ficou vazia: o ponteiro de fim também deve ser atualizado. */
        fila->fim = NULL;
    }

    free(removido);

    return true;
}

bool fila_inicio(Fila *fila, int *valor) {
    if (fila == NULL || fila_esta_vazia(fila)) {
        return false;
    }

    if (valor != NULL) {
        *valor = fila->inicio->valor;
    }

    return true;
}

void fila_exibir(Fila *fila) {
    if (fila == NULL) {
        printf("Fila invalida.\n");
        return;
    }

    no_t *atual = fila->inicio;

    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("]\n");
}

bool fila_esta_vazia(Fila *fila) {
    if (fila == NULL) {
        return true;
    }

    return fila->inicio == NULL;
}

void fila_destruir(Fila *fila) {
    if (fila == NULL) {
        return;
    }

    no_t *atual = fila->inicio;

    while (atual != NULL) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(fila);
}