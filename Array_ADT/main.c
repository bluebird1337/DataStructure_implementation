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


int main()
{
	array arr1 = { {2,3,4,5,6},10,5 };
	array arr2 = { {2,3,9,16,18,21,28,32,35},10,9 };
	Display(arr1);
	reverse2(&arr1);
	Display(arr1);
	return 0;
}