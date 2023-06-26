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
int bookAuthorCount = 0;
int nextCode = 1;
int bookCodes[MAX_BOOKS];

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

void bookRegistration() {
    int option, i;

    do {
        system("cls"); // limpa o terminal (windows)
        printBookRegistration();
        scanf("%d", &option);

        switch (option) {
            case 1:
                system("cls"); // limpa o terminal (windows)             
                if (count >= MAX_BOOKS) {
                    printf("Número máximo de livros atingido.\n");
                    printf("Pressione enter para voltar...");
                    getchar();
                    getchar();
                    return;
                }

                printf("============= CADASTRO DE LIVRO =============\n");

                Book b;

                printf("Título: ");
                scanf("%s", b.title);
                getchar();

                // verifica se o livro já está cadastrado
                for (i = 0; i < count; i++) {
                    if (strcmp(books[i].title, b.title) == 0) {
                        printf("Livro já cadastrado.\n");
                        printf("Pressione enter para continuar...");
                        getchar();
                        return;
                    }
                }

                b.price = 0.0;

                printf("Primeiro autor: ");
                scanf("%s", b.author);
                if (strcmp(books[i].author, b.author) == 0) {
                    bookAuthorCount++;
                }
                printf("Editora: ");
                scanf("%s", b.publisher);
                printf("Ano de publicação: ");
                scanf("%d", &b.yearPublication);
                printf("Preço: ");
                scanf("%f", &b.price);

                b.codeBook = nextCode++;
                books[count] = b;
                bookCodes[count] = b.codeBook;

                printf("Livro cadastrado com sucesso! Código do livro: %d\n", b.codeBook);
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
    int option, code, i;
    char title[MAX_LENGTH];

    do {
        system("cls"); // limpa o terminal (windows)
        printBookSearch();
        scanf("%d", &option);

        switch (option) {
            case 1:
                system("cls"); // limpa o terminal (windows)
                printf("========= CONSULTA POR CÓDIGO =========\n");
                printf("Digite o código do livro: ");
                scanf("%d", &code);

                for (i = 0; i < count; i++) {
                    if (books[i].codeBook == code) {
                        printf("--------- LIVRO %d ---------\n", books[i].codeBook);
                        printf("Título: %s\n", books[i].title);
                        printf("Primeiro autor: %s\n", books[i].author);
                        printf("Editora: %s\n", books[i].publisher);
                        printf("Ano de publicação: %d\n", books[i].yearPublication);
                        printf("Preço: %.2f\n", books[i].price);
                        printf("----------------------------\n");

                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    } 
                }
                    if (books[i].codeBook != code){
                        printf("Livro não encontrado.\n");
                        printf("Pressione enter para continuar...");
                        getchar();
                        break;
                    }

                break;

            case 2:
                system("cls"); // limpa o terminal (windows)
                printf("========= CONSULTA POR TÍTULO =========\n");
                printf("Digite o título do livro: ");
                scanf("%s", title);

                for (int i = 0; i < count; i++) {
                    if (strcmp(books[i].title, title) == 0) {
                        printf("--------- LIVRO '%s' ---------\n", books[i].title);
                        printf("Primeiro autor: %s\n", books[i].author);
                        printf("Editora: %s\n", books[i].publisher);
                        printf("Ano de publicação: %d\n", books[i].yearPublication);
                        printf("Preço: %.2f\n", books[i].price);
                        printf("Código: %d\n", books[i].codeBook);
                        printf("----------------------------\n");

                        printf("Pressione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }

                if (strcmp(books[i].title, title) != 0){
                    printf("Livro não encontrado.\n");
                    printf("Pressione enter para continuar...");
                    getchar();
                    getchar();
                }

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
    int option, i;
    float price;

    do {
        system("cls"); // limpa o terminal (windows)
        printBooksBelowPriceInput();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("========= CONSULTA DE LIVROS POR PREÇO =========\n");
                printf("Digite o preço máximo: R$");
                scanf("%f", &price);

                for (i = 0; i < count; i++) {
                    if (books[i].price < price) {
                        printf("\n--------- LIVRO %.2f ---------\n", books[i].price);
                        printf("Título: %s\n", books[i].title);
                        printf("Primeiro autor: %s\n", books[i].author);
                        printf("Editora: %s\n", books[i].publisher);
                        printf("Ano de publicação: %d\n", books[i].yearPublication);
                        printf("Código: %d\n", books[i].codeBook);
                        printf("----------------------------\n");
                        printf("Pressione enter para continuar...");
                        getchar();
                    }
                }

                break;

            case 2:
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}

void numberOfBooksByAuthor() {
    int option, i;
    char author[MAX_LENGTH];

    do {
        system("cls"); // limpa o terminal (windows)
        printNumberOfBooksByAuthor();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("============= CONSULTA DE LIVROS POR AUTOR =============\n");
                printf("Digite o nome autor: ");
                scanf("%s", author);

                int bookAuthorCount = 0;
                for (i = 0; i < count; i++) {
                    if (strcmp(books[i].author, author) == 0) {
                        bookAuthorCount++;
                    }
                }

                if (bookAuthorCount > 0) {
                    printf("O autor %s possui %d livro(s) cadastrados.\n", author, bookAuthorCount);
                } else {
                    printf("Autor não encontrado.\n");
                }

                printf("Pressione enter para continuar...");
                getchar();
                getchar();

                break;

            case 2:
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (option != 2);
}

void bookReport() {
    int i;

    printBookReport();
    for (i = 0; i < count; i++) {
        printf("--------- LIVRO %d ---------\n", books[i].codeBook);
        printf("Título: %s\n", books[i].title);
        printf("Primeiro autor: %s\n", books[i].author);
        printf("Editora: %s\n", books[i].publisher);
        printf("Ano de publicação: %d\n", books[i].yearPublication);
        printf("Preço: %.2f\n", books[i].price);
        printf("----------------------------\n");
    }
    printf("Pressione enter para continuar...");
    getchar();
    getchar();
}

void printMainMenu() {
    printf("============= MENU =============\n");
    printf("1. Cadastro de livro\n");
    printf("2. Consulta de livro\n");
    printf("3. Consulta de livros abaixo de um preço informado\n");
    printf("4. Consulta do número de livros de um autor informado\n");
    printf("5. Relatório de livros cadastrados\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
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
    printf("1. Consultar livro por preço\n");
    printf("2. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}

void printNumberOfBooksByAuthor() {
    printf("========= NÚMERO DE LIVROS POR AUTOR =========\n");
    printf("1. Consultar número de livros por autor\n");
    printf("2. Voltar ao menu principal\n");
    printf("Digite sua opção: ");
}

void printBookReport() {
    printf("============= RELATÓRIO DE LIVROS =============\n");
    printf("Livros cadastrados: %d\n", count);
}