#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

array merge(array a, array b)
{
	array c;
	int i, j, k;
	for (i = 0, j = 0, k = 0; i < a.length && j < b.length;) {
		if (a.A[i] > b.A[j])
			c.A[k++] = b.A[j++];
		else if (a.A[i] < b.A[j])
			c.A[k++] = a.A[i++];
		else {
			c.A[k++] = a.A[i++];
			j++;
		}
	}

	for (; i < a.length; i++)
		c.A[k++] = a.A[i];
	for (; j < b.length; j++)
		c.A[k++] = b.A[j];
	c.length = k;
	c.size = 20;
	return c;
}