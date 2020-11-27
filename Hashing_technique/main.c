#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

//function
node* insert_sorted(node* p, int key);
int hash_function(int key);
void chaining(node* HT[], int key);
node* chain_search(node** HT, int key);
void linear_probling(int HT[], int key);
int linear_search(int HT[], int key);

//main
int main() {

	//linear probling
	int HT[10];
	for (int i = 0; i < 10; i++)
		HT[i] = -1;
	linear_probling(HT, 19);
	linear_probling(HT, 29);
	linear_probling(HT, 39);
	linear_probling(HT, 49);
	int key = 19;
	int ans = linear_search(HT, key);
	if (ans != -1)
		printf("%d is found at %d\n", key, ans);
	else
		printf("%d is not found\n", key);
	/*
	//chaining
	node* HT[10];
	for (int i = 0; i < 10; i++) {
		HT[i] = NULL;
	}
	chaining(HT, 5);
	chaining(HT, 15);
	chaining(HT, 2);
	chaining(HT, 32);

	int key = 20;
	node* p = chain_search(HT, key);
	if (p == NULL)
		printf("%d is not found\n", key);
	else
		printf("%d is found\n", p->data);

	*/
	return 0;
}