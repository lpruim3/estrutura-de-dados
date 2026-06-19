#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

/*
 * Struct interna que representa um nó da pilha.
 * Cada nó guarda o valor armazenado e o ponteiro para o nó
 * imediatamente abaixo dele na pilha.
 */
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

/*
 * Struct interna que representa a pilha.
 * Guarda apenas o ponteiro para o nó do topo, o que é suficiente
 * para realizar empilhamento e desempilhamento em tempo O(1).
 */
struct pilha_t {
    no_t *topo;
};

Pilha *pilha_criar(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));

    if (pilha == NULL) {
        return NULL;
    }

    pilha->topo = NULL;

    return pilha;
}

bool pilha_empilhar(Pilha *pilha, int valor) {
    if (pilha == NULL) {
        return false;
    }

    no_t *novo = (no_t *) malloc(sizeof(no_t));

    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return true;
}

bool pilha_desempilhar(Pilha *pilha, int *valor) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) {
        return false;
    }

    no_t *removido = pilha->topo;

    if (valor != NULL) {
        *valor = removido->valor;
    }

    pilha->topo = removido->proximo;
    free(removido);

    return true;
}

bool pilha_topo(Pilha *pilha, int *valor) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) {
        return false;
    }

    if (valor != NULL) {
        *valor = pilha->topo->valor;
    }

    return true;
}

bool pilha_esta_vazia(Pilha *pilha) {
    if (pilha == NULL) {
        return true;
    }

    return pilha->topo == NULL;
}

void pilha_exibir(Pilha *pilha) {
    if (pilha == NULL) {
        printf("Pilha invalida.\n");
        return;
    }

    no_t *atual = pilha->topo;

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

void pilha_destruir(Pilha *pilha) {
    if (pilha == NULL) {
        return;
    }

    no_t *atual = pilha->topo;

    while (atual != NULL) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(pilha);
}