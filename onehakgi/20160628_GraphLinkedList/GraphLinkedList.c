#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct node{
	char data;
	struct node *link;
};

struct node* G[SIZE];

int main(){
	struct node *p;
	int i;
	char d;

	for (i = 0; i < SIZE; i++){
		printf("\n시작 정점 : ");
		scanf_s("%c", &d, 1);
		getchar();
		p = (struct node *)malloc(sizeof(struct node));
		p->data = d;
		p->link = NULL;
		G[i] = p;
		do{
			printf("\n인접 데이터 (없으면 Enter Key!) : ");
			scanf_s("%c", &d, 1);
			if (d == 10)break;
			p->link = (struct node *)malloc(sizeof(struct node));
			p = p->link;
			p->data = d;
			p->link = NULL;
			getchar(); //flush보다 더 잘먹음!
		} while (1);
	}
	
	printf("\n");

	for (i = 0; i < SIZE; i++){
		p = G[i];
		while (p != NULL){
			printf("%c", p->data);
			p = p->link;
		}
		printf("\n");
	}

	return 0;
}