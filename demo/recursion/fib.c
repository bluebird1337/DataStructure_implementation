#include<stdio.h>

int fib(int x) {
	if (x == 1 || x == 2)
		return 1;
	else if (x == 0)
		return 0;
	else
		return fib(x - 1) + fib(x - 2);
}

int fib_loop(int x) {
	int t0 = 0, t1 = 1, r=0;
	if (x <= 1)
		return x;
	for (int i = 2; i <= x; i++) {
		r = t0 + t1;
		t0 = t1;
		t1 = r;
	}
	return r;
}


int data[100];
int fib_store(int n) {
	if (data[n] < 0) {
		int temp = fib_store(n - 1) + fib_store(n - 2);
		data[n] = temp;
		return temp;
	}
	else {
		return data[n];
	}
}