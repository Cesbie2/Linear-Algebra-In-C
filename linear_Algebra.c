#include "linear_Algebra.h"

//Create a matrix of float type initialized at 0
float **mkMatrix (int nRows, int nCols)
{   float **ret = (float**)malloc( nRows * 8);
    
    if(ret == NULL)
    {   
        printf("%s", "Error: Memory allocation fault for rows");
        return NULL;
    }
    
    for(int i = 0; i < nRows; i++)
    {      
        ret[i] = (float*)calloc(nCols, sizeof(float));   
        
        if(ret[i] == NULL)
        {   
            for(int j = 0; j < i; j++)
            {
                free(ret[j]);
            }
            free(ret);
            
            printf("%s", "Error: Memory allocation fault for columns");
            return NULL;
        }
    }
    
    return ret;
}

//initialize a matrix or change it's values
void changeMatrix(float **matrix, int nRows, int nCols)
{   for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   printf("Value of the row[%d] column[%d]: \n", i+1, j+1);
            scanf("%f", &matrix[i][j]);  
        }
    }
}

//Create a random matrix, choose a minimum and a maximum
float **mkRandMatrix(int nRows, int nCols, int min, int MAX)
{   srand(time(NULL));
    
    float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            ret[i][j] = min + rand() % (MAX - min + 1);
        }
    }
    
    return ret;
}

//free the memory flom the heap
void freeMatrix(float **matrix, int nRows)
{   for(int i = 0; i < nRows; i++)
    {   free(matrix[i]);
    }
    free(matrix);
}

//print the matrix
void printMatrix(float **matrix, int nRows, int nCols)
{   for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   
            printf("%5.2f ", matrix[i][j]);
        }
        puts("");
    }
    puts("");
}

//invert the rows specified into the function 
void invertRows(float **matrix, int row_1, int row_2)
{   row_1--;    
    row_2--;    
        
    float *ptrTEMP = NULL;
    
    ptrTEMP = matrix[row_1];
    matrix[row_1] = matrix[row_2];
    matrix[row_2] = ptrTEMP;
}

void invertCols(float **matrix, int nRows, int col_1, int col_2)
{   col_1--;
    col_2--;
    
    for(int i = 0; i < nRows; i++)
    {   float temp = 0; 
        temp = matrix[i][col_1];
        matrix[i][col_1] = matrix[i][col_2];
        matrix[i][col_2] = temp;
    }
}

float **sumMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols)
{   float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   ret[i][j] = matrix_1[i][j] + matrix_2[i][j];     
        }
    }

    return ret;
}

float **subMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols)
{   float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   ret[i][j] = matrix_1[i][j] - matrix_2[i][j];     
        }
    }

    return ret;
}


