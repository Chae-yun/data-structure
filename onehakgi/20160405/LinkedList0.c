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

	head = (struct node *)malloc(sizeof(struct node)); //*������ �ʴ´�
	p = head;
	p->data = INT_MAX; //��� �ӽ÷� �� ��, ���� ����� ���� �ƴ�
	p->link = NULL;
	printf("������ : ");
	scanf_s("%d", &d);

	while (d != 0){
		p->link = (struct node *)malloc(sizeof(struct node));
		p = p->link;
		p->data = d;
		p->link = NULL;
		printf("\n������ : ");
		scanf_s("%d", &d);
	}

	p = head->link;
	printf("\n���� ����Ʈ ������ : ");

	printf("%d", p->data);
	p = p->link; //�̰� �߰��ϸ� ������ ȭ��ǥ ����!!!

	while (p != NULL){
		printf("->%d", p->data);
		p = p->link;
	}

	free(head); //C�� �������ݷ����� ���� ������
	return 0;

}