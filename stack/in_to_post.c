#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LL_stack {
	struct LL_stack* next;
	char data;
}*top;
typedef struct LL_stack LL_stack;

void push1(char x);
char pop2();

int is_operant(char a) {
	if (a == '+' || a == '-' || a == '*' || a == '/' ||a =='=')
		return 0;
	else
		return 1;
}

int pre(char a) {
	if (a == '+' || a == '-')
		return 1;
	else if (a == '*' || a == '/')
		return 2;
	else
		return 0;
}



char* in_to_post(char* s) {
	char* postfix;
	int len = strlen(s);
	postfix = (char*)malloc(sizeof(char) * (len+1));
	int i = 0, j = 0;
	while (s[i] != '\0') {
		if (is_operant(s[i]))
			postfix[j++] = s[i++];
		else {
			if (pre(s[i]) > pre(top->data)) {
				push1(s[i++]);
			}
			else {
				postfix[j++] = pop2();
			}
		}
	}
	while (top)
		postfix[j++] = pop2();
	postfix[j] = '\0';

	return postfix;
}