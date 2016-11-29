#include <stdio.h>
#include <stdlib.h>

struct node{
	int coefficient;
	int degree;
	struct node *link;
};

struct node *makeNode(int coefficient, int degree){
	struct node *mNode;
	mNode = (struct node *)malloc(sizeof(struct node));
	mNode->coefficient = coefficient;
	mNode->degree = degree;
	mNode->link = NULL;
	return mNode;
}

void insertNode(struct node *p, int coefficient, int degree){
	struct node *mNode, *previous = p;

	if (coefficient == 0) return;

	mNode = makeNode(coefficient, degree);
	p = p->link;

	if (p == NULL){
		previous->link = mNode;
		return;
	}

	while (p != NULL){
		if (p->degree == mNode->degree){
			p->coefficient += mNode->coefficient;
			if (p->coefficient == 0){
				previous->link = p->link;
				free(p);
			}
			free(mNode);
			break;
		}
		else if (p->degree < mNode->degree){
			mNode->link = previous->link;
			previous->link = mNode;
			break;
		}
		else{
			previous = p;
			p = p->link;
		}
	}
	if (previous->link == NULL) previous->link = mNode;
}

struct node *addPolynomial(struct node *a, struct node *b){
	struct node *add, *p;
	int coefficient;

	add = makeNode(NULL, NULL);
	p = add;
	a = a->link;
	b = b->link;
	while (a && b){
		if (a->degree > b->degree){
			p->link = makeNode(a->coefficient, a->degree);
			p = p->link;
			a = a->link;
		}
		else if (a->degree < b->degree){
			p->link = makeNode(b->coefficient, b->degree);
			p = p->link;
			b = b->link;
		}
		else if (a->degree == b->degree){
			if (coefficient = a->coefficient + b->coefficient){
				p->link = makeNode(coefficient, a->degree);
				p = p->link;
			}
			a = a->link; 	b = b->link;
		}
	}
	while (a){
		p->link = makeNode(a->coefficient, a->degree);
		p = p->link; a = a->link;
	}
	while (b){
		p->link = makeNode(b->coefficient, b->degree);
		p = p->link; b = b->link;
	}
	return add;
}

void Print(struct node *p){
	p = p->link;
	while (p != NULL){
		if (p->coefficient > 0)
			printf("+%dx%d", p->coefficient, p->degree);
		else
			printf("%dx%d", p->coefficient, p->degree);
		p = p->link;
	}
	printf("\n");
}

int main(void){
	struct node *a = makeNode(NULL, NULL);
	struct node *b = makeNode(NULL, NULL);
	struct node *c;

	insertNode(a, 2, 4);
	insertNode(a, 3, 2);
	insertNode(a, -5, 0);
	insertNode(a, 1, 3);
	insertNode(a, -3, 2);

	insertNode(b, 3, 2);
	insertNode(b, 4, 5);
	insertNode(b, 2, 3);
	insertNode(b, 1, 2);

	Print(a);
	Print(b);

	c = addPolynomial(a, b);
	Print(c);

	free(a); free(b); free(c);
	return 0;
}
