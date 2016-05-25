// Sudoku Guesser
//#include <stdlib.h>
#include <stdio.h>

// Determines whether the given row is a valid row (each number is unique)
// Returns 0 if invalid, and !0 if valid
int validRow(int rowNum, int sudoku[9][9]);
// Determines whether the given col is a valid col (each number is unique)
int validCol(int colNum, int sudoku[9][9]);
// Determines whether the given square is a valid square (each number is unique)
int validSquare(int squareNum, int sudoku[9][9]);

// Determines what values can be inserted into the row keeping it valid
int remainingInRow(int rowNum, int * remArray, int sudoku[9][9]);
// Determines what values can be inserted into the col keeping it valid
int remainingInCol(int colNum, int * remArray, int sudoku[9][9]);
// Determines what values can be inserted into the square keeping it valid
int remainingInSquare(int squareNum, int * remArray, int sudoku[9][9]);

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

    return 0;
}

int validRow(int rowNum, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; ++i) {
        if (sudoku[rowNum][i]) {
            if (found[sudoku[rowNum][i] - 1]) {
                return 0;
            } else {
                found[sudoku[rowNum][i] - 1] = 1;
            }
        }
    }

    return 1;
}

int validCol(int colNum, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; ++i) {
        if (sudoku[i][colNum]) {
            if (found[sudoku[i][colNum] - 1]) {
                return 0;
            } else {
                found[sudoku[i][colNum] - 1] = 1;
            }
        }
    }

    return 1;
}

int validSquare(int squareNum, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int baseX = squareNum % 3 * 3;
    int baseY = squareNum / 3 * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[baseX + i][baseY + j]) {
                if (found[sudoku[baseX + i][baseY + j]-1]) {
                    return 0;
                } else {
                    found[sudoku[baseX+i][baseY+j] - 1] = 1;
                }
            }
        }
    }
    return 1;
}