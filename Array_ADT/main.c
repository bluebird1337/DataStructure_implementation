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
int delete(array* a, int index) {
	if (index >= 0 && index < a->length) {
		int temp = a->A[index];
		for (int i = index; i < a->length-1; i++)
			a->A[i] = a->A[i + 1];
		a->length--;
		return temp;
	}
}
int binary_search(array a, int target) {
	int l = 0, h = a.length - 1, mid;
	while (l <= h) {
		mid = l-(l-h)/ 2;
		if (a.A[mid] > target)
			h = mid - 1;
		else if (a.A[mid] < target)
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	array arr1 = { {2,3,4,5,6},10,5 };
	array arr2 = { {2,3,9,16,18,21,28,32,35},10,9 };
	Display(arr2);
	int s = binary_search(arr2, 21);
	printf("%d", s);
	return 0;
}