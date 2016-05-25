#include "header.h"

// Backtrack function, will return a 0 if the insert failed or a non zero if it was successful
int backtrack(int row, int col, int sudoku[9][9]) {
    // If the tile already has a value, move to the next one
    if (sudoku[row][col] != 0) {
        if (col == 8) {
            if (row == 8) {
                return 1;
            } else {
                return backtrack(row + 1, 0, sudoku);
            }
        } else {
            return backtrack(row, col + 1, sudoku);
        }
    } else {
        // This logic is werid. Look to bottom of this c file for full explination.
        int square = (row / 3) * 3 + col / 3;
        int rowRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        int colRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        int squareRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        int commonRem[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

        remainingInRow(row, rowRem, sudoku);
        remainingInCol(col, colRem, sudoku);
        remainingInSquare(square, squareRem, sudoku);
        intersectionValidValues(commonRem, rowRem, colRem, squareRem);

        //CBF using memcpy
        int sudokuCopy[9][9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                sudokuCopy[i][j] = sudoku[i][j];
            }
        }

        // No Possible Values, return 0
        if (commonRem[0] == -1) {
            return 0;
        } else {
            for (int i = 0; i < 9; ++i) {
                if(commonRem[i] == -1) {
                    return 0;
                }
                sudokuCopy[row][col] = commonRem[i];
                if (col == 8) {
                    if (row == 8) {
                        return 1;
                    } else {
                        if (backtrack(row + 1, 0, sudokuCopy)) {
                            for (int i = 0; i < 9; ++i) {
                                for (int j = 0; j < 9; ++j) {
                                    sudoku[i][j] = sudokuCopy[i][j];
                                }
                            }
                            return 1;
                        }
                    }
                } else {
                    if (backtrack(row, col + 1, sudokuCopy)) {
                        for (int i = 0; i < 9; ++i) {
                            for (int j = 0; j < 9; ++j) {
                                sudoku[i][j] = sudokuCopy[i][j];
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
/*
==========Explination for square Generation==========
ok. so squares are arranged in the following order
0 1 2
3 4 5
6 7 8

From this, we can see that:
square 0 is made up of  (0,0) (0,1) (0,2)
                        (1,0) (1,1) (1,2)
                        (2,0) (2,1) (2,2)

square 1 is made up of  (0,3) (0,4) (0,5)
                        (1,3) (1,4) (1,5)
                        (2,3) (2,4) (2,5)

square 2 is made up of  (0,6) (0,7) (0,8)
                        (1,6) (1,7) (1,8)
                        (2,6) (2,7) (2,8)

square 3 is made up of  (3,0) (3,1) (3,2)
                        (4,0) (4,1) (4,2)
                        (5,0) (5,1) (5,2)

square 4 is made up of  (3,3) (3,4) (3,5)
                        (4,3) (4,4) (4,5)
                        (5,3) (5,4) (5,5)

square 5 is made up of  (3,6) (3,7) (3,8)
                        (4,6) (4,7) (4,8)
                        (5,6) (5,7) (5,8)

square 6 is made up of  (6,0) (6,1) (6,2)
                        (7,0) (7,1) (7,2)
                        (8,0) (8,1) (8,2)

square 7 is made up of  (6,3) (6,4) (6,5)
                        (7,3) (7,4) (7,5)
                        (8,3) (8,4) (8,5)

square 8 is made up of  (6,6) (6,7) (6,8)
                        (7,6) (7,7) (7,8)
                        (8,6) (8,7) (8,8)

so to get the square that a tile is in, the first helpful thing is the row.
if row is 0, 1, 2 then square is 0-2
if row is 3, 4, 5 then square is 3-5
if row is 6, 7, 8 then square is 6-8

therefore get the base number of the square as the first of the above, ie. bases are 0, 3, 6,
and then get the correct square based on the column.

if col is 0, 1, 2 then the square is the first in that "row of squares"
if col is 3, 4, 5 then the square is the second in that "row of squares"
if col is 6, 7, 8 then the square is the third in that "row of squares"

i.e. for (0, 5).
as the row is 0, it must be in square 0, 1, 2.
as the col is 5, it must be the second square in that list.
therefore it is in square 1.

so easy way to do this is to divide the row by 3 to get the "row" for the square and then multiply by 3 to get the base square
note: C is not 100% mathematically correct due to data types, so if storing in an int: (5/3) * 3 = 3 not 5 as (5/3) evaluates to 1

then once you have the base, just divide the column by 3 and add that to the base to get the square num.

i.e.
base = row/3 * 3;
square = base + col/3;

or

square = row/3 * 3 + col/3;
*/