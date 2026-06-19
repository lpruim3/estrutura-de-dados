#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

/*
 * Tipo opaco que representa a pilha.
 * A estrutura interna (pilha_t) é definida apenas em pilha.c,
 * garantindo o encapsulamento do TDA: quem usa a pilha só conhece
 * o ponteiro Pilha, nunca os detalhes de implementação.
 */
typedef struct pilha_t Pilha;

/*
 * Cria uma pilha vazia.
 * Retorna um ponteiro para a pilha recém-criada, ou NULL em caso de
 * falha na alocação de memória.
 */
Pilha *pilha_criar(void);

/*
 * Empilha (insere) um novo valor no topo da pilha.
 * Retorna true se a operação foi bem-sucedida, false em caso de erro
 * (pilha inválida ou falha na alocação de memória).
 */
bool pilha_empilhar(Pilha *pilha, int valor);

/*
 * Desempilha (remove) o valor que está no topo da pilha.
 * O valor removido é armazenado em *valor (se valor != NULL).
 * Retorna true se a operação foi bem-sucedida, false caso a pilha
 * esteja vazia ou seja inválida.
 */
bool pilha_desempilhar(Pilha *pilha, int *valor);

/*
 * Consulta o valor que está no topo da pilha, sem removê-lo.
 * O valor consultado é armazenado em *valor (se valor != NULL).
 * Retorna true se a operação foi bem-sucedida, false caso a pilha
 * esteja vazia ou seja inválida.
 */
bool pilha_topo(Pilha *pilha, int *valor);

/*
 * Verifica se a pilha está vazia.
 * Retorna true se a pilha não possui elementos (ou é inválida),
 * false caso contrário.
 */
bool pilha_esta_vazia(Pilha *pilha);

/*
 * Exibe todos os elementos da pilha, do topo para a base,
 * no formato: [v_topo, ..., v_base]
 */
void pilha_exibir(Pilha *pilha);

/*
 * Libera toda a memória utilizada pela pilha, incluindo todos os
 * seus nós. Após esta chamada, o ponteiro da pilha não deve mais
 * ser utilizado.
 */
void pilha_destruir(Pilha *pilha);

#endif /* PILHA_H */