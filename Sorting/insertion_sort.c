#pragma warning(disable:4996)
#include<stdio.h>

void insertion_sort(int* a, int size) {
	int i, j, x;
	for (i = 1; i < size; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}