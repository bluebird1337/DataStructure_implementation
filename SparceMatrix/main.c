#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int r;
	int c;
	int x;
}element;

typedef struct {
	int m;
	int n;
	int num;
	element* e;
}sparse;

void create(sparse* s, int m, int n, int num) {
	s->m = m;
	s->n = n;
	s->num = num;
	s->e = (element*)malloc(sizeof(element) * num);
	printf("enter non-zero elements\n");
	for (int i = 0; i < num; i++) {
		scanf("%d%d%d", &s->e[i].c, &s->e[i].r, &s->e[i].x);
	}
}
void display(sparse s) {
	int k = 0;
	for (int i = 0; i < s.num; i++) {
		for (int j = 0; j < s.num; j++) {
			if (i == s.e[k].c && j == s.e[k].r)
				printf("%d ", s.e[k++].x);
			else
				printf("0 ");
		}
	}
}

sparse add(sparse s1, sparse s2) {
	sparse sum;
	if (s1.m != s2.m && s1.n != s2.n)
		return NULL;
	else
	{
		sum.m = s1.m;
		sum.n = s1.n;
		sum.e = (element*)malloc(sizeof(element) * (s1.num + s2.num));
		int i, j, k;
		i = j = k = 0;
		while (i < s1.num && j < s2.num) {
			if (s1.e[i].c < s2.e[j].c)
				sum.e[k++] = s1.e[i++];
			else if (s1.e[i].c > s2.e[j].c)
				sum.e[k++] = s1.e[j++];
			else {
				if (s1.e[i].r < s2.e[j].r)
					sum.e[k++] = s1.e[i++];
				else if (s1.e[i].r > s2.e[j].r)
					sum.e[k++] = s1.e[j++];
				else {
					sum.e[k] = s1.e[i];
					sum.e[k++].x = s1.e[i++].x + s2.e[j++].x;
				}
			}
			for (; i < s1.num; i++) sum.e[k++] = s1.e[i];
			for (; j < s2.num; j++) sum.e[k++] = s2.e[j];
			sum.num = k;
		}
	}
	return sum;
}

int main() {
	sparse s1, s2, s3;
	create(&s1, 5, 5, 5);
	create(&s2, 5, 5, 5);
	s3 = add(s1, s2);
	printf("first\n");
	display(s1);
	printf("second\n");
	display(s2);
	printf("added\n");
	display(s3);
	return 0;
}