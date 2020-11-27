#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

node* insert_sorted(node* p, int key) {
	node* tmp, *r = NULL, *q = p;
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

int hash_function(int key) {
	return key % 10;
}

void chaining(node*HT[], int key) {
	int index = hash_function(key);
	HT[index] = insert_sorted(HT[index], key);
}

node* chain_search(node** HT, int key) {
	int index = hash_function(key);
	node* p = HT[index];
	while (p) {
		if (p->data == key)
			return p;
		else if (p->data < key)
			p = p->next;
		else
			return NULL;
	}
	return NULL;
}