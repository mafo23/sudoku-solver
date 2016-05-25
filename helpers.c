// This finds all common values that are valid in the grid tile's square, column and row
void intersectionValidValues(int * remArray, int * rowValues, int * colValues, int * squareValues) {
    int intersectRowCol[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < 9 && j < 9) {
        if (rowValues[i] == -1) break;
        if (colValues[j] == -1) break;
        if (rowValues[i] < colValues[j]) {
            ++i;
        } else if (rowValues[i] > colValues[j]) {
            ++j;
        } else {
            intersectRowCol[k] = rowValues[i];
            ++i;
            ++j;
            ++k;
        }
    }
    i = 0;
    j = 0;
    k = 0;
    while(i < 9 && j < 9) {
        if (intersectRowCol[i] == -1) break;
        if (squareValues[j] == -1) break;
        if (intersectRowCol[i] < squareValues[j]) {
            ++i;
        } else if (intersectRowCol[i] > squareValues[j]) {
            ++j;
        } else {
            remArray[k] = intersectRowCol[i];
            ++i;
            ++j;
            ++k;
        }
    }
}