#include"linear_Algebra.h"

int main ()
{   float **matrix = mkRandMatrix(4, 2, 10, 20);
    printMatrix(matrix, 4, 2);
    freeMatrix(matrix, 4);
}