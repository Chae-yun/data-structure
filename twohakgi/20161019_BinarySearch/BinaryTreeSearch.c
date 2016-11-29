#include <stdio.h>
#include <stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node))

struct node{
	struct node *llink;
	int data;
	struct node *rlink;
};

struct node *BinaryTree(int a[], int low, int high){
	int mid;
	struct node *p = NULL;

	if (low <= high){
		mid = (low + high) / 2;
		p = NEW;
		p->data = a[mid];
		p->llink = BinaryTree(a, low, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, high);
	}
	return p;
}

void search_data(struct node *p){
	int cnt = 0, value;

	printf("\n찾을 데이터 : ");
	scanf_s("%d", &value);
	
	while (p != NULL){
		cnt++;
		if (value == p->data) break;
		if (value < p->data)p = p->llink;
		else p = p->rlink;
	}

	if (p != NULL)
		printf("%d를(을) %d번 비교하여 찾았다!\n", value, cnt);
	else
		printf("%d는(은) 없는 데이터다!\n", value);
}

void DeleteAll(struct node *DelNode){
	if (DelNode != NULL){
		DeleteAll(DelNode->llink);
		DeleteAll(DelNode->rlink);
		printf("%d  ", DelNode->data);
		free(DelNode);
	}
}

int main(){
	int a[10] = { 3, 5, 7, 10, 15, 17, 20, 25, 28, 31 };
	struct node *root;

	root = BinaryTree(a, 0, 9);
	search_data(root);
	printf("삭제 순서 : ");
	DeleteAll(root);

	return 0;
}