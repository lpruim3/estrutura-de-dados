#include <stdio.h>
#include <stdlib.h>

#include "arvore_binaria.h"

/*
 * Struct interna que representa um nó da árvore.
 * Cada nó guarda o valor armazenado e os ponteiros para as
 * subárvores esquerda e direita.
 */
typedef struct no_t {
    struct no_t *esquerda;
    int valor;
    struct no_t *direita;
} no_t;

/*
 * Struct que representa a árvore binária.
 * Guarda apenas o ponteiro para o nó raiz.
 */
struct arvore_t {
    no_t *raiz;
};

/* Funções auxiliares internas, que operam diretamente sobre no_t. */
static no_t *no_inserir(no_t *no, int valor, bool *sucesso);
static void no_exibir_pre_ordem(no_t *no);
static void no_exibir_em_ordem(no_t *no);
static void no_exibir_pos_ordem(no_t *no);
static void no_destruir(no_t *no);

Arvore *arvore_criar(void) {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));

    if (arvore == NULL) {
        return NULL;
    }

    arvore->raiz = NULL;

    return arvore;
}

bool arvore_inserir(Arvore *arvore, int valor) {
    if (arvore == NULL) {
        return false;
    }

    bool sucesso = true;
    arvore->raiz = no_inserir(arvore->raiz, valor, &sucesso);

    return sucesso;
}

/*
 * Insere recursivamente um valor na subárvore apontada por "no".
 * Retorna o ponteiro para a raiz da subárvore (possivelmente um
 * novo nó, se "no" era NULL). Em *sucesso é indicado se a inserção
 * de fato ocorreu (false em caso de valor duplicado ou falha de
 * alocação).
 */
static no_t *no_inserir(no_t *no, int valor, bool *sucesso) {
    if (no == NULL) {
        no_t *novo = (no_t *) malloc(sizeof(no_t));

        if (novo == NULL) {
            *sucesso = false;
            return NULL;
        }

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < no->valor) {
        no->esquerda = no_inserir(no->esquerda, valor, sucesso);
    } else if (valor > no->valor) {
        no->direita = no_inserir(no->direita, valor, sucesso);
    } else {
        /* Valor já existe na árvore: não permite duplicatas. */
        *sucesso = false;
    }

    return no;
}

void arvore_exibir_pre_ordem(Arvore *arvore) {
    if (arvore == NULL) {
        printf("Arvore invalida.\n");
        return;
    }

    printf("[ ");
    no_exibir_pre_ordem(arvore->raiz);
    printf("]\n");
}

static void no_exibir_pre_ordem(no_t *no) {
    if (no == NULL) {
        return;
    }

    printf("%d ", no->valor);
    no_exibir_pre_ordem(no->esquerda);
    no_exibir_pre_ordem(no->direita);
}

void arvore_exibir_em_ordem(Arvore *arvore) {
    if (arvore == NULL) {
        printf("Arvore invalida.\n");
        return;
    }

    printf("[ ");
    no_exibir_em_ordem(arvore->raiz);
    printf("]\n");
}

static void no_exibir_em_ordem(no_t *no) {
    if (no == NULL) {
        return;
    }

    no_exibir_em_ordem(no->esquerda);
    printf("%d ", no->valor);
    no_exibir_em_ordem(no->direita);
}

void arvore_exibir_pos_ordem(Arvore *arvore) {
    if (arvore == NULL) {
        printf("Arvore invalida.\n");
        return;
    }

    printf("[ ");
    no_exibir_pos_ordem(arvore->raiz);
    printf("]\n");
}

static void no_exibir_pos_ordem(no_t *no) {
    if (no == NULL) {
        return;
    }

    no_exibir_pos_ordem(no->esquerda);
    no_exibir_pos_ordem(no->direita);
    printf("%d ", no->valor);
}

bool arvore_esta_vazia(Arvore *arvore) {
    if (arvore == NULL) {
        return true;
    }

    return arvore->raiz == NULL;
}

void arvore_destruir(Arvore *arvore) {
    if (arvore == NULL) {
        return;
    }

    no_destruir(arvore->raiz);
    free(arvore);
}

static void no_destruir(no_t *no) {
    if (no == NULL) {
        return;
    }

    no_destruir(no->esquerda);
    no_destruir(no->direita);
    free(no);
}