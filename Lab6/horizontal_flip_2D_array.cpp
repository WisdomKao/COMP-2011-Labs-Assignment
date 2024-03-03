#include "lab6_functions.h" // Include the declearation of the function


// Task 4: Implementation of horizontally flipping 2D Array.
// Notes: matrix_f is used for storing the result.
void horizontal_flip_2D_array(const int matrix[][MAX_DIMENSION], 
                              const int& row, const int& col, 
                              int matrix_f[][MAX_DIMENSION]) {
    /***************Start your code here***************/
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            matrix_f[r][c] = matrix[r][col-c-1];
        }
    }
    /***************End your code here***************/
}