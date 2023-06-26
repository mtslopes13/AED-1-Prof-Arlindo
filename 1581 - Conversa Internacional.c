#include <stdio.h>
#include <string.h>

#define MAX_LANGUAGE_LENGTH 21
#define MAX_GROUP_SIZE 101

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases > 0) {
        int groupSize;
        char languages[MAX_GROUP_SIZE][MAX_LANGUAGE_LENGTH];
        int languageCount[MAX_GROUP_SIZE] = {0};

        scanf("%d", &groupSize);

        // Ler os idiomas nativos de cada pessoa no grupo
        for (int i = 0; i < groupSize; i++) {
            scanf("%s", languages[i]);
        }

        // Verificar se há duas pessoas com idiomas nativos diferentes
        int englishRequired = 0;
        for (int i = 0; i < groupSize - 1; i++) {
            for (int j = i + 1; j < groupSize; j++) {
                if (strcmp(languages[i], languages[j]) != 0) {
                    englishRequired = 1;
                    break;
                }
            }
            if (englishRequired) {
                break;
            }
        }

        // Se necessário, definir o idioma mais apropriado como inglês
        char mostAppropriateLanguage[MAX_LANGUAGE_LENGTH];
        if (englishRequired) {
            strcpy(mostAppropriateLanguage, "ingles");
        } else {
            strcpy(mostAppropriateLanguage, languages[0]);
            int maxCount = 1;

            // Encontrar o idioma mais comum no grupo
            for (int i = 1; i < groupSize; i++) {
                int count = 1;
                for (int j = i + 1; j < groupSize; j++) {
                    if (strcmp(languages[i], languages[j]) == 0) {
                        count++;
                    }
                }
                if (count > maxCount) {
                    maxCount = count;
                    strcpy(mostAppropriateLanguage, languages[i]);
                }
            }
        }

        printf("%s\n", mostAppropriateLanguage);

        numCases--;
    }

    return 0;
}