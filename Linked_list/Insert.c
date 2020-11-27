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

int count(node*);
node* head;
int count_circular(node* p);

doubly* insert_doubly(doubly* p, int index, int key) {
	if (p == NULL) {
		p->data = key;
		p->prev = p->next = NULL;
		return p;
	}
	if (index == 0) {
		doubly* tmp;
		tmp = (doubly*)malloc(sizeof(doubly));
		tmp->data = key;
		tmp->next = p;
		tmp->prev = NULL;
		p->prev = tmp;
		return tmp;
	}
	else {
		doubly* q = p;
		for (int i = 0; i < index - 1; i++) {
			q = q->next;
		}
		doubly* tmp;
		tmp = (doubly*)malloc(sizeof(doubly));
		tmp->data = key;
		q->next->prev = tmp;
		tmp->next = q->next;
		tmp->prev = q;
		q->next = tmp;
		return p;
	}
}


node* insert_circular(node* p, int index, int key) {
	if (index < 0)
		return NULL;
	if (index == 0) {
		node* q = p;
		for (int i = 0; i < count_circular(p) - 1; i++)
			q = q->next;
		node* tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp->data = key;
		tmp->next = p;
		q->next = tmp;
		return tmp;
	}
	else {
		node* q = p;
		for (int i = 0; i < index - 1; i++)
			q = q->next;
		node* tmp;
		tmp = (node*)malloc(sizeof(node));
		tmp->data = key;
		tmp->next = q->next;
		q->next = tmp;
		return p;
	}
}

node* insert_sorted(node* p, int key) {
	node* tmp, * r = NULL, * q = p;
	tmp = (node*)malloc(sizeof(node));
	tmp->data = key;
	tmp->next = NULL;
	if (p == NULL) {
		p = tmp;
	}
	else {
		while (q && q->data < key) {
			r = q;
			q = q->next;
		}
		if (q == p) {
			tmp->next = p;
			p = tmp;
		}
		else {
			tmp->next = r->next;
			r->next = tmp;
		}
	}
	return p;
}

node* insert(node* p, int index, int x) {
	node* q, *t;
	if (index<0 || index>count(p))
		return NULL;
	if (index == 0)
	{
		q = (node*)malloc(sizeof(node));
		if (q) {
			q->data = x;
			q->next = p;
			p = q;
		}
	}
	else {
		q = p;
		for (int i = 0; i < index - 1; i++) {
			q = q->next;
		}
		t = (node*)malloc(sizeof(node));
		if (t) {
			t->data = x;
			t->next = q->next;
			q->next = t;
		}
	}
	return p;
}