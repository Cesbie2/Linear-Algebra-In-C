#include "linear_Algebra.h"

//Create a matrix of float type initialized at 0
float **mkMatrix (int nRows, int nCols)
{   float **ret = (float**)malloc( nRows * sizeof(float*));
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

