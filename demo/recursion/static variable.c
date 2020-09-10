#include <stdio.h>

int f(int n) {
	static int x = 0;
	if (n > 0) {
		x++;
		return f(n - 1) + x;
	}
	return 0;
}

