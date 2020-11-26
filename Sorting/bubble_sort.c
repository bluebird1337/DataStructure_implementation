#pragma warning(disable:4996)
#include<stdio.h>

void swap(int* a, int* b);

void bubble_sort(int* a, int size) {
	int flag;

	for (int i = 0; i < size - 1; i++) {
		flag = 0;
		for (int j = 0; j < size - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag++;
			}
		}
		if (flag == 0)
			break;
	}
}