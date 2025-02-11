#ifndef linear_Algebra_h
#define linear_Algebra_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float **mkMatrix (int nRighe1, int nColonne1);
void changeMatrix(float **matrix, int nRows, int nCols);
float **mkRandMatrix(int nRows, int nCols, int min, int MAX);
void freeMatrix(float **matrix, int nRows);
void printMatrix(float **matrix, int nRows, int nCols);

#endif