#pragma warning(disable: 4996)
#pragma warning(disable:6011)
#pragma warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int col;
	int data;
	struct node* next;
};
typedef struct Node node;
int row, column;

node** create_sparse() {
	int num, d_row, d_column, data;
	printf("Enter row & column\n");
	scanf("%d%d", &row, &column);
	printf("Enter number of non-zero data\n");
	scanf("%d", &num);

	node** p;
	p = (node**)malloc(sizeof(node*) * (row + 1));
	node** last;
	last = (node**)malloc(sizeof(node*) * (row + 1));

	for (int i = 0; i <= row; i++) {
		p[i] = NULL;
		last[i] = NULL;
	}

	printf("Enter non-zero data\n");
	for (int i = 0; i < num; i++) { //one data
		scanf("%d%d%d", &d_row, &d_column, &data);
		node* tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp->col = d_column;
		tmp->data = data;
		tmp->next = NULL;

		if (p[d_row] == NULL) {//that row don't have any data
			p[d_row] = tmp;
			last[d_row] = tmp;
		}
		else {
			last[d_row]->next = tmp;
			last[d_row] = tmp;
		}
	}
	return p;
}

void display_sparse(node** p) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			if (p[i] == NULL || p[i]->col != j)
				printf("%d ", 0);
			else
				printf("%d ", p[i]->data);
		}
		printf("\n");
	}
}