#include <stdio.h>

double calcTotal();

int main() {
    int salgado, quantidadeSalgado = 0, bebida, quantidadeBebida = 0, pagamento, maisSalgados, maisBebidas, quantidadeTotalSalgados = 0, quantidadeTotalBebidas = 0;
    double totalGasto = 0.0, valorEntregue, totalSalgado = 0.0, totalBebida = 0.0, troco;

    // cardapio + info
    printf("\n----- Coxinhas Douradas de Bueno -----\n"); 

    // salgados
    while (1) {
        printf("--------- Cardápio Salgados ----------\n");
        printf("(1) Coxinhas (frango) - R$ 6,50\n(2) Enrolado (presunto e queijo) - R$ 6,50\n(3) Bola1 (frango e catupiry)- R$ 8,80\n(4) Bola2 (brócolis e catupiry) - R$ 8,80\n(5) Bola3 (camarão) - R$ 9,60\n(6) Bola4 (queijo e catupiry) - R$ 6,50\n");
        printf("Escolha o salgado (1-6) ou 0 para encerrar: ");
        scanf("%d", &salgado);
        
        if (salgado == 0) {
            break;
        }
        
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidadeSalgado);
        
        switch (salgado) {
            case 1:
                totalSalgado += 6.50 * quantidadeSalgado;
                break;
            case 2:
                totalSalgado += 6.50 * quantidadeSalgado;
                break;
            case 3:
                totalSalgado += 8.80 * quantidadeSalgado;
                break;
            case 4:
                totalSalgado += 8.80 * quantidadeSalgado;
                break;
            case 5:
                totalSalgado += 9.60 * quantidadeSalgado;
                break;
            case 6:
                totalSalgado += 6.50 * quantidadeSalgado;
                break;
            default:
                printf("Opção de salgado inválida.\n");
                break;
            quantidadeTotalSalgados++;
        }
        
        printf("Quer escolher mais salgados? (1 - Sim, 0 - Não): ");
        scanf("%d", &maisSalgados);
        if (maisSalgados == 0) {
            break;
        }
    }

    // bebidas
    while (1) {
        printf("\n---------- Cardápio Bebidas ----------\n");
        printf("(1) Água - R$ 3,00\n(2) Água com gás - R$ 3,50\n(3) Refrigerante - R$ 5,00\n(4) Suco (lata) - R$ 7,50\n(5) Cerveja R$ 5,00\n");
        printf("Escolha a bebida (1-5) ou 0 para encerrar: ");
        scanf("%d", &bebida);
        
        if (bebida == 0) {
            break;
        }
        
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidadeBebida);
        
        switch (bebida) {
            case 1:
                totalBebida += 3.00 * quantidadeBebida;
                break;
            case 2:
                totalBebida += 3.50 * quantidadeBebida;
                break;
            case 3:
                totalBebida += 5.00 * quantidadeBebida;
                break;
            case 4:
                totalBebida += 7.50 * quantidadeBebida;
                break;
            case 5:
                totalBebida += 5.00 * quantidadeBebida;
                break;
            default:
                printf("Opção de bebida inválida.\n");
                break;
            quantidadeTotalBebidas++;
        }
        
        printf("Quer escolher mais bebidas? (1 - Sim, 0 - Não): ");
        scanf("%d", &maisBebidas);
        if (maisBebidas == 0) {
            break;
        }
    }
    
    totalGasto = calcTotal(totalSalgado, totalBebida);

    // forma de pagamento
    printf("\n-------- Formas de Pagamento ---------\n");
    printf("(1) Em dinheiro\n(2) Débito\n(3) Crédito\n(4) Crédito em 2X\n");
    printf("Escolha a forma de pagamento (1-4): ");
    scanf("%d", &pagamento);
    switch (pagamento) { 
        case 1:
            printf("Valor entregue pelo cliente: ");
            scanf("%lf", &valorEntregue);
            troco = valorEntregue - totalGasto;
            printf("O troco do cliente é R$ %.2lf\n", troco); // retorna o troco em dinheiro
            break;
        case 2: // acréscimo de 3%
            totalGasto = totalGasto * 1.03;
            break;
        case 3: // acréscimo de 5%
            totalGasto = totalGasto * 1.05;
            break;
        case 4: // acréscimo de 10%
            totalGasto = totalGasto * 1.1;
            break;
        default:
            printf("Opção de pagamento inválida.\n");
    }

    printf("Total de salgados pedidos: %d\n", quantidadeTotalSalgados);
    printf("Total de bebidas pedidas: %d\n", quantidadeTotalBebidas);
    printf("Total gasto: R$ %.2lf\n", totalGasto);

    return 0;
}

double calcTotal(double totalSalgado, double totalBebida) {
    return totalSalgado + totalBebida;
}