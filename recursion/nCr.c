#include<stdio.h>

int choose(int n, int r) {
	if (r == 0 || n == r)
		return 1;
	else
		return choose(n - 1, r) + choose(n - 1, r - 1);
}