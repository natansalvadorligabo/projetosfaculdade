#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_LENGTH 50

typedef struct {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char publisher[MAX_LENGTH];
    int codeBook;
    int yearPublication;
    float price;
} Book;

void bookRegistration();
void bookSearch();
void booksBelowPriceInput();
void numberOfBooksByAuthor();
void bookReport();
void printMainMenu();
void printBookRegistration();
void printBookSearch();
void printBooksBelowPriceInput();
void printNumberOfBooksByAuthor();
void printBookReport();

Book books[MAX_BOOKS];
int count = 0;
int nextCodeBook = 1;

int main() {
    int option;

    do {
        system("cls"); // limpa o terminal (windows)
        printMainMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                bookRegistration();
                break;
            case 2:
                bookSearch();
                break;
            case 3:
                booksBelowPriceInput();
                break;
            case 4:
                numberOfBooksByAuthor();
                break;
            case 5:
                bookReport();
                break;
            case 6:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Operação inválida! Tecle ENTER para tentar novamente...");
                getchar();
                getchar();
        }
    } while (option != 6);

    return 0;
}

void printMainMenu() {
    printf("============= MENU =============\n");
    printf("1. Cadastro de livro\n");
    printf("2. Consulta do livro por código ou título\n");
    printf("3. Consulta de livros com preço inferior ao informado\n");
    printf("4. Consultar o número de livros cadastrados de um autor escolhido\n");
    printf("5. Relatório de livros\n");
    printf("6. Sair do programa\n");
    printf("Escolha uma operação acima: ");
}

void bookRegistration() {
    int option;

    do {
        system("cls"); // limpa o terminal (windows)
        printBookRegistration();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("============= CADASTRO DE LIVRO =============\n");
                
                if (count >= MAX_BOOKS) {
                    printf("Número máximo de livros atingido.\n");
                    printf("Pressione enter para continuar...");
                    getchar();
                    getchar();
                    return;
                }

                Book b;

                printf("Título: ");
                scanf("%s", b.title);

                // verifica se o livro já está cadastrado
                for (int i = 0; i < count; i++) {
                    if (strcmp(books[i].title, b.title) == 0) {
                        printf("Livro já cadastrado.\n");
                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        return;
                    }
                }

                b.price = 0.0;

                printf("Primeiro autor: ");
                scanf("%s", &b.author);
                printf("Editora: ");
                scanf("%s", &b.publisher);
                printf("Ano de publicação: ");
                scanf("%s", &b.yearPublication);
                printf("Código: ");
                scanf("%s", &b.codeBook);
                printf("Preço: ");
                scanf("%d", &b.price);

                books[count] = b;
                
                printf("Livro cadastrado com sucesso!\n");
                printf("Pressione enter para continuar...");
                getchar();
                getchar();

                count++;
                break;

            case 2:
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}



void bookSearch() {
    int option;

    do {
        system("cls"); // limpa o terminal (windows)
        printBookSearch();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("========= CONSULTA POR CÓDIGO =========\n");
                printf("Digite o código do livro: ");
                break;

            case 2:
                printf("========= CONSULTA POR TÍTULO =========\n");
                printf("Digite o título do livro: ");
                break;

            case 3:
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 3);
    
}

void booksBelowPriceInput() {
    printBooksBelowPriceInput();
}

void numberOfBooksByAuthor() {
    printNumberOfBooksByAuthor();
}

void bookReport() {
    printBookReport();
}

void printBookRegistration() {
    printf("============= CADASTRO DE LIVRO =============\n");
    printf("1. Cadastrar livro\n");
    printf("2. Voltar ao menu principal\n");
    printf("Escolha uma operação acima: ");
}

void printBookSearch() {
    printf("========= CONSULTA DE LIVRO =========\n");
    printf("1. Consultar por código\n");
    printf("2. Consultar por título\n");
    printf("3. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}

void printBooksBelowPriceInput() {
    printf("========= CONSULTA DE LIVROS POR PREÇO =========\n");
    printf("Digite o preço máximo: R$");
}

void printNumberOfBooksByAuthor() {
    printf("========= CONSULTA DE LIVROS POR AUTOR =========\n");
    printf("Digite o autor: ");
}

void printBookReport() {
    printf("========= RELATÓRIO DE LIVROS =========\n");
}