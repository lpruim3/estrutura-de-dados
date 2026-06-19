#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdbool.h>

/*
 * Tipo opaco que representa a tabela hash.
 * A estrutura interna (hash_t) é definida apenas em tabela_hash.c,
 * garantindo o encapsulamento do TDA: quem usa a tabela só conhece
 * o ponteiro TabelaHash, nunca os detalhes de implementação.
 */
typedef struct hash_t TabelaHash;

/*
 * Cria uma tabela hash vazia, com a quantidade de posicoes (buckets)
 * indicada por "tamanho".
 * Retorna um ponteiro para a tabela recém-criada, ou NULL em caso de
 * tamanho invalido ou falha na alocação de memória.
 */
TabelaHash *hash_criar(int tamanho);

/*
 * Insere um novo valor na tabela hash.
 * Em caso de colisão (dois valores mapeados para a mesma posição),
 * o tratamento é feito por encadeamento: o novo valor é adicionado
 * a lista ligada daquela posição. Valores duplicados não são
 * inseridos novamente.
 * Retorna true se a inserção foi bem-sucedida, false em caso de erro
 * (tabela inválida, valor duplicado ou falha na alocação de memória).
 */
bool hash_inserir(TabelaHash *tabela, int valor);

/*
 * Busca um valor na tabela hash.
 * Retorna true se o valor está presente na tabela, false caso contrário.
 */
bool hash_buscar(TabelaHash *tabela, int valor);

/*
 * Remove um valor da tabela hash, caso ele exista.
 * Retorna true se o valor foi encontrado e removido, false caso
 * contrário (valor não encontrado ou tabela inválida).
 */
bool hash_remover(TabelaHash *tabela, int valor);

/*
 * Exibe todas as posicoes da tabela hash e os valores armazenados
 * em cada uma delas (na forma de lista encadeada), permitindo
 * visualizar as colisões tratadas por encadeamento.
 */
void hash_exibir(TabelaHash *tabela);

/*
 * Verifica se a tabela hash está vazia (nenhum valor inserido em
 * nenhuma posição).
 * Retorna true se a tabela não possui elementos (ou é inválida),
 * false caso contrário.
 */
bool hash_esta_vazia(TabelaHash *tabela);

/*
 * Libera toda a memória utilizada pela tabela hash, incluindo todas
 * as listas encadeadas de cada posição e o vetor de posicoes.
 * Após esta chamada, o ponteiro da tabela não deve mais ser utilizado.
 */
void hash_destruir(TabelaHash *tabela);

#endif /* TABELA_HASH_H */
