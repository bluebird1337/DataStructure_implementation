#pragma once
#pragma warning(disable:6031)
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>

struct Node {
	struct node* lchild;
	int data;
	struct node* rchild;
};
typedef struct Node node;

struct stack {
	node** data;
	int top;
	int size;
};
typedef struct stack stack;

void create_stack(stack*st, int size) {
	st->size = size;
	st->data = (node**)malloc(sizeof(node*) * size);
	st->top = -1;
}

int stacktop(stack st) {
	if (st.top == -1)
		return 1000000;
	else
		return st.data[st.top]->data;
}

void insert_stack(stack* st, node* x) {
	if (st->top == st->size - 1)
		printf("stack is fulled\n");
	else {
		st->top++;
		st->data[st->top]= x;
	}
}

node* pop_stack(stack* st) {
	node* x = NULL;
	if (st->top == -1)
		printf("stack is empty\n");
	else {
		x = st->data[st->top];
		st->top--;
	}
	return x;
}