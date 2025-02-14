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
{   
    float *ptrTEMP = NULL;
    
    ptrTEMP = matrix[row_1];
    matrix[row_1] = matrix[row_2];
    matrix[row_2] = ptrTEMP;
}

//invert the columns specified into the function 
void invertCols(float **matrix, int nRows, int col_1, int col_2)
{    
    for(int i = 0; i < nRows; i++)
    {   float temp = 0; 
        temp = matrix[i][col_1];
        matrix[i][col_1] = matrix[i][col_2];
        matrix[i][col_2] = temp;
    }
}

//sum of 2 matricles
float **sumMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols)
{   float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   ret[i][j] = matrix_1[i][j] + matrix_2[i][j];     
        }
    }

    return ret;
}

//subtraction of 2 matricles
float **subMatrices(float **matrix_1, float **matrix_2, int nRows, int nCols)
{   float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   ret[i][j] = matrix_1[i][j] - matrix_2[i][j];     
        }
    }

    return ret;
}

//extract and place the row inside an array (remember to free the array)
float *xtrctRow(float **matrix, int row_1, int nCols)
{   float *ret = (float*)malloc(nCols * sizeof(float));
    //check the allocated memory
    if(ret == NULL)
    {   printf("%s", "Error: Memory allocation fault for extract rows");
        return NULL;   
    }
    
    for(int i = 0; i < nCols; i++)
    {   ret[i] = matrix[row_1][i];
    }
    return ret;
}

//extract and place the column inside an array (remember to free the array)
float *xtractColumn(float **matrix, int column, int nRows)
{    float *ret = (float*)malloc(nRows * sizeof(float));
    //check the allocated memory
    if(ret == NULL)
    {   printf("%s", "Error: Memory allocation fault for extract column");
        return NULL;   
    }
    
    for(int i = 0; i < nRows; i++)
    {   ret[i] = matrix[i][column];
    }
    return ret;
}

float **productScalar(float **matrix, int nRows, int nCols, float scalar)
{   float **ret = mkMatrix(nRows, nCols);
    
    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {   
            ret[i][j] = matrix[i][j] * scalar;
        }
    }
    
    return ret;
}

//matrix product row * column REMINDER: can be done only if nCols_1 == nRows_2
float **productMatrix(float **matrix_1, float **matrix_2, int nRows_1, int nCols_1, int nRows_2, int nCols_2)
{   
    if(nCols_1 != nRows_2)
    {   puts("You can't do the matrix product if nCols_1 and nRows_2 are different");
        return NULL;
    }
    
    float **ret = mkMatrix(nRows_1, nCols_2);
    
    for(int i = 0; i < nRows_1; i++)
    {   for(int j = 0; j < nCols_2; j++)
        {   
            for(int k = 0; k < nCols_1; k++)
            {   
                ret[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    return ret;
}


//incomplete
/*void eGauss(float **matrix, int nRows, int nCols)
{   while(matrix[0][0] == 0)
    {   for(int i = 1; i < nRows; i++)
        {   invertRows(matrix, 0, i);
        }
    }

    if(nRows == nCols)
    {   puts("La matrice è quadrata");
    }

    for(int i = 0; i < nRows; i++)
    {   for(int j = 0; j < nCols; j++)
        {
        }
    }
}
*/