#include <stdio.h>

#include "tabela_hash.h"

int main(void) {
    /*
     * Tabela com 7 posições. Usando essa quantidade, é fácil forcar
     * colisões propositalmente: valores cuja diferença é múltipla
     * de 7 caem na mesma posição (ex.: 10 e 17, pois 17 - 10 = 7).
     */
    TabelaHash *tabela = hash_criar(7);

    if (tabela == NULL) {
        printf("Erro ao criar a tabela hash.\n");
        return 1;
    }

    printf("=== Teste: tabela recem-criada ===\n");
    printf("Tabela vazia? %s\n", hash_esta_vazia(tabela) ? "sim" : "nao");
    hash_exibir(tabela);

    printf("\n=== Teste: insercao de elementos (com colisoes propositais) ===\n");
    /*
     * 10 % 7 = 3
     * 17 % 7 = 3  -> colide com 10
     * 24 % 7 = 3  -> colide com 10 e 17
     * 20 % 7 = 6
     * 13 % 7 = 6  -> colide com 20
     * 5  % 7 = 5
     */
    int valores[] = {10, 17, 24, 20, 13, 5};
    int quantidade = (int) (sizeof(valores) / sizeof(valores[0]));

    for (int i = 0; i < quantidade; i++) {
        if (hash_inserir(tabela, valores[i])) {
            printf("Valor %d inserido com sucesso.\n", valores[i]);
        } else {
            printf("Falha ao inserir o valor %d.\n", valores[i]);
        }
    }

    printf("\nTabela apos as insercoes (note as colisoes nas posicoes 3 e 6):\n");
    hash_exibir(tabela);
    printf("Tabela vazia? %s\n", hash_esta_vazia(tabela) ? "sim" : "nao");

    printf("\n=== Teste: insercao de valor duplicado ===\n");
    if (!hash_inserir(tabela, 17)) {
        printf("Insercao do valor 17 falhou, como esperado (duplicado).\n");
    }

    printf("\n=== Teste: busca de elementos ===\n");
    int valores_busca[] = {24, 99};
    for (int i = 0; i < 2; i++) {
        int valor = valores_busca[i];
        if (hash_buscar(tabela, valor)) {
            printf("Valor %d encontrado na tabela.\n", valor);
        } else {
            printf("Valor %d NAO encontrado na tabela.\n", valor);
        }
    }

    printf("\n=== Teste: remocao de elementos ===\n");
    printf("Removendo o valor 17 (meio da lista da posicao 3)...\n");
    if (hash_remover(tabela, 17)) {
        printf("Remocao bem-sucedida.\n");
    }
    hash_exibir(tabela);

    printf("Tentando remover o valor 999 (inexistente)...\n");
    if (!hash_remover(tabela, 999)) {
        printf("Remocao falhou, como esperado (valor nao existe).\n");
    }

    printf("\n=== Teste: esvaziar a tabela ===\n");
    for (int i = 0; i < quantidade; i++) {
        hash_remover(tabela, valores[i]);
    }
    printf("Tabela apos remover todos os elementos:\n");
    hash_exibir(tabela);
    printf("Tabela vazia? %s\n", hash_esta_vazia(tabela) ? "sim" : "nao");

    printf("\n=== Teste: destruicao da tabela ===\n");
    hash_destruir(tabela);
    printf("Tabela destruida com sucesso.\n");

    return 0;
}