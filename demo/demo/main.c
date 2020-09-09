#include<stdio.h>
double taylor(int x, int n);
int fast_power(int m, int n);
void head(int x);
void tail(int x);
int f(int n);
double taylor_horner(int x, int n);

int main() {
	printf("%lf \n", taylor_horner(4, 15) );

	return 0;
}

