#include<stdio.h>

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
int main()
{
	array arr1 = { {2,3,4,5,6},10,5 };
	Append(&arr1, 10);
	Insert(&arr1, 0, 12);
	Display(arr1);
	return 0;
}