#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

int binary_search(array a, int target);
void Display(array arr);
void Append(array* arr, int x);
void Insert(array* arr, int index, int x);
int delete(array* a, int index);
void swap(int* a, int* b);
void reverse(array* a);
void reverse2(array* a);
array merge(array a, array b);

int main()
{
	array arr1 = { {2, 4, 6, 8, 10},10 ,5 };
	array arr2 = { {1, 3, 5, 7, 9},10 ,5 };
	array arr3 = merge(arr1, arr2);
	Display(arr3);
	return 0;
}