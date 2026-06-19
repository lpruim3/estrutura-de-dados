#include <stdio.h>

#include "lista_linear.h"

int main(void) {
    Lista *lista = lista_criar();

    if (lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    printf("=== Teste: lista recem-criada ===\n");
    printf("Lista vazia? %s\n", lista_esta_vazia(lista) ? "sim" : "nao");
    lista_exibir(lista);

    printf("\n=== Teste: insercao de elementos ===\n");
    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);
    lista_inserir(lista, 50);
    printf("Lista apos insercoes: ");
    lista_exibir(lista);
    printf("Lista vazia? %s\n", lista_esta_vazia(lista) ? "sim" : "nao");

    printf("\n=== Teste: busca de elementos ===\n");
    int valores_busca[] = {30, 99};
    for (int i = 0; i < 2; i++) {
        int valor = valores_busca[i];
        if (lista_buscar(lista, valor)) {
            printf("Valor %d encontrado na lista.\n", valor);
        } else {
            printf("Valor %d NAO encontrado na lista.\n", valor);
        }
    }

    printf("\n=== Teste: remocao de elementos ===\n");
    printf("Removendo o valor 30 (meio da lista)...\n");
    if (lista_remover(lista, 30)) {
        printf("Remocao bem-sucedida.\n");
    }
    lista_exibir(lista);

    printf("Removendo o valor 10 (inicio da lista)...\n");
    if (lista_remover(lista, 10)) {
        printf("Remocao bem-sucedida.\n");
    }
    lista_exibir(lista);

    printf("Removendo o valor 50 (fim da lista)...\n");
    if (lista_remover(lista, 50)) {
        printf("Remocao bem-sucedida.\n");
    }
    lista_exibir(lista);

    printf("Tentando remover o valor 999 (inexistente)...\n");
    if (!lista_remover(lista, 999)) {
        printf("Remocao falhou, como esperado (valor nao existe).\n");
    }
    lista_exibir(lista);

    printf("\n=== Teste: esvaziar a lista ===\n");
    lista_remover(lista, 20);
    lista_remover(lista, 40);
    printf("Lista apos remover todos os elementos: ");
    lista_exibir(lista);
    printf("Lista vazia? %s\n", lista_esta_vazia(lista) ? "sim" : "nao");

    printf("\n=== Teste: destruicao da lista ===\n");
    lista_destruir(lista);
    printf("Lista destruida com sucesso.\n");

    return 0;
}