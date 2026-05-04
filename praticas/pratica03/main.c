#include <stdio.h>
#include "conta.h"

int main() {
    Conta *c = conta_criar(1001, 500.00);

    printf("Conta criada: %d\n", 1001);
    printf("Saldo inicial: %.2f\n", conta_ver_saldo(c));

    conta_depositar(c, 200.00);
    printf("Apos deposito de 200.00: %.2f\n", conta_ver_saldo(c));

    conta_sacar(c, 150.00);
    printf("Apos saque de 150.00: %.2f\n", conta_ver_saldo(c));

    conta_sacar(c, 1000.00);

    conta_destruir(c);

    return 0;
}