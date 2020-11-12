#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

struct Doubly {
	int data;
	struct Doubly* prev;
	struct Doubly* next;
};
typedef struct Doubly doubly;

doubly* reverse_doubly(doubly* p) {
	if ( p == NULL || p->next == NULL)
		return p;
	doubly* q = p;
	while (q) {
		if (q->next == NULL)
			p = q;
		doubly* tmp = q->next;
		q->next = q->prev;
		q->prev = tmp;
		q = q->prev;
	}
	return p;
}

node* reverse(node* q) {
	node* p, * r;
	if (q == NULL || q->next == NULL)
		return q;
	else {
		p = NULL;
		r = q->next;
		while (r) {
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		return q;
	}
}
