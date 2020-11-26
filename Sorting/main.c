#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node {
	int data;
	struct node* next;
};
typedef struct node node;
//sorting function
void bubble_sort(int* a, int size);
void insertion_sort(int* a, int size);
void selection_sort(int* a, int n);
int partision(int* a, int l, int h);
void quick_sort(int* a, int l, int h);
int find_max(int* a, int n);
void count_sort(int* a, int n);
void merge(int* a, int l, int m, int h);
void merge_sort(int* a, int n);
void Rmerge_sort(int* a, int l, int h); 
int delete_from_stack(node** ptr, int index);
void insert_stack(node** ptr, int x, int index);
int getBinIndex(int x, int idx);
void radix_sort(int* a, int n);
void shell_sort(int* a, int n);
//main
void display(int* a, int size) {
	for (int i= 0; i < size; i++)
		printf("%d ", a[i]);
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int data[] = { 237, 146, 259, 348, 152, 163, 235, 48, 36, 62 };
	shell_sort(data, 10);
	display(data, 10);
	return 0;
}