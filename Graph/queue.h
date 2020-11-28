#pragma once
#include<stdlib.h>
#include<stdio.h>

struct queue {
	int* data;
	int front;
	int rear;
	int size;
};
typedef struct queue queue;

queue* create_queue(queue* q, int size) {
	q = (queue*)malloc(sizeof(queue));
	q->data = (int*)malloc(sizeof(int) * (size + 1));
	q->rear = q->front = 0;
	q->size = size;
	return q;
}

int is_full(queue* q) {
	if (q->rear == q->size)
		return 1;
	else
		return 0;
}

void enqueue(queue* q, int key) {
	if (is_full(q)) {
		printf("queue is fulled\n");
	}
	else {
		q->rear++;
		q->data[q->rear] = key;
	}
}

int is_empty(queue* q) {
	if (q->front == q->rear)
		return 1;
	else return 0;
}

int dequeue(queue* q) {
	int x = -1;
	if (is_empty(q)) {
		printf("queue is empty\n");
	}
	else {
		q->front++;
		x = q->data[q->front];
	}
	return x;
}