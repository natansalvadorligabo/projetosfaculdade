#include <stdio.h>

void printPrimeNumber();

int main(){
    printPrimeNumber();

    return 0;
}

void printPrimeNumber(){
    int x, i;
    int validacao = 0;

    printf("Insira um número: ");
    scanf("%d", &x);

    for (i = 2; i <= (x / 2); i++) {
        if (x % i == 0){
            validacao++; // 'true' confirma que o número é primo
            break; // encerra o loop
        }
    }

    if (validacao == 0) {
        printf("%d é um número primo!\n", x);
    } else {
        printf("%d NÃO é um número primo!\n", x);
    }
}

