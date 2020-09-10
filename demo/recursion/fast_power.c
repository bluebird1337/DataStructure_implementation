#include<stdio.h>

int fast_power(int m, int n) {
	int base = m, ans = 1;
	while (n > 0) {
		if (n & 1) ans *= base;
		base *= base;
		n >>= 1;
	}
	return ans;
}