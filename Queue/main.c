#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct queue {
	char* data;
	int size;
	int front;
	int rear;
};
typedef struct queue queue;

struct priority {
	char data;
	int p;
};
typedef struct priority pri;

void create(queue* q, int size){
	q->size = size;
	q->data = (char*)malloc(sizeof(char) * q->size);
	q->front = q->rear = -1;
}
queue a, b, c;

void enqueue(pri node) {
	switch (node.p)
	{
	case 1:
		if (a.size - 1 == a.rear)
			printf("queue a is fulled\n");
		else {
			a.rear++;
			a.data[a.rear] = node.data;
		}
		break;
	case 2:
		if (b.size - 1 == b.rear)
			printf("queue b is fulled\n");
		else {
			b.rear++;
			b.data[b.rear] = node.data;
		}
		break;
	case 3:
		if (c.size - 1 == c.rear)
			printf("queue c is fulled\n");
		else {
			c.rear++;
			c.data[c.rear] = node.data;
		}
		break;
	}
}

char dequeue() {
	char tmp ='\0';
	if (a.front != a.rear) {
		a.front++;
		tmp = a.data[a.front];
		return tmp;
	}
	else {
		if (b.front != b.rear) {
			b.front++;
			tmp = b.data[b.front];
			return tmp;
		}
		else {
			if (c.front != c.rear) {
				c.front++;
				tmp = c.data[c.front];
				return tmp;
			}
			else {
				printf("all queue is empty\n");
				return tmp;
			}
		}
	}
}

void display(queue p) {
	for (int i = p.front + 1; i <= p.rear; i++) {
		printf("%c ", p.data[i]);
	}
	printf("\n");
}

int main() {
	

	return 0;
}





/*
//Double_end circular queue
void enqueue(queue* q, int x, char dir) {
	if ( (q->rear+1)%q->size ==q->front)
		printf("queue is full\n");
	else {
		if (dir == 'f') {
			if (q->data[q->front - 1] == -1 || q->front == 0)
				printf("can't insert\n");
			else {
				q->data[q->front] = x;
				q->front--;
			}
		}
		else if (dir == 'r') {
			q->rear = (q->rear + 1) % q->size;
			q->data[q->rear] = x;
		}
		else
			printf("wrong direction\n");
	}
}

int dequeue(queue* q, char dir) {
	int x = -1;
	if (q->front == q->rear)
		printf("queue is empty\n");
	else {
		if (dir == 'f') {
			q->front = (q->front + 1) % q->size;
			x = q->data[q->front];
			q->data[q->front] = -1;
		}
		else if (dir == 'r') {
			x = q->data[q->rear];
			q->data[q->rear] = -1;
			q->rear--;
		}
		else
			printf("wrong direction\n");
	}
	return x;
}

void display(queue q) {
	int i = (q.front + 1) % q.size;
	while (i != (q.rear+1)%q.size) {
		printf("%d ", q.data[i]);
		i = (i + 1) % q.size;
	}
	printf("\n");
}

struct Queue {
	int data;
	struct Queue* next;
}*front = NULL, *rear = NULL;
typedef struct Queue queue;

void insert(int x) {
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue));
	if (tmp == NULL)
		printf("queue is full\n");
	else {
		if (rear == NULL) {
			tmp->data = x;
			tmp->next = NULL;
			front = tmp;
			rear = tmp;
		}
		else {
			tmp->data = x;
			tmp->next = NULL;
			rear->next = tmp;
			rear = tmp;
		}
	}
}

int delete() {
	int x = -1;
	if (front == rear)
		printf("queue is empty\n");
	else {
		queue* tmp = front;
		front = front->next;
		x = tmp->data;
		free(tmp);
	}
	return x;
}

void display() {
	queue* tmp = front;
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
*/