/*
   O código implementa um sistema de gerenciamento de contas bancárias. 
   Ele permite cadastrar novas contas, realizar depósitos, saques e consultas
   de saldo.

   As contas são armazenadas em uma estrutura de dados do tipo Account,
   que possui um número de conta, nome do titular e saldo. As contas são 
   armazenadas em um vetor "accounts" e o número de contas registradas é 
   controlado pela variável "count". O próximo número de conta disponível é 
   armazenado na variável "nextAccountNumber".

   No geral, o código oferece funcionalidades básicas para um sistema bancário, 
   permitindo a interação com contas, depósitos, saques e consultas de saldo.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 50
#define MAX_NAME_LENGTH 40

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

void accountRegistration();
void printMainMenu();
void printDepositMenu();
void printWithdrawalMenu();
void printBalanceMenu();
void deposit();
void withdrawal();
void balanceInquiry();

Account accounts[MAX_ACCOUNTS];
int count = 0;
int nextAccountNumber = 1;

int main() {
    int option;

    do {
        system("cls"); // limpa o terminal (windows)
        printMainMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                accountRegistration();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdrawal();
                break;
            case 4:
                balanceInquiry();
                break;
            case 5:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Operação inválida! Tecle ENTER para tentar novamente...");
                getchar();
                getchar();
        }
    } while (option != 5);

    return 0;
}

void printMainMenu() {
    printf("========= MENU =========\n");
    printf("1. Cadastramento da conta\n");
    printf("2. Depósito\n");
    printf("3. Saque\n");
    printf("4. Consulta\n");
    printf("5. Sair\n");
    printf("Escolha uma operação acima: ");
}

void accountRegistration() {
    if (count >= MAX_ACCOUNTS) {
        printf("Número máximo de contas atingido.\n");
        printf("Pressione enter para continuar...");
        getchar();
        getchar();
        return;
    }

    Account a;

    printf("Nome: ");
    scanf("%s", a.name);

    // verifica se o cliente já possui uma conta
    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].name, a.name) == 0) {
            printf("Cliente já possui uma conta.\n");
            printf("Pressione enter para continuar...");
            getchar();
            getchar();
            return;
        }
    }

    // gera um número de conta sequencial e único
    a.accountNumber = nextAccountNumber++;
    a.balance = 0.0;

    accounts[count] = a;
    printf("Conta cadastrada com sucesso! Número da conta: %d\n", a.accountNumber);
    printf("Pressione enter para continuar...");
    getchar();
    getchar();

    count++;
}

void printDepositMenu() {
    printf("========= Depósito =========\n");
    printf("1. Realizar depósito\n");
    printf("2. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}

void deposit() {
    int option;
    int accountNumber;
    float depositAmount;

    do {
        system("cls"); // limpa o terminal (windows)
        printDepositMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o número da conta: ");
                scanf("%d", &accountNumber);

                for (int i = 0; i < count; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        printf("Qual é o valor do depósito? R$ ");
                        scanf("%f", &depositAmount);

                        if (depositAmount < 0) {
                            printf("Não é possível realizar depósito de valor negativo.\n");
                            printf("Pressione enter para continuar...");
                            getchar();
                            getchar();
                            break;
                        }

                        accounts[i].balance += depositAmount;
                        printf("Depósito realizado com sucesso! Novo saldo: %.2f\n", accounts[i].balance);
                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }

                if (option == 1 && (accountNumber < 1 || accountNumber > nextAccountNumber)) {
                    printf("Conta não encontrada.\n");
                    printf("Pressione enter para continuar...");
                    getchar();
                    getchar();
                }

                break;

            case 2:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}

void withdrawal() {
    int option;
    int accountNumber;
    float withdrawalAmount;

    do {
        system("cls"); // limpa o terminal (windows)
        printWithdrawalMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o número da conta: ");
                scanf("%d", &accountNumber);

                for (int i = 0; i < count; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        printf("Qual é o valor do saque? R$ ");
                        scanf("%f", &withdrawalAmount);

                        if (withdrawalAmount < 0) {
                            printf("Não é possível realizar saque de valor negativo.\n");
                            printf("Pressione enter para continuar...");
                            getchar();
                            getchar();
                            break;
                        }

                        if (withdrawalAmount > accounts[i].balance) {
                            printf("Saldo insuficiente para realizar o saque.\n");
                            printf("Pressione enter para continuar...");
                            getchar();
                            getchar();
                            break;
                        }

                        accounts[i].balance -= withdrawalAmount;
                        printf("Saque realizado com sucesso! Novo saldo: %.2f\n", accounts[i].balance);
                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }

                if (option == 1 && (accountNumber < 1 || accountNumber > nextAccountNumber)) {
                    printf("Conta não encontrada.\n");
                    printf("Pressione enter para continuar...");
                    getchar();
                    getchar();
                }

                break;

            case 2:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}

void printWithdrawalMenu() {
    printf("========= Saque =========\n");
    printf("1. Realizar saque\n");
    printf("2. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}

void balanceInquiry() {
    int option;
    int accountNumber;

    do {
        system("cls"); // limpa o terminal (windows)
        printBalanceMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o número da conta: ");
                scanf("%d", &accountNumber);

                for (int i = 0; i < count; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        printf("Saldo da conta: %.2f\n", accounts[i].balance);
                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }

                if (option == 1 && (accountNumber < 1 || accountNumber > nextAccountNumber)) {
                    printf("Conta não encontrada.\n");
                    printf("Pressione enter para continuar...");
                    getchar();
                    getchar();
                }

                break;

            case 2:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}

void printBalanceMenu() {
    printf("========= Consulta =========\n");
    printf("1. Consultar saldo\n");
    printf("2. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}
