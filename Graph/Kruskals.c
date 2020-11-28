#include<stdio.h>
#define n 7
#define e 9
#define I 32767

//set operation
int set[n + 1] = { -1, -1, -1, -1, -1, -1, -1, -1 };
void myunion(int a, int b) {
	if (set[a] < set[b]) {
		set[a] = set[a] + set[b];
		set[b] = a;
	}
	else {
		set[b] = set[b] + set[a];
		set[a] = b;
	}
}
int find(int x) {
	while (set[x] > 0) {
		x = set[x];
	}
	return x;
}

//kruskal
void kruskal(int cost[][9]) {
	//declare
	int ans[2][n - 1];
	int included[e] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	
	int i = 0, j, k, min, u, v;

	while (i < n - 1) {
		min = I;
		//find minimum cost edges
		for (j = 0; j < e; j++) {
			if (included[j] == 0 && min > cost[2][j]) {
				min = cost[2][j];
				u = cost[0][j];
				v = cost[1][j];
				k = j;
			}
		}
		//check whether it will form a cycle
		if (find(u) != find(v)) {
			myunion(find(u), find(v));
			ans[0][i] = u;
			ans[1][i] = v;
			i++;
		}
		included[k] = 1;
	}

	//show the result
	for (i = 0; i < n - 1; i++)
		printf("<%d, %d> \n", ans[0][i], ans[1][i]);
}