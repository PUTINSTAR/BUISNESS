#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

const int SIZE = 9;
char array1[SIZE][SIZE];

struct Ship {
    int length;
    int row;
    int col;
    bool isHorizontal;
};

void drawShip(struct Ship s) {
    for (int i = 0; i < s.length; i++) {
        if (s.isHorizontal)
            array1[s.row][s.col + i] = '#';
        else
            array1[s.row + i][s.col] = '#';
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct Ship ships[3];  
    int direction;

    for (int i = 0; i < 3; i++) {
        printf("Длина корабля: ");
        scanf("%d", &ships[i].length);

        printf("Строка: ");
        scanf("%d", &ships[i].row);

        printf("Столбец: ");
        scanf("%d", &ships[i].col);

        printf("Горизонтально? (1 - да, 2 - нет): ");
        scanf("%d", &direction);

        ships[i].row--;
        ships[i].col--;

        ships[i].isHorizontal = (direction == 1);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            array1[i][j] = '.';
    }

    for (int i = 0; i < 3; i++) {
        drawShip(ships[i]);
    }

    printf("   1 2 3 4 5 6 7 8 9\n");
    printf("   ------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);

        for (int j = 0; j < SIZE; j++) {
            printf("%c ", array1[i][j]);
        }
        printf("|\n");
    }

    return 0;
}