#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;


void reverse(array* a) {
	int* b = (int*)malloc(sizeof(int) * a->length);
	for (int i = a->length - 1, j = 0; i >= 0; i--, j++)
		b[j] = a->A[i];
	for (int i = 0; i < a->length; i++)
		a->A[i] = b[i];

}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse2(array* a) {
	for (int i = 0, j = a->length - 1; i < j; i++, j--)
		swap(&a->A[i], &a->A[j]);
}