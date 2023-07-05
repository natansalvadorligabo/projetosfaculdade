#include <stdio.h>

void printFactorial();

int main(){
    printFactorial();
    
    return 0;
}

void printFactorial() {
    int num, i;

    do {
        printf("Insira um número positivo: ");
        scanf("%d", &num);
        if (num < 0){ // verifica se o número é positivo
            printf("O número inserido precisar ser POSITIVO!\n");
        }
    } while (num < 0);
    for (i = 1; num > 1; num--) { // fatorial do número 
        i = i * num; 
    }

    printf("O fatorial do número é %d\n", i);
}