#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LL_stack1 {
	struct LL_stack1* next;
	int data;
}*top1;
typedef struct LL_stack1 LL_stack1;

void push2(int x) {
	LL_stack1* tmp;
	tmp = (LL_stack1*)malloc(sizeof(LL_stack1));
	if (tmp == NULL) {
		printf("stack is full\n");
		return;
	}
	tmp->data = x;
	tmp->next = top1;
	top1 = tmp;
}
int pop3() {
	int x = -1;
	if (top1 == NULL)
		printf("stack is empty\n");
	else {
		x = top1->data;
		top1 = top1->next;
	}
	return x;
}
int is_operant(char a);


int eva(char*s) {
	int a1, a2, r = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (is_operant(s[i]))
			push2(s[i]-'0');
		else if(is_operant(s[i])==0 && s[i]!='='){
			a2 = pop3();
			a1 = pop3();
			switch ( s[i])
			{
			case '+': {r = a1 + a2; break; }
			case '-': {r = a1 - a2; break; }
			case '*': {r = a1 * a2; break; }
			case '/': {r = a1 / a2; break; }
			}
			push2(r);
		}
	}
	return top1->data;
}