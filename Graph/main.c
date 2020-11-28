#include<stdio.h>
#pragma warning(disable:4996)

//prims
#define I 32767
#define v 7 // # of vertices in Graph - prims

//function
void BFS(int G[][7], int start, int n);
void DFS(int G[][7], int start, int size);
void prim(int cost[][v + 1], int ans[][v - 1], int near[v + 1]);
void myunion(int a, int b);
int find(int x);
void kruskal(int cost[][9]);

//main
int main() {
	int edges[3][9] = { { 1, 1,  2,  2, 3,  4,  4,  5,  5},
					   { 2, 6,  3,  7, 4,  5,  7,  6,  7},
					   {25, 5, 12, 10, 8, 16, 14, 20, 18} };

	kruskal(edges);



	/*
	* prim
	int cost[][v+1] = {
		{I, I, I, I, I, I, I, I},
		{I, I, 25, I, I, I, 5, I},
		{I, 25, I, 9, I, I, I, 6},
		{I, I, 9, I, 10, I, I, I},
		{I, I, I, 10, I, 12, I, 11},
		{I, I, I, I, 12, I, 18, 16},
		{I, 5, I, I, I, 18, I, I},
		{I, I, 6, I, 11, 16, I, I},
	};
	int ans[2][v-1];
	int near[v+1] = { I, I, I, I ,I ,I ,I ,I};
	prim(cost, ans, near);
	*/


}