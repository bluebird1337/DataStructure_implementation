#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int find_max(int* a, int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (max < a[i])
			max = a[i];
	}
	return max;
}

void count_sort(int* a, int n) {
	int* c;
	int max = find_max(a, n);
	c = (int*)malloc(sizeof(int) * (max + 1));
	for (int i = 0; i < max + 1; i++)
		c[i] = 0;

	for (int i = 0; i < n; i++)
		c[a[i]]++;
	int i = 0, j = 0;
	while (i < max + 1) {
		if (c[i] > 0) {
			a[j++] = i;
			c[i]--;
		}
		else
			i++;
	}
}