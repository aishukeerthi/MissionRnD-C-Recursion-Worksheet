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
void spiral_helper(int rows, int columns, int **input_array, int *output, int start_pos)
{
	static int output_pos = 0;
	if (rows <= 0 || columns <= 0)
		return;

	//Go right
	int i = start_pos, j;
	for (j = 0; j<columns; j++)
	{
		output[output_pos++] = input_array[i][j + start_pos];
		//printf("%d\n", output[output_pos - 1]);
	}
	j--;	//going back one row
	//printf("value of i:%d, j:%d\n", i, j);
	//Go down
	for (i = 1; i<rows; i++)
	{
		output[output_pos++] = input_array[i + start_pos][j + start_pos];
		//printf("%d\n", output[output_pos - 1]);
	}
	i--;	//going back one row
	//printf("value of i:%d, j:%d\n", i, j);

	//Go Left
	for (j = j - 1; j >= 0; j--)
	{
		output[output_pos++] = input_array[i + start_pos][j + start_pos];
		//printf("%d\n", output[output_pos - 1]);
	}
	j++;
	//printf("value of i:%d, j:%d\n", i, j);

	//Go Up and dont print the first element
	for (i = i - 1; i>0; i--)
	{
		output[output_pos++] = input_array[i + start_pos][j + start_pos];
		//printf("%d\n", output[output_pos - 1]);
	}
//	printf("value of i:%d, j:%d\n", i, j);

	spiral_helper(rows - 2, columns - 2, input_array, output, start_pos + 1);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || !input_array)
		return NULL;
	int *output = (int *)malloc(sizeof(int)*rows*columns);
	spiral_helper(rows, columns, input_array, output, 0);
	return output;
}

