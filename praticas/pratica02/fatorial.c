#include <stdio.h>

long long fatorial_iterativo(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n = 10;

    printf("Fatorial de %d\n", n);
    printf("Iterativo:  %lld\n", fatorial_iterativo(n));
    printf("Recursivo:  %lld\n", fatorial_recursivo(n));

    printf("\nComplexidade Assintotica\n");
    printf("Iterativo: O(n) em tempo, O(1) em espaco\n");
    printf("Recursivo: O(n) em tempo, O(n) em espaco\n");

    return 0;
}