#pragma warning(disable: 4996)
#pragma warning(disable:6011)
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

struct Polynomial {
	int coeff;
	int exp;
	struct Polynomial* next;
};
typedef struct Polynomial poly;

int fp(int a, int b) {
	int base = a, sum = 1;
	while (b) {
		if (b % 2) sum *= base;
		base *= base;
		b = b / 2;
	}
	return sum;
}

int eval(poly*p, int x) {
	int sum = 0;
	while (p) {
		sum += p->coeff * fp(x, p->exp);
		p = p->next;
	}
	return sum;
}

void display_poly(poly* p, int x) {
	poly* q = p;
	while (p) {
		if (p->next != NULL)
			printf("%dx%d+", p->coeff, p->exp);
		else {
			if (p->exp == 0)
				printf("%d=", p->coeff);
			else
				printf("%dx%d= ", p->coeff, p->exp);
		}
		p = p->next;
	}
	printf("%d\n", eval(q, x));
}

poly* create_poly() {
	int num;
	printf("Enter number of term\n");
	scanf("%d", &num);
	poly* p, *last;
	p = (poly*)malloc(sizeof(poly));
	printf("Enter %d terms:\n", num);
	scanf("%d%d", &p->coeff, &p->exp);
	p->next = NULL;
	last = p;
	for (int i = 1; i < num; i++) {
		poly* tmp;
		tmp = (poly*)malloc(sizeof(poly));
		scanf("%d%d", &tmp->coeff, &tmp->exp);
		tmp->next = NULL;
		last->next = tmp;
		last = tmp;
	}
	return p;
}