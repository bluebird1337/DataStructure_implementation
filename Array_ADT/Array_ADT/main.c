#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p, * q;
	p = (int*)malloc(sizeof(int) * 5);
	q = (int*)malloc(sizeof(int) * 10);
	p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11;
	for (int i = 0; i < 5; i++)
		q[i] = p[i];
	free(p);
	p = q;
	q = NULL;
	return 0;
}