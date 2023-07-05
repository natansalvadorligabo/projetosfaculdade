#include <stdio.h>

void movieReview();

int main(){
    movieReview();

    return 0;
}

void movieReview(){
    int idade, opiniao, max;
    int i = 0;
    int totalRegular = 0;
    int totalGreat = 0;
    double porcentGood;
    double mediaGreat = 0;
    double totalGood = 0;
    double media = 0;
    
    printf("Insira a quantidade de pessoas que participaram da pesquisa: ");
    scanf("%d", &max);

    while (i < max){ // limita quantas pessoas irão participar da pesquisa
        printf("Digite a idade: ");
        scanf("%d", &idade);
        printf("(3) - Ótimo\n(2) - Bom\n(1) - Regular\n"); // com base na tabela
        printf("Deixe a sua opinião (1-3): ");
        scanf("%d", &opiniao);        

        switch (opiniao){
        case 1:
            totalRegular++; // quantidade de pessoas que responderam REGULAR
            break;
        
        case 2:
            totalGood++; 
            break;
        
        case 3:
            media += idade; 
            totalGreat++;
            break;
        
        default:
            printf("Opinião inválida! Por favor, tente novamente.\n");
            break;
        }
        i++;
    }
    mediaGreat = media / totalGreat; // média das idades das pessoas que responderam ÓTIMO
    porcentGood = (totalGood / max) * 100; // porcentagem de pessoas que responderam BOM, entre TODOS os espectadores analisados.

    printf("\nResultados das pesquisas:\n");
    printf("Média das idades das pessoas que responderam ÓTIMO: %.2lf\n", mediaGreat);
    printf("Quantidade de pessoas que responderam REGULAR: %d\n", totalRegular);
    printf("Porcentagem de pessoas que responderam BOM: %.2lf%%\n", porcentGood);
}