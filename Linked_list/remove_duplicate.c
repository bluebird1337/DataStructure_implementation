#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

void remove_duplicate(node* p){
	if (p == NULL)
		return;
	node* q, *tmp;
	q = p->next;
	while (q) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			tmp = q;
			q = q->next;
			free(tmp);
		}
	}
}




