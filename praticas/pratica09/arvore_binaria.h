#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdbool.h>


typedef struct arvore_t Arvore;


Arvore *arvore_criar(void);


bool arvore_inserir(Arvore *arvore, int valor);


void arvore_exibir_pre_ordem(Arvore *arvore);


void arvore_exibir_em_ordem(Arvore *arvore);


void arvore_exibir_pos_ordem(Arvore *arvore);


bool arvore_esta_vazia(Arvore *arvore);


void arvore_destruir(Arvore *arvore);

#endif 