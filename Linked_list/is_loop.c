#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

int is_loop(node* p) {
	node* q = p;
	do{
		if ((p==NULL) || (q==NULL) )
			return 0; // one of the pointer reach NULL : is linear
		p = p->next;
		q = q->next;
		if (q)
			q = q->next;
	} while (p != q);
	//out of loop -> p==q, is a loop!
	return 1;
}