#pragma warning(disable:6031)
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include<stdio.h>
#include "queue.h"

node* root;

void create_tree() {
	queue q;
	create_queue(&q, 100);

	printf("enter root value:\n");
	root = (node*)malloc(sizeof(node));
	scanf("%d", &root->data);
	root->l_child = root->r_child = NULL;
	enqueue(&q, root);

	while (!isEmpty(q)) {
		int x;
		node* p = dequeue(&q);

		printf("enter %d left child:\n", p->data);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->data = x;
			t->l_child = t->r_child = NULL;
			p->l_child = t;
			enqueue(&q, t);
		}

		printf("enter %d right child:\n", p->data);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->data = x;
			t->l_child = t->r_child = NULL;
			p->r_child = t;
			enqueue(&q, t);
		}
	}
}

void preorder(node* p) {
	if (p){
		printf("%d ", p->data);
		preorder(p->l_child);
		preorder(p->r_child);
	}
}
void inorder(node* p) {
	if (p ){
		preorder(p->l_child);
		printf("%d ", p->data);
		preorder(p->r_child);
	}
}
void postorder(node* p) {
	if (p){
		preorder(p->l_child);
		preorder(p->r_child);
		printf("%d ", p->data);
	}
}

int count_node(node*p) {
	if (p == NULL)
		return 0;
	int x, y;
	x = count_node(p->l_child);
	y = count_node(p->r_child);
	return x + y + 1;
}

int count_level(node* p) {
	if (p == NULL)
		return 0;
	int x, y;
	x = count_level(p->l_child);
	y = count_level(p->r_child);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}

void levelorder(node* p) {
	queue q;
	create_queue(&q, 100);
	enqueue(&q, p);

	while (!isEmpty(q)) {
		node* t = dequeue(&q);
		printf("%d ", t->data);
		if (t->l_child)
			enqueue(&q, t->l_child);
		if (t->r_child)
			enqueue(&q, t->r_child);
	}
}

int main() {
	create_tree();

	printf("level order:\n");
	levelorder(root);
	printf("\nnumber of nodes : %d\n", count_node(root));
	printf("level of tree : %d", count_level(root));
	return 0;
}