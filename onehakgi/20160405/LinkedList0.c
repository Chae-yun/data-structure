#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

int main(){

	struct node *head, *p;
	int d;

	head = (struct node *)malloc(sizeof(struct node)); //*붙이지 않는다
	p = head;
	p->data = INT_MAX; //얘는 임시로 준 것, 실제 출력할 값이 아님
	p->link = NULL;
	printf("데이터 : ");
	scanf_s("%d", &d);

	while (d != 0){
		p->link = (struct node *)malloc(sizeof(struct node));
		p = p->link;
		p->data = d;
		p->link = NULL;
		printf("\n데이터 : ");
		scanf_s("%d", &d);
	}

	p = head->link;
	printf("\n연결 리스트 데이터 : ");

	printf("%d", p->data);
	p = p->link; //이거 추가하면 마지막 화살표 없당!!!

	while (p != NULL){
		printf("->%d", p->data);
		p = p->link;
	}

	free(head); //C는 가비지콜렉션이 없기 때문에
	return 0;

}