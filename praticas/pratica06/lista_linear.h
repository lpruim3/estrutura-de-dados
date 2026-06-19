#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

#include <stdbool.h>


typedef struct lista_t Lista;


Lista *lista_criar(void);


bool lista_inserir(Lista *lista, int valor);


bool lista_remover(Lista *lista, int valor);


bool lista_buscar(Lista *lista, int valor);


void lista_exibir(Lista *lista);


bool lista_esta_vazia(Lista *lista);


void lista_destruir(Lista *lista);

#endif 