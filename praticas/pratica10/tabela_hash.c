#include <stdio.h>
#include <stdlib.h>

#include "tabela_hash.h"

/*
 * Struct interna que representa um nó da lista encadeada usada em
 * cada posição da tabela, para tratar colisões.
 * Cada nó guarda o valor armazenado e o ponteiro para o próximo nó
 * que colidiu na mesma posição.
 */
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} no_t;

/*
 * Struct que representa a tabela hash.
 * "tabela" é um vetor de ponteiros para no_t (um por posição), e
 * "tamanho" é a quantidade de posições do vetor.
 * Cada posição do vetor é a cabeça de uma lista encadeada com os
 * valores que colidiram naquela posição.
 */
struct hash_t {
    no_t **tabela;
    int tamanho;
};

/* Função auxiliar interna: calcula a posição (bucket) de um valor. */
static int hash_funcao(TabelaHash *tabela, int valor);

TabelaHash *hash_criar(int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    TabelaHash *tabela = (TabelaHash *) malloc(sizeof(TabelaHash));

    if (tabela == NULL) {
        return NULL;
    }

    /* Vetor de ponteiros para no_t, um para cada posição da tabela. */
    tabela->tabela = (no_t **) calloc((size_t) tamanho, sizeof(no_t *));

    if (tabela->tabela == NULL) {
        free(tabela);
        return NULL;
    }

    tabela->tamanho = tamanho;

    return tabela;
}

/*
 * Função hash simples: usa o resto da divisão (módulo) pelo tamanho
 * da tabela. Como "valor" pode ser negativo, o resultado é ajustado
 * para garantir que sempre fique no intervalo [0, tamanho - 1].
 */
static int hash_funcao(TabelaHash *tabela, int valor) {
    int posicao = valor % tabela->tamanho;

    if (posicao < 0) {
        posicao += tabela->tamanho;
    }

    return posicao;
}

bool hash_inserir(TabelaHash *tabela, int valor) {
    if (tabela == NULL) {
        return false;
    }

    if (hash_buscar(tabela, valor)) {
        /* Valor já existe na tabela: não permite duplicatas. */
        return false;
    }

    int posicao = hash_funcao(tabela, valor);

    no_t *novo = (no_t *) malloc(sizeof(no_t));

    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;

    /* Insere no início da lista encadeada daquela posição (O(1)). */
    novo->proximo = tabela->tabela[posicao];
    tabela->tabela[posicao] = novo;

    return true;
}

bool hash_buscar(TabelaHash *tabela, int valor) {
    if (tabela == NULL) {
        return false;
    }

    int posicao = hash_funcao(tabela, valor);
    no_t *atual = tabela->tabela[posicao];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }
        atual = atual->proximo;
    }

    return false;
}

bool hash_remover(TabelaHash *tabela, int valor) {
    if (tabela == NULL) {
        return false;
    }

    int posicao = hash_funcao(tabela, valor);
    no_t *atual = tabela->tabela[posicao];
    no_t *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        /* Valor não encontrado na posição correspondente. */
        return false;
    }

    if (anterior == NULL) {
        /* O valor estava no início da lista daquela posição. */
        tabela->tabela[posicao] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    return true;
}

void hash_exibir(TabelaHash *tabela) {
    if (tabela == NULL) {
        printf("Tabela hash invalida.\n");
        return;
    }

    for (int i = 0; i < tabela->tamanho; i++) {
        printf("[%d]: ", i);

        no_t *atual = tabela->tabela[i];

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
}

bool hash_esta_vazia(TabelaHash *tabela) {
    if (tabela == NULL) {
        return true;
    }

    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->tabela[i] != NULL) {
            return false;
        }
    }

    return true;
}

void hash_destruir(TabelaHash *tabela) {
    if (tabela == NULL) {
        return;
    }

    for (int i = 0; i < tabela->tamanho; i++) {
        no_t *atual = tabela->tabela[i];

        while (atual != NULL) {
            no_t *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    free(tabela->tabela);
    free(tabela);
}