/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int n)
{
	int num1 = -1, num2 = -1, i = 1, flag = 0;
	if (n <= 1 || Arr == NULL)
		return NULL;

	for (i = 0; i<n - 1; i++)
	{
		if (num1 == -1)
		{
			if (Arr[i]>Arr[i + 1])
			{
				num1 = i;
				num2 = i + 1;
			}
		}
		else
		{
			if (Arr[i]>Arr[i + 1])
			{
				num2 = i + 1;
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		Arr[num1] = Arr[num1] + Arr[num2];
		Arr[num2] = Arr[num1] - Arr[num2];
		Arr[num1] = Arr[num1] - Arr[num2];
	}
	return Arr;
}
