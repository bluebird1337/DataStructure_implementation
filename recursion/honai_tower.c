#include<stdio.h>

void honai(int a, int b, int c, int n) {
	if (n == 0)
		return;
	honai(a, c, b, n - 1);
	printf("%d to %d\n", a, c);
	honai(b, a, c, n - 1);
}