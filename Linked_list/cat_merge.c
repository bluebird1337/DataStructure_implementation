#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

node* concate(node* p, node* r) {
	node* q = p;
	while (q->next){
		q = q->next;
	}
	q->next = r;
	return p;
}

node* merge(node* a, node* b) {
	node* first, * last;
	if (a->data > b->data)
	{
		last = first = b;
		b = b->next;
	}
	else {
		last = first = a;
		a = a->next;
	}

	while (a && b) {
		if (a->data > b->data)
		{
			last->next = b;
			last = b;
			b = b->next;
		}
		else {
			last->next = a;
			last = a;
			a = a->next;
		}
	}
	while (a) {
		last->next = a;
		last = a;
		a = a->next;
	}
	while (b) {
		last->next = b;
		last = b;
		b = b->next;
	}
	return first;
}
