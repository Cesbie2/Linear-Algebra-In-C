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
        ret[i] = (float*)malloc(nCols * sizeof(float));   
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