#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

void Display(array arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
}
void Append(array* arr, int x)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}
void Insert(array* arr, int index, int x)
{
	int i;

	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}
int delete(array* a, int index)
{
	if (index >= 0 && index < a->length) {
		int temp = a->A[index];
		for (int i = index; i < a->length - 1; i++)
			a->A[i] = a->A[i + 1];
		a->length--;
		return temp;
	}
	else return -1;
}