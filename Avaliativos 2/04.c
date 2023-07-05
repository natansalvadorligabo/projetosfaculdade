#include <stdio.h>

void radioactivity();

int main(){
    radioactivity();

    return 0;
}

void radioactivity(){
    double weight;
    int second = 0;

    printf("Insira a massa do material (em gramas): ");
    scanf("%lf", &weight);

    if (weight > 0.1){
        do {
            second += 30; // adiciona 30 segundos  
            weight *= 0.75; // reduz 25% da massa
        } while (weight > 0.1);

        printf("Tempo necessário para a massa se tornar menor que 0,10 grama: %d segundos\n", second);
    } else {
        printf("A massa precisa ser maior que 0,10 grama!\n");
    }
}

