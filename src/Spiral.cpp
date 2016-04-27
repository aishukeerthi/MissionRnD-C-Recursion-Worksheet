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
#include<stdlib.h>
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;

	int n = rows*columns;
	int *res = (int *)malloc(n*sizeof(int));
	int i, k = 0, r1 = 0, r2 = rows, c1 = 0, c2 = columns;

	while (r1 < r2 && c1 < c2)
	{
		for (i = c1; i < c2; i++)
		{
			res[k++] = input_array[r1][i];
		}
		r1++;
		for (i = r1; i < r2; i++)
		{
			res[k++] = input_array[i][c2 - 1];
		}
		c2--;
		if (r1 < r2)
		{
			for (i = c2 - 1; i >= c1; i--)
			{
				res[k++] = input_array[r2 - 1][i];
			}
			r2--;
		}
		if (c1 < c2)
		{
			for (i = r2 - 1; i >= r1; i--)
			{
				res[k++] = input_array[i][c1];
			}
			c1++;
		}
	}
	return res;
}