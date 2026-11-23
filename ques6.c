#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1 || numRows >= n) {
        char* copy = (char*)malloc((n + 1) * sizeof(char));
        strcpy(copy, s);
        return copy;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int index = 0;
    int cycleLen = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < n; j += cycleLen) {
            result[index++] = s[j];

            int diagonalIdx = j + cycleLen - 2 * row;
            if (row != 0 && row != numRows - 1 && diagonalIdx < n) {
                result[index++] = s[diagonalIdx];
            }
        }
    }

    result[index] = '\0';
    return result;
}
