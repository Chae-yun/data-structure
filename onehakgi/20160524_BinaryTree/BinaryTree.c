#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *llink;
	int data;
	struct node *rlink;
};

struct node *BinaryTree(int a[], int left, int right){

	struct node *p = NULL;
	int mid;

	if (left <= right){
		mid = (left + right) / 2;
		printf("%d, %d, %d\n", left, right, mid); //진행상황
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a[mid];
		p->llink = BinaryTree(a, left, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, right);
	}

	return p; //총 25번 리턴

}

void Delete(struct node *DelNode){

	if (DelNode != NULL){
		Delete(DelNode->llink);
		Delete(DelNode->rlink);
		printf("%d ", DelNode->data);
		free(DelNode);
	}

}

int main(void){
	
	int a[] = { 3, 5, 7, 10, 15, 17, 20, 25, 28, 31, 33, 35 };
	struct node *root;
	int n = sizeof(a) / sizeof(int);

	root = BinaryTree(a, 0, n - 1);
	Delete(root);

	return 0;

}