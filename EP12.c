#include <stdio.h>
#include <string.h>

int calcularHash(char *string) {
    int hash = 0;
    int tamanho = strlen(string);
    
    for (int i = 0; i < tamanho; i++) {
        int posicaoAlfabeto = string[i] - 'A';
        hash += posicaoAlfabeto + i + strlen(string);
    }
    
    return hash;
}

int main() {
    int casosTeste;
    scanf("%d", &casosTeste);
    
    for (int i = 0; i < casosTeste; i++) {
        int numLinhas;
        scanf("%d", &numLinhas);
        
        int totalHash = 0;
        
        for (int j = 0; j < numLinhas; j++) {
            char string[51];
            scanf("%s", string);
            totalHash += calcularHash(string);
        }
        
        printf("%d\n", totalHash);
    }
    
    return 0;
}
