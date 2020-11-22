#pragma warning(disable:6031)
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#pragma warning(disable:4133)
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

node* create_pre(int* pre, int n) {
	stack st;
	create_stack(&st, 100);
	node* root, *p, *t;
	root = (node*)malloc(sizeof(node));
	root->data = pre[0];
	root->lchild = root->rchild = NULL;
	int i = 1;
	p = root;

	while(i<n)
	{
		if (pre[i] < p->data) {
			t = (node*)malloc(sizeof(node));
			t->data = pre[i++];
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			insert_stack(&st, p);
			p = t;
		}
		else {
			if (pre[i] > p->data && pre[i] < stacktop(st)) {
				t = (node*)malloc(sizeof(node));
				t->data = pre[i++];
				t->lchild = t->rchild = NULL;
				p->rchild = t;
				p = t;
			}
			else {
				p = pop_stack(&st);
			}
		}
	}
	return root;
}

void inorder(node* p) {
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

node* root;
void insert(int x) {
	node* t, *r = NULL;
	if (root == NULL) {
		t = (node*)malloc(sizeof(node));
		t->data = x;
		t->lchild = t->rchild = NULL;
		root = t;
		return;
	}
	node* p = root;

	while (p) {
		if (p->data < x) {
			r = p;
			p = p->rchild;
		}
		else if(p->data > x){
			r = p;
			p = p->lchild;
		}
		else {
			printf("%d is exist\n", x);
			return;
		}
	}
	t = (node*)malloc(sizeof(node));
	t->data = x;
	t->lchild = t->rchild = NULL;
	if (r->data < x)
		r->rchild = t;
	else
		r->lchild = t;
}

node* Rinsert(node* Root, int x) {
	if (Root == NULL) {
		node* t = NULL;
		t = (node*)malloc(sizeof(node));
		t->data = x;
		t->lchild = t->rchild = NULL;
		return t;
	}
	else if (Root->data > x) {
		Root->lchild = Rinsert(Root->lchild, x);
	}
	else if (Root->data < x) {
		Root->rchild = Rinsert(Root->rchild, x);
	}
	else {
		printf("%d is exist\n", x);
		return NULL;
	}
	return Root;
}

int height(node* p) {
	if (p) {
		int x = height(p->lchild);
		int y = height(p->rchild);
		return x > y ? x + 1 : y + 1;
	}
	return 0;
}

node* pred(node* p) {
	while (p->rchild)
		p = p->rchild;
	return p;
}
node* succ(node* p) {
	while (p->lchild)
		p = p->lchild;
	return p;
}

node* Delete_BST(node* p, int key) {
	if (p == NULL) {
		printf("%d not found\n", key);
		return NULL;
	}

	if (p->data < key) {
		p->rchild = Delete_BST(p->rchild, key);
	}
	else if (p->data > key) {
		p->lchild = Delete_BST(p->lchild, key);
	}
	else {
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root)
				root = NULL;
			free(p);
			return NULL;
		}
		else if (height(p->lchild) > height(p->rchild) ) {
			node* q = pred(p->lchild);
			p->data = q->data;
			p->lchild = Delete_BST(q, q->data);
		}
		else {
			node* q = succ(p->rchild);
			p->data = q->data;
			p->rchild = Delete_BST(p->rchild, q->data);
		}

	}

	return p;
}

node* search(node* p, int key) {
	if (p == NULL) {
		printf("not found\n");
		return NULL;
	}

	if (p->data < key)
		return search(p->rchild, key);
	else if (p->data > key)
		return search(p->lchild, key);
	else {
		return p;
	}
}


int main() {
	insert(5);
	insert(3);
	insert(8);
	insert(1);
	insert(4);
	inorder(root);
	Delete_BST(root, 5);
	printf("\n");
	inorder(root);
}