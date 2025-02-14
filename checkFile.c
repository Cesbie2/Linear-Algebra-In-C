#include"linear_Algebra.h"

int main ()
{   float **matrix = mkRandMatrix(2, 2, 0, 5);
    float **matrix2 = mkRandMatrix(2, 2, 0, 5);
    
   changeMatrix(matrix, 2, 2);
   changeMatrix(matrix2, 2, 2);

    printMatrix(matrix, 2, 2);
    printMatrix(matrix2, 2, 2);

    float **product = productMatrix(matrix, matrix2, 2, 2, 2, 2);

    printMatrix(product, 2, 2);

    freeMatrix(product, 2);
    freeMatrix(matrix, 2);
    freeMatrix(matrix2, 2);
}

