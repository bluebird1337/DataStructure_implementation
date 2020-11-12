#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;


int count_circular(node* p) {
	int num = 0;
	node* head = p;
	if (p == NULL)
		return num;
	do {
		num++;
		p = p->next;
	} while (p!=head);
	return num;
}

int count(node* p) {
	int num = 0;
	while (p) {
		num++;
		p = p->next;
	}
	return num;
}
int sum(node* p) {
	int sum = 0;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int max_num(node* p) {
	int max = p->data;
	p = p->next;
	while (p) {
		max = max < p->data ? p->data : max;
		p = p->next;
	}
	return max;
}
