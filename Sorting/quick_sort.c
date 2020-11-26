#pragma warning(disable:4996)
#include<stdio.h>

void swap(int*, int*);

int partision(int* a, int l, int h) {
	int pivot = a[l];
	int i, j;
	i = l, j = h;
	do {
		do { i++; } while (a[i] <= pivot);
		do { j--; } while (a[j] > pivot);
		if (i < j)
			swap(&a[i], &a[j]);
	} while (i < j);
	swap(&a[l], &a[j]);
	return j;
}

void quick_sort(int* a, int l, int h) {
	if (l < h) {
		int position = partision(a, l, h);
		quick_sort(a, l, position);
		quick_sort(a, position + 1, h);
	}
	return;
}