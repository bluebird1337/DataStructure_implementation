#pragma warning(disable:6031)
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#pragma warning(disable:4133)
#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node* lchild;
	int data;
	int height;
	struct node* rchild;
}*root = NULL;
typedef struct node node;


/// <insert>
/// //////////////////////////
node* LL_rotation(node* p) {
	node* pl = p->lchild;
	node* plr = pl->rchild;
	pl->rchild = p;
	p->lchild = plr;
	p->height = height(p);
	pl->height = height(pl);

	if (root == p)
		root = pl;
	return pl;
}

node* LR_rotation(node* p) {
	node* pl = p->lchild, *plr = pl->rchild, *plrl = plr->lchild, *plrr = plr->rchild;
	plr->lchild = pl;
	plr->rchild = p;
	pl->rchild = plrl;
	p->lchild = plrr;
	plr->height = height(plr);
	p->height = height(p);
	pl->height = height(pl);

	if (root == p)
		root = plr;
	return plr;
}

node* RR_rotation(node* p) {
	node* pr = p->rchild;
	node* prl = pr->lchild;
	pr->lchild = p;
	p->rchild = prl;
	p->height = height(p);
	pr->height = height(pr);

	if (root == p)
		root = pr;
	return pr;
}

node* RL_rotation(node* p) {
	node* pr = p->rchild, * prl = pr->lchild, * prll = prl->lchild, * prlr = prl->rchild;
	prl->lchild = p;
	prl->rchild = pr;
	pr->lchild = prlr;
	p->rchild = prll;
	p->height = height(p);
	prl->height = height(prl);
	pr->height = height(pr);

	if (root == p)
		root = p;
	return prl;
}

int height(node* p) {
	int x, y;
	if (p) {
		x = p->lchild ? p->lchild->height : 0;
		y = p->rchild ? p->rchild->height : 0;
	}
	else {
		x = 0;
		y = 0;
	}
	return x > y ? x + 1 : y + 1;
}

int balance_factor(node* p) {
	int x = p && p->lchild ? (p->lchild->height) : 0;
	int y = p && p->rchild ? (p->rchild->height) : 0;
	return  x - y;
}


node* insert(node* p, int x) {
	if (p == NULL)
	{
		node* t;
		t = (node*)malloc(sizeof(node));
		t->data = x;
		t->lchild = t->rchild = NULL;
		t->height = 1;
		if (root == NULL)
			root = t;
		return t;
	}
	if (p->data < x) {
		p->rchild = insert(p->rchild, x);
	}
	else if (p->data > x) {
		p->lchild = insert(p->lchild, x);
	}

	p->height = height(p);
	if (balance_factor(p) == 2 && balance_factor(p->lchild) == 1)
		return LL_rotation(p);
	if (balance_factor(p) == 2 && balance_factor(p->lchild) == -1)
		return LR_rotation(p);
	if (balance_factor(p) == -2 && balance_factor(p->lchild) == 1)
		return RL_rotation(p);
	if (balance_factor(p) == -2 && balance_factor(p->lchild) == -1)
		return RR_rotation(p);

	return p;
}
/// //////////////////////////
/// <insert>


/// <delete>
/// //////////////////////////

node* pre(node* p) {
	while (p && p->rchild)
		p = p->rchild;
	return p;
}

node* succ(node* p) {
	while (p && p->lchild)
		p = p->lchild;
	return p;
}

node* delete(node* p, int key) {
	if (p == NULL) {
		printf("key not exist\n");
		return NULL;
	}
	
	if (p->data == key) {
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root)
				root == NULL;
			free(p);
			return NULL;
		}
		else {
			if (  (p->lchild && height(p->lchild)) > ( p->rchild && height(p->rchild) )  ) {
				node*q = pre(p->lchild);
				p->data = q->data;
				p->lchild = delete(p->lchild, q->data);
			}
			else {
				node* q = succ(p->rchild);
				p->data = q->data;
				p->rchild = delete(p->rchild, q->data);
			}
		}
	}
	//search
	else if (p->data > key) {
		p->lchild = delete(p->lchild, key);
	}
	else {
		p->rchild = delete(p->rchild, key);
	}
	p->height = height(p);

	if (p->height == 2) {
		if (p->lchild->height == 1)
			return p = LL_rotation(p);
		else
			return p = LR_rotation(p);
	}
	else if (p->height == -2) {
		if (p->rchild->height == -1)
			return p = RR_rotation(p);
		else {
			return p = RL_rotation(p);
		}
	}

	return p;
}
/// <delete>
/// //////////////////////////

void inorder(node* p) {
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
	return;
}

int main() {
	root = insert(root, 10);
	insert(root, 20);
	insert(root, 30);
	insert(root, 25);
	insert(root, 28);
	insert(root, 27);
	insert(root, 5);
	inorder(root);
	delete(root, 25);
	printf("\n");
	inorder(root);
	return 0;
}