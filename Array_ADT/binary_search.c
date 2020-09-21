#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int A[10];
	int size;
	int length;
}array;

int binary_search(array a, int target) {
	int l = 0, h = a.length - 1, mid;
	while (l <= h) {
		mid = l - (l - h) / 2;
		if (a.A[mid] > target)
			h = mid - 1;
		else if (a.A[mid] < target)
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}