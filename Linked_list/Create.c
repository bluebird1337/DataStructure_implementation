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

doubly* create_doubly(int*a , int n, doubly* p) {
	p->prev = NULL;
	p->next = NULL;
	p->data = a[0];
	doubly* last;
	last = p;
	
	for (int i = 1; i < n; i++) {	
		doubly* tmp;
		tmp = (doubly*)malloc(sizeof(doubly));
		tmp->data = a[i];
		tmp->prev = last;
		last->next = tmp;
		tmp->next = NULL;
		last = tmp;
	}
	
	return p;
}

node* create_circular(int* a, int n, node* p) {
	node* t, * last;
	p = (node*)malloc(sizeof(node));
	if (p) {
		p->data = a[0];
		p->next = NULL;
	}
	last = p;

	for (int i = 1; i < n; i++) {
		t = (node*)malloc(sizeof(node));
		if (t) {
			t->data = a[i];
			t->next = NULL;
		}
		if (last) {
			last->next = t;
			last = t;
		}
	}
	if(last)
		last->next = p;
	return p;
}

node* create(int* a, int n, node* p)
{
	node* t, * last = NULL;
	p = (node*)malloc(sizeof(node));
	if (p) {
		p->data = a[0];
		p->next = NULL;
		last = p;
	}


	for (int i = 1; i < n; i++) {
		t = (node*)malloc(sizeof(node));
		if (t) {
			t->data = a[i];
			t->next = NULL;
			if (last) {
				last->next = t;
				last = t;
			}
		}
	}
	return p;
}