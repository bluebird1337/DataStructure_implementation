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

void push(A_stack* st, int x) {
	if (st->size - 1 == st->top)
		printf("stack overflow\n");
	else {
		st->top++;
		st->data[st->top] = x;
	}
}

void push1(char x) {
	LL_stack* tmp ;
	tmp = (LL_stack*)malloc(sizeof(LL_stack));
	if (tmp == NULL) {
		printf("stack is full\n");
		return;
	}
	tmp->data = x;
	tmp->next=top;
	top = tmp;
}