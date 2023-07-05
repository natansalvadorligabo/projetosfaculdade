#include <stdio.h>

void printPerfectNumber();

int main() {
    printPerfectNumber();

    return 0;
}

void printPerfectNumber() {
    int count = 0;  
    int number = 2; // verificação começa a partir do número dois
    int sum = 1; 
    int i;

    while (count < 4) { // encerra ao escrever os quatro primeiros números perfeitos
        for (sum = 1, i = 2; i <= number / 2; i++) { 
            if (number % i == 0) { // verifica os divisores
                sum += i; 
            }
        }

        if (sum == number) { // verifica se o número é perfeito
            printf("%d\n", number);
            count++;
        }

        number++; // vai para o próximo número
    }
}