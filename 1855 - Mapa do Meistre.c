#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int x;
    int y;
} Point;

Point getNextPosition(Point currentPos, char direction) {
    Point nextPos = currentPos;
    if (direction == '>') {
        nextPos.x++;
    } else if (direction == '<') {
        nextPos.x--;
    } else if (direction == 'v') {
        nextPos.y++;
    } else if (direction == '^') {
        nextPos.y--;
    }
    return nextPos;
}

int isInsideMap(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int isMapValid(char map[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    Point startPos = {0, 0};
    Point currentPos = startPos;
    char currentSymbol = map[currentPos.y][currentPos.x];

    while (1) {
        if (currentSymbol == '*' || currentSymbol == '!') {
            break;
        }

        Point nextPos = getNextPosition(currentPos, currentSymbol);

        if (!isInsideMap(nextPos.x, nextPos.y, width, height)) {
            return 0; // Mapa inválido
        }

        currentPos = nextPos;
        currentSymbol = map[currentPos.y][currentPos.x];
    }

    return currentSymbol == '*'; // Mapa válido se o símbolo atual for '*'
}

int main() {
    int width, height;
    char map[MAX_HEIGHT][MAX_WIDTH];

    // Lê a largura e altura do mapa
    scanf("%d", &width);
    scanf("%d", &height);

    // Lê o mapa
    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
    }

    // Verifica se o mapa é válido
    if (isMapValid(map, width, height)) {
        printf("*\n");
    } else {
        printf("!\n");
    }

    return 0;
}