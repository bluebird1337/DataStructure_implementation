#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;
int count(node*);
node* head;
int count_circular(node* p);

int Is_sorted(node* p) {
	if (p == NULL)
		return 0;
	else {
		int temp = p->data;
		p = p->next;
		while (p) {
			if (temp > p->data)
				return 0;
			temp = p->data;
			p = p->next;
		}
		return 1;
	}
}