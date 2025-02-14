#ifndef linear_Algebra_h
#define linear_Algebra_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float **mkMatrix (int nRighe1, int nColonne1);
void  changeMatrix(float **matrix, int nRows, int nCols);
float **mkRandMatrix(int nRows, int nCols, int min, int MAX);
void  freeMatrix(float **matrix, int nRows);
void  printMatrix(float **matrix, int nRows, int nCols);
void  invertRows(float **matrix, int row_1, int row_2);
void  invertCols(float **matrix, int nRows, int col_1, int col_2);
float **sumMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols);
float **subMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols);

float *xtrctRow(float **matrix, int row_1, int nCols); //revisiona
float *xtractColumn(float **matrix, int column, int nRows); //revisiona

float **productMatrix(float **matrix_1, float **matrix_2, int nRows_1, int nCols_1, int nRows_2, int nCols_2); //incompleta
void  eGauss(float **matrix, int nRows); //incompleta

#endif