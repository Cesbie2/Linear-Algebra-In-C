#include"linear_Algebra.h"

int main ()
{   float **matrix = mkMatrix(4, 2);
    float **matrix2 = mkMatrix(2, 4);
    
    changeMatrix(matrix, 4, 2);
    changeMatrix(matrix2, 2, 4);

    printMatrix(matrix, 4, 2);
    printMatrix(matrix2, 2, 4);

    float **product = productMatrix(matrix, matrix2, 4, 2, 2, 4);

    printMatrix(product, 4, 4);

    freeMatrix(product, 4);
    freeMatrix(matrix, 4);
    freeMatrix(matrix2, 2);
}