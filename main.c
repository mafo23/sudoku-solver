// Sudoku Guesser
//#include <stdlib.h>
#include <stdio.h>
#include "header.h"

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

    printf("==========INPUT==========\n");
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

    int sudokuCopy[9][9];
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudokuCopy[i][j] = sudoku[i][j];
        }
    }
    printf("==========OUTPUT==========\n");
    int success = backtrack(0, 0, sudokuCopy);
    if (success) {
        for (int i = 0; i < 9; ++i) {
            if (i%3 == 0) {
                printf("-------------------\n");
            }
            for (int j = 0; j < 9; ++j) {
                if (j%3 == 0) printf("|");
                if (sudokuCopy[i][j] == 0) {
                    printf("?");
                } else {
                    printf("%d", sudokuCopy[i][j]);
                }
                if (j%3 != 2) printf(" ");
                if (j == 8) printf("|");
            }
            printf("\n");
        }
        printf("-------------------\n");
    }

    return 0;
}
