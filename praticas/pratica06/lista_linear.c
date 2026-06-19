#include <stdio.h>
#include <stdlib.h>

#include "lista_linear.h"


typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} no_t;


struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

Lista *lista_criar(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));

    if (lista == NULL) {
        return NULL;
    }

    lista->primeiro = NULL;
    lista->ultimo = NULL;

    return lista;
}

bool lista_inserir(Lista *lista, int valor) {
    if (lista == NULL) {
        return false;
    }

    no_t *novo = (no_t *) malloc(sizeof(no_t));

    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista_esta_vazia(lista)) {
        /* Lista vazia: o novo nó é o primeiro e o último. */
        lista->primeiro = novo;
        lista->ultimo = novo;
    } else {
        /* Lista não vazia: o novo nó passa a ser o último. */
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }

    return true;
}

bool lista_remover(Lista *lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) {
        return false;
    }

    no_t *atual = lista->primeiro;

    /* Percorre a lista em busca do valor a ser removido. */
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        /* Valor não encontrado na lista. */
        return false;
    }

    /* Ajusta o nó anterior (ou a cabeça da lista). */
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->primeiro = atual->proximo;
    }

    /* Ajusta o nó seguinte (ou a cauda da lista). */
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->ultimo = atual->anterior;
    }

    free(atual);

    return true;
}

bool lista_buscar(Lista *lista, int valor) {
    if (lista == NULL) {
        return false;
    }

    no_t *atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }
        atual = atual->proximo;
    }

    return false;
}

void lista_exibir(Lista *lista) {
    if (lista == NULL) {
        printf("Lista invalida.\n");
        return;
    }

    no_t *atual = lista->primeiro;

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

bool lista_esta_vazia(Lista *lista) {
    if (lista == NULL) {
        return true;
    }

    return lista->primeiro == NULL;
}

void lista_destruir(Lista *lista) {
    if (lista == NULL) {
        return;
    }

    no_t *atual = lista->primeiro;

    while (atual != NULL) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}