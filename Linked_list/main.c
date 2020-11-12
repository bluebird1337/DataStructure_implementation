#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

struct Doubly {
	int data;
	struct Doubly* prev;
	struct Doubly* next;
};
typedef struct Doubly doubly;

node* create(int* a, int n, node*);
void display(node* p);
int count(node* );
int max_num(node* );
int sum(node* );
node* search(node* p, int key);
node* rsearch(node* p, int key);
node* insert(node* p, int index, int x);
node* insert_sorted(node* p, int key);
int Is_sorted(node* p);
int delete(node* p, int index);
void remove_duplicate(node* p);
node* reverse(node* q);
node* concate(node* p, node* r);
node* merge(node* a, node* b);
int is_loop(node* p);
node* create_circular(int* a, int n, node* p); 
void display_circular(node* p);
int count_circular(node* p);
node* insert_circular(node* p, int index, int key);
node* delete_circular(node* p, int index);
doubly* create_doubly(int* a, int n, doubly* p);
doubly* insert_doubly(doubly* p, int index, int key);
void display_doubly(doubly* p);
doubly* delete_doubly(doubly* p, int index);
doubly* reverse_doubly(doubly* p);

int main() {
	node* first = NULL;
	node* second = NULL;
	doubly* third = NULL;
	third = (doubly*)malloc(sizeof(doubly));
	int a[10] = {1, 3, 5, 7, 9};

	third = create_doubly(a, 5, third);
	display_doubly(third);
	third = reverse_doubly(third);
	display_doubly(third);

	return 0;
}