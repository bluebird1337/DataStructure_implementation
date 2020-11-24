#pragma warning (disable : 4996)
#include<stdio.h>


void insert(int*a, int n) {
	int i = n;
	int x = a[i];

	while (i > 1 && a[i/2] < x) {
		a[i] = a[i/2];
		i = i / 2;
	}
	a[i] = x;
	return;
}

void create_heap(int* a, int n) {
	for (int i = 2; i < n; i++)
		insert(a, i);
}

int delete(int *a, int n) {
	int x = a[n-1];
	int del = a[1];
	a[1] = x;
	int i = 1;
	int j = i * 2;
	
	while (j < n-1) {
		if (a[j + 1] > a[j])
			j = j + 1;
		if (a[i] < a[j]) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i = j;
			j = i * 2;
		}
		else
			break;
	}
	a[n - 1] = del;
	return del;
}
	
int main() {
	int a[8] = { 0, 10, 20, 30, 25, 5, 40, 35 };
	create_heap(a, 8);
	for (int i = 1; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	printf("%d is deleted\n", delete(a, 8));
	for (int i = 1; i < 8; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}