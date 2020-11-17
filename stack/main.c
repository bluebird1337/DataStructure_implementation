#pragma warning(disable:4996)
#pragma warning(disable:6031)
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

struct LL_stack1 {
	struct LL_stack1* next;
	int data;
}*top1;
typedef struct LL_stack1 LL_stack1;

void create(A_stack*st) {
	printf("Enter stack size");
	scanf("%d", &st->size);
	st->data = (int*)malloc(sizeof(int) * st->size);
	st->top = -1;
	return;
}

int is_empty1(A_stack* st) {
	if (st->top == -1)
		return 1;
	else
		return 0;
}
int is_empty() {
	if (top == NULL)
		return 1;
	else
		return 0;
}
int is_full(A_stack* st) {
	if (st->top == st->size - 1)
		return 1;
	else
		return 0;
}

int peek1(A_stack* st, int index) {
	if (index<1 || index > st->top+1) {
		printf("invalid index\n");
		return -1;
	}
	else {
		return st->data[st->top - (index - 1)];
	}
}
int peek(int index) {
	LL_stack* tmp = top;
	for (int i = 0; i < index - 1; i++)
		tmp = tmp->next;
	return tmp->data;
}

void push1(char x);
void push(A_stack* st, int x);
int pop(A_stack* st);
char pop2();
void display_A_stack(A_stack st);
void display();
int is_operant(char a);
int pre(char a);
char* in_to_post(char* s);
int eva(char* s);


int main() {
	char* s = "3*4+2*5";
	push1('=');
	s = in_to_post(s);
	printf("%s", s);
	printf("%d\n", eva(s));
	return 0;
}
