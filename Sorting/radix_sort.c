#pragma warning(disable:4996)
#include<stdlib.h>
#include<math.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node node;
int find_max(int* a, int n);

int delete_from_stack(node**ptr, int index) {
	node* p = ptr[index];
	ptr[index] = ptr[index]->next;
	int value = p->data;
	free(p);
	return value;
}

void insert_stack(node**ptr, int x, int index) {
	node* p = (node*)malloc(sizeof(node));
	p->data = x;
	p->next = NULL;

	if (ptr[index] == NULL) {
		ptr[index] = p;
	}
	else {
		node* t = ptr[index];
		while (t->next!=NULL) {
			t = t->next;
		}
		t->next = p;
	}
}

int getBinIndex(int x, int idx) {
	return (int)(x / pow(10, idx)) % 10;
}

void radix_sort(int* a, int n) {
	node** bin;
	bin = (node**)malloc(sizeof(node*) * 10);
	for (int i = 0; i < 10; i++)
		bin[i] = NULL;

	int max = find_max(a, n);
	int count = 0;
	while (max !=0) {
		count++;
		max = max / 10;
	}

	for (int i = 0; i < count; i++) {
		//insert
		for (int j = 0; j < n; j++) {
			int digit = getBinIndex(a[j], i);
			insert_stack(bin, a[j], digit);
		}
		//delete
		int x = 0, y=0;
		while (x < 10) {
			while (bin[x] != NULL) {
				a[y++] = delete_from_stack(bin, x);
			}
			x++;
		}

	}
	free(bin);
}