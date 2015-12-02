/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
int * sortedArrayInsertNumber(int *a, int n, int num)
{
	int i = 0, j = n - 1, temp, t1;
	if (a == NULL || n<=0)
		return NULL;
	a = (int *)realloc(a, (n + 1)*sizeof(int));
	while (1)
	{
		if (a[i]>a[i + 1])
			return NULL;
		if (a[i] == num || a[j] == num)
			return NULL;
		if (a[i]<num && a[j]>num)
		{
			i++;
			j--;
		}
		else if (a[i]>num)
		{
			temp = num;
			for (; i <= n; i++)
			{
				t1 = a[i];
				a[i] = temp;
				temp = t1;
			}
			break;
		}
		else if (a[j]<num)
		{
			temp = num;
			for (j = j + 1; j <= n; j++)
			{
				t1 = a[j];
				a[j] = temp;
				temp = t1;
			}
			break;
		}
	}
	return a;
}

/*
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	return NULL;
}
*/