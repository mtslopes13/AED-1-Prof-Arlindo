#include <stdio.h>

int calcularHash(char* linha) {
    int i, hash = 0;
    for (i = 0; linha[i] != '\0'; i++) {
        int posicaoAlfabeto = linha[i] - 'A';
        int elemento = 0;
        int posicao = i;
        int valor = posicaoAlfabeto + elemento + posicao;
        hash += valor;
    }
    return hash;
}

int main() {
    int casosTeste;
    scanf("%d", &casosTeste);

    while (casosTeste > 0) {
        int numLinhas;
        scanf("%d", &numLinhas);

        int i, j;
        for (i = 0; i < numLinhas; i++) {
            char linha[51];
            scanf("%s", linha);

            int hash = 0;
            for (j = 0; linha[j] != '\0'; j++) {
                int posicaoAlfabeto = linha[j] - 'A';
                int elemento = i;
                int posicao = j;
                int valor = posicaoAlfabeto + elemento + posicao;
                hash += valor;
            }
            printf("%d\n", hash);
        }

        casosTeste--;
    }

    return 0;
}
