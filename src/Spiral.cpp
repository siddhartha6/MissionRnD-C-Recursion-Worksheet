/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

void spiralPrint(int row_start,int rows,int col_start, int cols, int **input_array,int *result,int res_index)
{
	int index=0;
	if (row_start < rows && col_start < cols)
	{
		for (index = col_start; index < cols; index++)
		{
			result[res_index++] = input_array[row_start][index];
		}
		row_start++;

		for (index = row_start; index < rows; index++)
		    	result[res_index++] = input_array[index][cols - 1];
		cols--;

		if (row_start < rows)
		{
			for (index = cols - 1; index >= col_start; index--)
			    	result[res_index++] = input_array[rows - 1][index];
			rows--;
		}

		if (col_start < cols)
		{
			for (index = rows - 1; index >= row_start; index--)
				    result[res_index++] = input_array[index][col_start];
			col_start++;
		}
		spiralPrint(row_start, rows, col_start, cols, input_array, result, res_index);
	}
	
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
	        return NULL;
	int *res = (int *)malloc(rows*columns*sizeof(int));

	spiralPrint(0, rows, 0, columns, input_array,res,0);
	return res;
}
