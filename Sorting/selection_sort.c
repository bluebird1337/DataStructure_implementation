#pragma warning(disable:4996)
#include<stdio.h>

void swap(int* a, int* b);

void selection_sort(int* a, int n) {
	int j, k;
	for (int i = 0; i < n - 1; i++) {
		for (j = k = i; j < n; j++) {
			if (a[j] < a[k])
				k = j;
		}
		swap(&a[i], &a[k]);
	}
}