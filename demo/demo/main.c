#include<stdio.h>
double taylor(int x, int n);
int fast_power(int m, int n);
void head(int x);
void tail(int x);
int f(int n);
double taylor_horner(int x, int n);
int fib(int x);
int fib_loop(int x);
int fib_store(int n);

int data[100];
int main() {
	data[0] = 0;
	data[1] = 1;
	for (int i = 2; i < 100; i++)
		data[i] = -1;

	printf("%d \n", fib_store(7) );
	return 0;
}

