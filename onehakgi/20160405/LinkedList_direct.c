#include <stdio.h>

int main(){

	struct node{
		int data;
		struct node *link;
	}a, b, c, *p;

	p = &a;
	a.data = 'A';
	a.link = &b;
	b.data = 'B';
	b.link = &c;
	c.data = 'C';
	c.link = NULL;

	return 0;

}