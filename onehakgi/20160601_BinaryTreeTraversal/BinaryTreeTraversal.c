#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *llink;
	char data;
	struct node *rlink;
};

struct node *makeNode(char data){
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->data = data;
	p->llink = NULL;
	p->rlink = NULL;
	return p;
}

void Delete(struct node *p){
	if (p != NULL){
		Delete(p->llink);
		Delete(p->rlink);
		free(p);
	}
}

void PreOrder(struct node *p){
	if (p != NULL){
		printf("%c   ", p->data);
		PreOrder(p->llink);
		PreOrder(p->rlink);
	}
}

void InOrder(struct node *p){
	if (p != NULL){
		PreOrder(p->llink);	
		printf("%c   ", p->data);
		PreOrder(p->rlink);
	}
}

void PostOrder(struct node *p){
	if (p != NULL){
		PreOrder(p->llink);
		PreOrder(p->rlink);
		printf("%c   ", p->data);
	}
}

int main(){
	struct node *root;
	root = makeNode('A');
	root->llink = makeNode('B');
	root->rlink = makeNode('C');
	root->llink->rlink = makeNode('D');
	root->llink->rlink->llink = makeNode('E');
	root->rlink->rlink = makeNode('F');

	printf("傈困 款青 (PreOrder) : ");
	PreOrder(root);
	printf("\n");

	printf("吝困 款青 (InOrder) : ");
	InOrder(root);
	printf("\n");

	printf("饶困 款青 (PostOrder) : ");
	PostOrder(root);
	printf("\n");

}