#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

array* difference(array a, array b) {
	array* c = (array*)malloc(sizeof(array));
	int i, j, k;
	for (i = 0, j = 0, k = 0; i < a.length && j < b.length;) {
		if (a.A[i] > b.A[j])
			j++;
		else if (a.A[i] < b.A[j])
			c->A[k++] = a.A[i++];
		else
		{
			i++;
			j++;
		}
	}
	for (; i < a.length; i++)
		c->A[k++] = a.A[i];
	c->length = k;
	c->size = 10;
	return c;
}