#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_ROWS 7
#define MAX_COLUMNS 7

#define BORDER_TOP_LEFT     201 // ╔
#define BORDER_HORIZONTAL   205 // ═
#define BORDER_TOP_RIGHT    187 // ╗
#define BORDER_VERTICAL     186 // ║
#define BORDER_BOTTOM_LEFT  200 // ╚
#define BORDER_BOTTOM_RIGHT 188 // ╝

#define BLOCK               254 // ■
#define DOT                 250 // ·

typedef int MAT[MAX_ROWS][MAX_COLUMNS];

typedef struct tacka {
    int x;
    int y;
} TACKA;


void promeni(int* k) {
    if (*k) 
        (*k) = 0;
    else 
        (*k) = 1;
}

void ispisi_matricu(MAT mat, TACKA point, TACKA* points, int n, int* k) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            mat[i][j] = 0;
        }
    }

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            if (*k) {
                mat[points[i].y][points[i].x] = 2;
                promeni(k);
            }
            else {
                mat[points[i].y][points[i].x] = 3;
                promeni(k);
            }
        }
    }
    mat[point.y][point.x] = 1;

    printf("%c", BORDER_TOP_LEFT);
    for (int i = 0; i < MAX_COLUMNS + MAX_COLUMNS - 1; i++)
        printf("%c", BORDER_HORIZONTAL);
    printf("%c\n", BORDER_TOP_RIGHT);

    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%c", BORDER_VERTICAL); 
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (j != MAX_COLUMNS - 1) {
                switch (mat[i][j]) {
                case 0: {
                    printf("%c ", DOT);
                    break;
                }
                case 1: {
                    printf("%c ", BLOCK);
                    break;
                }
                case 2: {
                    printf("X ");
                    break;
                }
                case 3: {
                    printf("O ");
                    break;
                }
                }
            }
            else {
                switch (mat[i][j]) {
                case 0: {
                    printf("%c", DOT);
                    break;
                }
                case 1: {
                    printf("%c", BLOCK);
                    break;
                }
                case 2: {
                    printf("X");
                    break;
                }
                case 3: {
                    printf("O");
                    break;
                }
                }
            }
        }
        printf("%c\n", BORDER_VERTICAL); 
    }

    printf("%c", BORDER_BOTTOM_LEFT);
    for (int i = 0; i < MAX_COLUMNS + MAX_COLUMNS - 1; i++)
        printf("%c", BORDER_HORIZONTAL);
    printf("%c\n", BORDER_BOTTOM_RIGHT);
}



int main(void) {
    int k = 0;
    MAT matrica = { 0 };
    TACKA point = { 0, 0 };
    TACKA tacke[100];
    int n = 0;
    char c;

    ispisi_matricu(matrica, point, tacke, n, &k);

    while ((c = _getch()) != 'p') {
        system("cls");

        switch (c) {
        case 'w':
            if (point.y > 0) point.y -= 1;
            break;
        case 'a':
            if (point.x > 0) point.x -= 1;
            break;
        case 's':
            if (point.y < MAX_ROWS - 1) point.y += 1;
            break;
        case 'd':
            if (point.x < MAX_COLUMNS - 1) point.x += 1;
            break;
        case 13:
            tacke[n].y = point.y;
            tacke[n++].x = point.x;
            break;
        }

        ispisi_matricu(matrica, point, tacke, n, &k);
        k = 0;
        printf("%d %d\n", point.x, point.y);
    }

    return 0;
}
