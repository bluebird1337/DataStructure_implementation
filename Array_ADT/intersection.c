#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

array* intersection(array a, array b)
{
	int i, j, k=0;
	array* c = (array*)malloc(sizeof(array));
	for (i = 0, j = 0; i < a.length && j < b.length;) {
		if (a.A[i] > b.A[j])
			j++;
		else if (a.A[i] < b.A[j])
			i++;
		else
		{
			c->A[k++] = a.A[i];
			i++;
			j++;
		}
	}
	c->length = k;
	c->size = a.size + b.size;
	return c;
}