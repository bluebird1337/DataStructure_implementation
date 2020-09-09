#include<stdio.h>

double taylor(int x, int n) {
	static double p = 1, f = 1;
	double r;
	if (n == 0)
		return 1;
	r = taylor(x, n - 1);
	p *= x;
	f *= n;
	return r + p / f;
}

double taylor_horner(int x, int n) {
	static double r = 1;
	if (n == 0)
		return r;
	r = 1 + x * r / n;
	return taylor_horner(x, n - 1);
}