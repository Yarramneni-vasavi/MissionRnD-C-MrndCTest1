/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr == NULL)
		return NULL;

	int *result_array = (int *)malloc(sizeof(int) * 6);
	float quo1, quo2;
	int quo1_index, quo2_index;

	quo1_index = 0; 	quo2_index = 0;
	int flag = 0;
	// to find first GP
	for (int i = 0; i < len - 1; i++)
	{
		quo1 = ((double)arr[i + 1]) / arr[i];
		quo2 = ((double)arr[i + 2]) / arr[i + 1];
		if (flag == 0)
		{
			quo1_index = i;
		}
		if (quo1 == quo2)
		{
			flag = 1;
			quo1 = quo2;
			quo2_index = i + 2;
		}
		else if (quo2_index - quo1_index >= 2)
		{
			break;
		}
		else
		{
			quo1 = quo2;
			quo2_index = i;
		}
	}

	result_array[4] = quo1_index;
	result_array[5] = quo2_index;
	//to find first AP
	int diff1, diff2, APflag = 0;
	quo1_index = 0; 	quo2_index = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		diff1 = arr[i + 1] - arr[i];
		diff2 = arr[i + 2] - arr[i + 1];
		if (APflag == 0)
		{
			quo1_index = i;
		}
		if (diff1 == diff2)
		{
			APflag = 1;
			diff1 = diff2;
			quo2_index = i + 2;
		}
		else if (quo2_index - quo1_index >= 2)
		{
			break;
		}
		else
		{
			diff1 = diff2;
			quo2_index = i;
		}
	}

	result_array[0] = quo1_index;
	result_array[1] = quo2_index;

	int trace = quo2_index;
	quo1_index = 0; 	quo2_index = 0;
	APflag = 0;
	// to find second AP
	for (int k = trace; k < len; k++)
	{
		diff1 = arr[k + 1] - arr[k];
		diff2 = arr[k + 2] - arr[k + 1];
		if (APflag == 0)
		{
			quo1_index = k;
		}
		if (diff1 == diff2)
		{
			APflag = 1;
			diff1 = diff2;
			quo2_index = k + 2;
		}
		else if (quo2_index - quo1_index >= 2)
		{
			break;
		}
		else
		{
			diff1 = diff2;
			quo2_index = k;
		}
	}

	result_array[2] = quo1_index;
	result_array[3] = quo2_index;

	return result_array;
}