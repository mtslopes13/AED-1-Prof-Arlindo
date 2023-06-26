#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void imprimirInfixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        imprimirInfixa(raiz->esquerda, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        imprimirInfixa(raiz->direita, primeiro);
    }
}

void imprimirPrefixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        imprimirPrefixa(raiz->esquerda, primeiro);
        imprimirPrefixa(raiz->direita, primeiro);
    }
}

void imprimirPosfixa(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        imprimirPosfixa(raiz->esquerda, primeiro);
        imprimirPosfixa(raiz->direita, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}

int pesquisar(No* raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    } else if (valor == raiz->valor) {
        return 1;
    } else if (valor < raiz->valor) {
        return pesquisar(raiz->esquerda, valor);
    } else {
        return pesquisar(raiz->direita, valor);
    }
}

int main() {
    No* raiz = NULL;
    char comando[8];
    char valor;
    int primeiro;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        } else if (strcmp(comando, "INFIXA") == 0) {
            if (raiz != NULL) {
                primeiro = 1;
                imprimirInfixa(raiz, &primeiro);
                printf("\n");
            }
        } else if (strcmp(comando, "PREFIXA") == 0) {
            if (raiz != NULL) {
                primeiro = 1;
                imprimirPrefixa(raiz, &primeiro);
                printf("\n");
            }
        } else if (strcmp(comando, "POSFIXA") == 0) {
            if (raiz != NULL) {
                primeiro = 1;
                imprimirPosfixa(raiz, &primeiro);
                printf("\n");
            }
        } else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        }
    }

    return 0;
}
