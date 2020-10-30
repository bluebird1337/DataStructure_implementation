#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int d;
	int* a;
}matrix;

matrix create(int d) {
	matrix a;
	a.d = d;
	a.a = (int*)malloc(sizeof(int) * (d + 1) * d / 2);
	return a;
}
void set(matrix a, int i, int j, int x) {
	if (i <= j)
		a.a[a.d * (i-1) + (i-1)*(i-2)/2 + (j-i)] = x;
}
void get(matrix a, int i, int j) {
	if (i <= j)
		return a.a[a.d * (i - 1) + (i - 1) * (i - 2) / 2 + (j - i) ];
	else
		return 0;
}
void display(matrix a) {
	for (int i = 0; i < a.d; i++) {
		for (int j = 0; j < a.d; j++) {
			if (i <= j)
				printf("%3d", a.a[a.d * (i - 1) + (i - 1) * (i - 2) / 2 + (j - i) ] );
			else
				printf("%3d", 0);
		}
		printf("\n");
	}
}
int main() {
	matrix a;
	a = create(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			set(a, i, j, i + j + 1);
	}
	display(a);
	return 0;
}

/*lower_matrix
typedef struct {
	int d;
	int* a;
}matrix;

matrix create(int d) {
	matrix a;
	a.d = d;
	a.a = (int*)malloc(sizeof(int) * (d+1)*d/2 );
	return a;
}
void set(matrix a, int i, int j, int x) {
	if (i >= j)
		a.a[i*(i-1)/2 + (j-1)]= x;
}
void get(matrix a, int i, int j) {
	if (i >= j)
		return a.a[i * (i - 1) / 2 + (j - 1)];
	else
		return 0;
}
void display(matrix a) {
	for (int i = 0; i < a.d; i++) {
		for (int j = 0; j < a.d; j++) {
			if (i >= j)
				printf("%3d", a.a[i * (i - 1) / 2 + (j - 1)]);
			else
				printf("%3d", 0);
		}
		printf("\n");
	}
}
int main() {
	matrix a;
	a = create(6);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++)
			set(a, i, j, i + j + 1);
	}
	display(a);
	return 0;
}
*/
/*diagonal matrix
typedef struct {
	int d;
	int* a;
}matrix;

matrix create(int d) {
	matrix a;
	a.d = d;
	a.a = (int*)malloc(sizeof(int) * d);
	return a;
}
void set(matrix a, int i, int j, int x) {
	if (i == j)
		a.a[i] = x;
}
void get(matrix a, int i, int j) {
	if (i == j)
		return a.a[i];
	else
		return 0;
}
void display(matrix a) {
	for (int i = 0; i < a.d; i++) {
		for (int j = 0; j < a.d; j++) {
			if (i == j)
				printf("%d ", a.a[i]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}
int main() {
	matrix a;
	a = create(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			set(a, i, j, i + j+1);
	}
	display(a);
	return 0;
}
*/