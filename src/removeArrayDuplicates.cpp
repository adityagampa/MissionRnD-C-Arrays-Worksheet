/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>


void * removeArrayDuplicates(int *a, int len)
{
	int k = 0;
	int i = 0, j = 0;
	if (len <= 1)
		return NULL;
	if (a == NULL)
		return NULL;
	else
	{
		for (; i<len; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (a[j] == a[i])
					break;
			}
			if (j == -1)
				a[k++] = a[i];
		}
	}
	return a;
}
