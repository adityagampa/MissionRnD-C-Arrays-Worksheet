/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void sort(struct student *students, int len)
{
	int i, j;
	struct student temp;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - i - 1; ++j)
		{
			if (students[j].score < students[j + 1].score)
			{
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
}

struct student ** topKStudents(struct student *students, int len, int k)
{
	struct student **a;
	int i, j = 0;
	if (k <= 0)
		return NULL;
	a = (struct student **)malloc(k*sizeof(struct student));
	sort(students, len);
	if (k > len)
		k = len;
	for (i = 0; i<k; i++)
	{
		a[i] = &students[i];
	}
	return a;
}
