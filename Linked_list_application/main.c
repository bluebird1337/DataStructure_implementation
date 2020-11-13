#pragma warning(disable: 4996)
#pragma warning(disable:6011)
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int col;
	int data;
	struct node* next;
};
typedef struct Node node;
struct Polynomial {
	int coeff;
	int exp;
	struct Polynomial* next;
};
typedef struct Polynomial poly;

int row, column;

node** create_sparse();
poly* create_poly();
void display_sparse(node** p);
void display_poly(poly* p, int x);
int fp(int a, int b);
int eval(poly* p, int x);

int main() {
	poly* p;
	p = create_poly();
	//printf("%d", eval(p, 2));
	display_poly(p, 2);
	return 0;
}