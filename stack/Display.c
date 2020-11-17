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

void display_A_stack(A_stack st) {
	for (int i = st.top; i >= 0; i--)
		printf("%d ", st.data[i]);
	printf("\n");
}
struct LL_stack {
	struct LL_stack* next;
	char data;
}*top;
typedef struct LL_stack LL_stack;

void display() {
	while (top) {
		printf("%d ", top->data);
		top = top->next;
	}
	printf("\n");
}