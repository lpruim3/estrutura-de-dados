#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct conta_t {
    int numero;
    double saldo;
};

Conta* conta_criar(int numero, double saldo_inicial) {
    Conta *c = (Conta*) malloc(sizeof(Conta));
    c->numero = numero;
    c->saldo = saldo_inicial;
    return c;
}

void conta_depositar(Conta *c, double valor) {
    if (valor > 0)
        c->saldo += valor;
    else
        printf("Valor de deposito invalido.\n");
}

void conta_sacar(Conta *c, double valor) {
    if (valor > 0 && valor <= c->saldo)
        c->saldo -= valor;
    else
        printf("Saldo insuficiente ou valor invalido.\n");
}

double conta_ver_saldo(Conta *c) {
    return c->saldo;
}

void conta_destruir(Conta *c) {
    free(c);
}