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

void display_doubly(doubly* p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;;
	}
	printf("\n");
	return;
}

void display_circular(node* p) {
	node* first = p;
	do{
		printf("%d ", p->data);
		p = p->next;
	} while (p != first);
	printf("\n");
}

void display(node* p) {
	while (p) {
		printf("%d ", p->data);
		p = p->next;;
	}
	printf("\n");
	return;
}

void rdisplay(node* p) {
	if(p) {
		printf("%d ", p->data);
		rdisplay(p->next);
	}
	return;
}
