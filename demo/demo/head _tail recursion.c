#include <stdio.h>

//head recursion 
void head(int x) {
	if (x > 0){
		head(x - 1);
		printf("%d", x);
	}
}

//tail recursion
void tail(int x) {
	if (x > 0) {
		printf("%d", x);
		tail(x - 1);
	}
}
