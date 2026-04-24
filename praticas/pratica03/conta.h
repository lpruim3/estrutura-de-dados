#ifndef CONTA_H
#define CONTA_H

typedef struct conta_t Conta;

Conta* conta_criar(int numero, double saldo_inicial);
void conta_depositar(Conta *c, double valor);
void conta_sacar(Conta *c, double valor);
double conta_ver_saldo(Conta *c);
void conta_destruir(Conta *c);

#endif