// Sudoku Guesser
//#include <stdlib.h>
#include <stdio.h>
#include "header.h"

// fills every value in a size 9 array to -1;
void clearArray(int * array) {
    for (int i = 0; i < 9; ++i)
    {
        array[i] = -1;
    }
}

int main(int argc, char const *argv[]) {
    int sudoku[9][9];
    FILE *fp;

    fp = fopen(argv[1], "r");
    char c;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            c = fgetc(fp);
            if (c == ' ' || c == '\n' || c == '\t') c = fgetc(fp);
            if (c == '?') {
                 sudoku[i][j] = 0;
            } else {
                sudoku[i][j] = (int)c - 48;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (i%3 == 0) {
            printf("-------------------\n");
        }
        for (int j = 0; j < 9; ++j) {
            if (j%3 == 0) printf("|");
            if (sudoku[i][j] == 0) {
                printf("?");
            } else {
                printf("%d", sudoku[i][j]);
            }
            if (j%3 != 2) printf(" ");
            if (j == 8) printf("|");
        }
        printf("\n");
    }
    printf("-------------------\n");

    for (int i = 0; i < 9; ++i) {
        if (validRow(i, sudoku)) {
            printf("Row %d is Valid!\n", i);
        } else {
            printf("Row %d is Invalid!\n", i);
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (validCol(i, sudoku)) {
            printf("Column %d is Valid!\n", i);
        } else {
            printf("Column %d is Invalid!\n", i);
        }
    }
    for (int i = 0; i < 9; ++i) {
        if (validSquare(i, sudoku)) {
            printf("Square %d is Valid!\n", i);
        } else {
            printf("Square %d is Invalid!\n", i);
        }
    }

    printf("--------------------\n");
    printf("-------(0, 0)-------\n");
    int rowRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int colRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int squareRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int commonRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

    remainingInRow(1, rowRem, sudoku);
    remainingInCol(0, colRem, sudoku);
    remainingInSquare(0, squareRem, sudoku);
    intersectionValidValues(commonRem, rowRem, colRem, squareRem);

    for (int i = 0; i < 9; ++i) {
        if (rowRem[i] == -1) break;
        printf("%d ", rowRem[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        if (colRem[i] == -1) break;
        printf("%d ", colRem[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        if (squareRem[i] == -1) break;
        printf("%d ", squareRem[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        if (commonRem[i] == -1) break;
        printf("%d ", commonRem[i]);
    }
    printf("\n");

    return 0;
}
