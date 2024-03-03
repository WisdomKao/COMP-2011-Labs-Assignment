#include "lab6_functions.h" // Include the declearation of the function

// Task 3: Implement the Matrix Multiplication.
// Note: maxtrixC is used for storing the result.
// Note: You need to intialize the matrixC to all zeros before mutiplying matrixA and matrixB.
// Note: rowA is the number of rows of matrixA, and colA is the number of columns of matrixA.
// Note: colB is the number of columns of matrixB.
// Note: You can assume that the number of columns of matrixA is equal to the number of rows of matrixB
void multiply(const int matrixA[][MAX_DIMENSION], const int matrixB[][MAX_DIMENSION], 
              int matrixC[][MAX_DIMENSION], const int& rowA, const int& colA, 
              const int& colB) {
    /***************Start your code here**************/
    for (int r = 0; r < MAX_DIMENSION; r++)
    {
        for (int c = 0; c < MAX_DIMENSION; c++)
        {
            matrixC[r][c] = 0;
        }
    }

    for (int cB = 0; cB < colB; cB++) {
        for (int rA = 0; rA < rowA; rA++) {
            int tem = 0;
            for (int cA = 0; cA < colA; cA++) {
                tem += matrixB[cA][cB] * matrixA[rA][cA];
            }
            matrixC[rA][cB] = tem;
        }
    }
    
    /**************End your code here***************/
}