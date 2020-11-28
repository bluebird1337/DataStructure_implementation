#include"queue.h"

void BFS(int G[][7], int start, int n) {
	int visited[7] = { 0 };
	queue* q = NULL;
	q = create_queue(q, 7);
	int j;
	printf("%d ", start);
	visited[start] = 1;

	enqueue(q, start);
	while (!is_empty(q)) {

		start = dequeue(q);
		for (j = 1; j <= n; j++) {
			if (G[start][j] == 1 && visited[j] == 0) {
				enqueue(q, j);
				printf("%d ", j);
				visited[j] = 1;
			}
		}
	}

}

void DFS(int G[][7], int start, int size) {
	static int visited[7] = { 0 };
	if (visited[start] == 0) {
		printf("%d ", start);
		visited[start] = 1;
		for (int j = 1; j <= size; j++) {
			if (G[start][j] == 1 && visited[j] == 0)
				DFS(G, j, size);
		}
	}
}
