#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct Array_stack
{
	int* data;
	int top;
	int size;
};
typedef struct Array_stack A_stack;

struct LL_stack {
	struct LL_stack* next;
	char data;
}*top;
typedef struct LL_stack LL_stack;

int pop(A_stack* st) {
	int x = -1;
	if (st->top == -1) {
		printf("stack is empty\n");
	}
	else {
		x = st->data[st->top--];
	}
	return x;
}

char pop2() {
	int x = -1;
	if (top == NULL)
		printf("stack is empty\n");
	else {
		x = top->data;
		top = top->next;
	}
	return x;
}