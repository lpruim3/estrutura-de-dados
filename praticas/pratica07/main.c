#include <stdio.h>

#include "pilha.h"

int main(void) {
    Pilha *pilha = pilha_criar();

    if (pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    printf("=== Teste: pilha recem-criada ===\n");
    printf("Pilha vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");
    pilha_exibir(pilha);

    printf("\n=== Teste: empilhamento de elementos ===\n");
    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);
    pilha_empilhar(pilha, 50);
    printf("Pilha apos empilhamentos (topo -> base): ");
    pilha_exibir(pilha);
    printf("Pilha vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");

    printf("\n=== Teste: consulta do topo ===\n");
    int valor_topo;
    if (pilha_topo(pilha, &valor_topo)) {
        printf("Valor no topo da pilha: %d\n", valor_topo);
    }
    printf("Pilha apos consulta (nao deve mudar): ");
    pilha_exibir(pilha);

    printf("\n=== Teste: desempilhamento de elementos ===\n");
    int valor_removido;

    if (pilha_desempilhar(pilha, &valor_removido)) {
        printf("Valor desempilhado: %d\n", valor_removido);
    }
    pilha_exibir(pilha);

    if (pilha_desempilhar(pilha, &valor_removido)) {
        printf("Valor desempilhado: %d\n", valor_removido);
    }
    pilha_exibir(pilha);

    printf("\n=== Teste: esvaziar a pilha ===\n");
    while (!pilha_esta_vazia(pilha)) {
        pilha_desempilhar(pilha, &valor_removido);
        printf("Valor desempilhado: %d\n", valor_removido);
    }
    printf("Pilha apos remover todos os elementos: ");
    pilha_exibir(pilha);
    printf("Pilha vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");

    printf("\n=== Teste: operacoes em pilha vazia ===\n");
    if (!pilha_desempilhar(pilha, &valor_removido)) {
        printf("Desempilhar falhou, como esperado (pilha vazia).\n");
    }
    if (!pilha_topo(pilha, &valor_topo)) {
        printf("Consultar topo falhou, como esperado (pilha vazia).\n");
    }

    printf("\n=== Teste: destruicao da pilha ===\n");
    pilha_destruir(pilha);
    printf("Pilha destruida com sucesso.\n");

    return 0;
}