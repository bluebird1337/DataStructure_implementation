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
array* intersection(array a, array b);
array* difference(array a, array b);


int main()
{
	int a;
	scanf(%d, &a);
	printf("%d", a);
	return 0;
}