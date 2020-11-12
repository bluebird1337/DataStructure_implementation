#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

node* search(node*p, int key) {
	while (p) {
		if (p->data == key)
			return p;
		else
			p = p->next;
	}
	return NULL;
}
node* rsearch(node* p, int key) {
	if (p) {
		if (p->data == key)
			return p;
		else
			return rsearch(p->next, key);
	}
	else
		return NULL;
}