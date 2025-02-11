#include "linear_Algebra.h"

//Create a matrix of float type initialized at 0
float **mkMatrix (int nRows, int nCols)
{   float **ret = (float**)calloc( nRows, sizeof(float*));
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

//Create a random 
float **mkRandMatrix(int nRows, int nCols, int min, int MAX)
{   srand(time(NULL));
    float **ret = mkMatrix(nRows, nCols);
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            ret[i][j] = min - rand() % (MAX - min + 1);
        }
    }
    return ret;
}

void freeMatrix(float **matrix, int nRows)
{   for(int i = 0; i < nRows; i++)
    {   free(matrix[i]);
    }
    free(matrix);
}
