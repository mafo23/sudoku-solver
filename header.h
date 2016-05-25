// Determines whether the given row is a valid row (each number is unique)
// Returns 0 if invalid, and !0 if valid
int validRow(int rowNum, int sudoku[9][9]);
// Determines whether the given col is a valid col (each number is unique)
int validCol(int colNum, int sudoku[9][9]);
// Determines whether the given square is a valid square (each number is unique)
int validSquare(int squareNum, int sudoku[9][9]);

// Determines what values can be inserted into the row keeping it valid
void remainingInRow(int rowNum, int * remArray, int sudoku[9][9]);
// Determines what values can be inserted into the col keeping it valid
void remainingInCol(int colNum, int * remArray, int sudoku[9][9]);
// Determines what values can be inserted into the square keeping it valid
void remainingInSquare(int squareNum, int * remArray, int sudoku[9][9]);

// This finds all common values that are valid in the grid tile's square, column and row
void intersectionValidValues(int * remArray, int * rowValues, int * colValues, int * squareValues);
