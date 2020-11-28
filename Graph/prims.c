#define v 7
#define I 32767
#include<stdio.h>

void prim(int cost[][v + 1], int ans[][v - 1], int near[v + 1]) {
	//declare
	int i, j, k, min = I, x, y;
	//find the smallest edges
	for (i = 1; i <= v; i++) {
		for (j = i; j <= v; j++) {
			if (min > cost[i][j]) {
				min = cost[i][j];
				x = i; 
				y = j;
			}
		}
	}

	//update ans
	ans[0][0] = x;
	ans[1][0] = y;

	//update near 
	near[x] = near[y] = 0;
	for (i = 1; i <= v; i++) {
		if (near[i] != 0) {
			if (cost[i][x] < cost[i][y])
				near[i] = x;
			else
				near[i] = y;
		}
	}

	//iterative 
	for (i = 1; i < v-1; i++) {
		//find smallest edges near to selected vertices
		min = I;
		for (j = 1; j <= v; j++) {
			if (near[j] != 0 && min > cost[j][near[j]]) {
				min = cost[j][near[j]];
				k = j;
			}
		}
		//update ans
		ans[0][i] = near[k];
		ans[1][i] = k;

		//update near
		near[k] = 0;
		for (j = 1; j <= v; j++) {
			if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
				near[j] = k;
		}
	}

	for (i = 0; i < v-1; i++) {
		printf("<%d, %d>\n", ans[0][i], ans[1][i]);
	}
}