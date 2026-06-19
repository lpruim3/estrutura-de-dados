#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

/*
 * Tipo opaco que representa a fila.
 * A estrutura interna (fila_t) é definida apenas em fila.c,
 * garantindo o encapsulamento do TDA: quem usa a fila só conhece
 * o ponteiro Fila, nunca os detalhes de implementação.
 */
typedef struct fila_t Fila;

/*
 * Cria uma fila vazia.
 * Retorna um ponteiro para a fila recém-criada, ou NULL em caso de
 * falha na alocação de memória.
 */
Fila *fila_criar(void);

/*
 * Enfileira (insere) um novo valor no fim da fila.
 * Retorna true se a operação foi bem-sucedida, false em caso de erro
 * (fila inválida ou falha na alocação de memória).
 */
bool fila_enfileirar(Fila *fila, int valor);

/*
 * Desenfileira (remove) o valor que está no início da fila.
 * O valor removido é armazenado em *valor (se valor != NULL).
 * Retorna true se a operação foi bem-sucedida, false caso a fila
 * esteja vazia ou seja inválida.
 */
bool fila_desenfileirar(Fila *fila, int *valor);

/*
 * Consulta o valor que está no início da fila, sem removê-lo.
 * O valor consultado é armazenado em *valor (se valor != NULL).
 * Retorna true se a operação foi bem-sucedida, false caso a fila
 * esteja vazia ou seja inválida.
 */
bool fila_inicio(Fila *fila, int *valor);

/*
 * Exibe todos os elementos da fila, do início para o fim,
 * no formato: [v_inicio, ..., v_fim]
 */
void fila_exibir(Fila *fila);

/*
 * Verifica se a fila está vazia.
 * Retorna true se a fila não possui elementos (ou é inválida),
 * false caso contrário.
 */
bool fila_esta_vazia(Fila *fila);

/*
 * Libera toda a memória utilizada pela fila, incluindo todos os
 * seus nós. Após esta chamada, o ponteiro da fila não deve mais
 * ser utilizado.
 */
void fila_destruir(Fila *fila);

#endif /* FILA_H */