#include <stdio.h>

#include "arvore_binaria.h"

int main(void) {
    Arvore *arvore = arvore_criar();

    if (arvore == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }

    printf("=== Teste: arvore recem-criada ===\n");
    printf("Arvore vazia? %s\n", arvore_esta_vazia(arvore) ? "sim" : "nao");
    printf("Pre-ordem:  ");
    arvore_exibir_pre_ordem(arvore);
    printf("Em-ordem:   ");
    arvore_exibir_em_ordem(arvore);
    printf("Pos-ordem:  ");
    arvore_exibir_pos_ordem(arvore);

    printf("\n=== Teste: insercao de elementos ===\n");
    
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 35};
    int quantidade = (int) (sizeof(valores) / sizeof(valores[0]));

    for (int i = 0; i < quantidade; i++) {
        if (arvore_inserir(arvore, valores[i])) {
            printf("Valor %d inserido com sucesso.\n", valores[i]);
        } else {
            printf("Falha ao inserir o valor %d.\n", valores[i]);
        }
    }

    printf("Arvore vazia? %s\n", arvore_esta_vazia(arvore) ? "sim" : "nao");

    printf("\n=== Teste: insercao de valor duplicado ===\n");
    if (!arvore_inserir(arvore, 30)) {
        printf("Insercao do valor 30 falhou, como esperado (duplicado).\n");
    }

    printf("\n=== Teste: percursos da arvore ===\n");
    printf("Pre-ordem  (raiz, esquerda, direita): ");
    arvore_exibir_pre_ordem(arvore);
    printf("Em-ordem   (esquerda, raiz, direita):  ");
    arvore_exibir_em_ordem(arvore);
    printf("Pos-ordem  (esquerda, direita, raiz):  ");
    arvore_exibir_pos_ordem(arvore);

    printf("\nObservacao: o percurso em-ordem de uma arvore binaria de\n");
    printf("busca sempre exibe os valores em ordem crescente.\n");

    printf("\n=== Teste: destruicao da arvore ===\n");
    arvore_destruir(arvore);
    printf("Arvore destruida com sucesso.\n");

    return 0;
}