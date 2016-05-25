// Determines what values can be inserted into the row keeping it valid
void remainingInRow(int rowNum, int * remArray, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; ++i) {
        if (sudoku[rowNum][i]) {
            found[sudoku[rowNum][i] - 1] = 1;
        }
    }

    int index = 0;
    for (int i = 0; i < 9; ++i) {
        if (!found[i]) {
            remArray[index] = i + 1;
            ++index;
        }
    }
}

// Determines what values can be inserted into the col keeping it valid
void remainingInCol(int colNum, int * remArray, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; ++i) {
        if (sudoku[i][colNum]) {
            found[sudoku[i][colNum] - 1] = 1;
        }
    }

    int index = 0;
    for (int i = 0; i < 9; ++i) {
        if (!found[i]) {
            remArray[index] = i + 1;
            ++index;
        }
    }
}

// Determines what values can be inserted into the square keeping it valid
void remainingInSquare(int squareNum, int * remArray, int sudoku[9][9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int baseRow = squareNum / 3 * 3;
    int baseCol = squareNum % 3 * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[baseRow + i][baseCol + j]) {
                found[sudoku[baseRow+i][baseCol + j] - 1] = 1;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < 9; ++i) {
        if (!found[i]) {
            remArray[index] = i + 1;
            ++index;
        }
    }
}