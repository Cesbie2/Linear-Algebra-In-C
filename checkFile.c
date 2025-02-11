#include"linear_Algebra.h"

int main ()
{   float **matrix = mkRandMatrix(4, 4, 10, 20);
    float **matrix2 = mkRandMatrix(4, 4, 20, 30);
    
    printMatrix(matrix, 4, 4);
    printMatrix(matrix2, 4, 4);
    
    sumMatrices(matrix, matrix, 4, 4);

    printMatrix(matrix, 4, 4);
    printMatrix(matrix2, 4, 4);
    freeMatrix(matrix, 4);
    freeMatrix(matrix2, 4);
}