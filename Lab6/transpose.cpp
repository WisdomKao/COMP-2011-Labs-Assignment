#include "lab6_functions.h" // Include the declearation of the function


// Task 1: Implement the Matrix Transpose.
void transpose(const int matrix[][MAX_DIMENSION], const int& row,
               const int& col, int matrix_t[][MAX_DIMENSION]) {
  /***************Start your code here***************/
  for (int r = 0; r < row; r++)
  {
    for (int c = 0; c < col; c++)
    {
        matrix_t[c][r] = matrix[r][c];
    }
  }
  /***************End your code here***************/
}