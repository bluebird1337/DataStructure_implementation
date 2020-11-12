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

int count(node* p);
int count_circular(node* p);

doubly* delete_doubly(doubly* p, int index) {
	if (index < 1)
		return NULL;
	if (index == 1) {
		doubly* q = p;
		p = p->next;
		free(q);
		return p;
	}
	else {
		doubly* q = p;
		doubly* r = p->next;
		for (int i = 0; i < index - 2; i++) {
			q = q->next;
			r = r->next;
		}
		q->next = r->next;
		if(r->next)
			r->next->prev = q;
		free(r);
		return p;
	}
}

node* delete_circular(node* p, int index) {
	if (p == NULL || index <=0)
		return NULL;
	if (index == 1) {
		node* q = p;
		for (int i = 0; i < count_circular(p) - 1; i++) {
			q = q->next;
		}
		q->next = p->next;
		free(p);
		return q->next;
	}
	else {
		node* first = p;
		node* q = p;
		p = p->next;
		for (int i = 0; i < index - 2; i++) {
			q = q->next;
			p = p->next;
		}
		q->next = p->next;
		free(p);
		return first;
	}
}

node* delete(node* p, int index) {
	if (index<1 || index>count(p))
		return NULL;
	if (index == 1) {
		node* temp = p;
		p = p->next;
		free(temp);
		return p;
	}
	else {
		node* q = p;
		for (int i = 0; i < index - 2; i++)
			q = q->next;
		node* temp = q->next;
		q->next = temp->next;
		free(temp);
		return p;
	}
}