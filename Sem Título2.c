#include <stdio.h>

int eh_primo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void precalcula_primos_ate(int max, int primos[], int* qtde_primos) {
    *qtde_primos = 0;
    for (int i = 2; i <= max; i++) {
        if (eh_primo(i)) {
            primos[*qtde_primos] = i;
            (*qtde_primos)++;
        }
    }
}

void conjectura_de_goldbach(int n, int primos[], int qtde_primos) {
    if (n <= 2 || n % 2 != 0) {
        printf("A entrada deve ser um numero par maior que 2.\n");
        return;
    }
    for (int i = 0; i < qtde_primos; i++) {
        int primo1 = primos[i];
        int primo2 = n - primo1;

        if (eh_primo(primo2)) {
            printf("%d = %d + %d\n", n, primo1, primo2);
            return;
        }
    }
}

int main() {
    int n;
    printf("Digite um numero inteiro par maior que 2: ");
    scanf("%d", &n);

    int primos[1000]; // Supomos que ha no maximo 1000 numeros primos abaixo de n
    int qtde_primos;

    precalcula_primos_ate(n, primos, &qtde_primos);
    conjectura_de_goldbach(n, primos, qtde_primos);

    return 0;
}
