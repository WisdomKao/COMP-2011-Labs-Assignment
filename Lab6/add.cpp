#include "lab6_functions.h" // Include the declearation of the function

// Task 2: Implement the Matrix Addition.
// Note: maxtrixC is used for storing the result.
// Note: You need to intialize the matrixC to all zeros before adding matrixA and matrixB !!
// Note: row is the number of rows of matrixA, and col is the number of columns of matrixA.
// Note: You can assume that the shape of matrixA is equal to the shape of the matrixB
void add(const int matrixA[][MAX_DIMENSION], const int matrixB[][MAX_DIMENSION], 
              int matrixC[][MAX_DIMENSION], const int& row, const int& col) {
    /***************Start your code here***************/
    for (int r = 0; r < MAX_DIMENSION; r++)
    {
        for (int c = 0; c < MAX_DIMENSION; c++)
        {
            matrixC[r][c] = 0;
        }
    }

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            matrixC[r][c] = matrixA[r][c] + matrixB[r][c];
        }
    }
    /***************End your code here***************/
}