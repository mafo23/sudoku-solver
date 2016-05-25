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

    int baseRow = squareNum / 3 * 3;
    int baseCol = squareNum % 3 * 3;

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