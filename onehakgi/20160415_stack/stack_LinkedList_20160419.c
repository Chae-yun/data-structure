#include <stdio.h>
#include <stdlib.h>
#define MAX 5 //�̰� ���� ������ �� ������ �ڸ��� �ִ� �� ��� ��������� ������ �̰� ���� �����÷ο쵵!
 
int cnt = 0; //�����÷ο� üũ
struct node{
	char data;
	struct node *link;
};
struct node *top = NULL; //ó���� ��

enum bool{ false, true }; //�̴��ӷ��̼��� ���� �ڵ����� ó���� 0, ������ 1
//c���� ��Ÿ���� ���� ������ �̷� ���� ��

enum bool Push(char item){ //item �޾Ƽ� �������ϰ� ����Ʈ���� �����ϰ� ž�� ����
	struct node *p; //���������ϱ� p�� Ǫ�������� �Ҹ�
	if (cnt >= MAX){
		printf("Stack Overflow!\n");
		return false;
	}
	//���� �ᵵ �� �ᵵ ok
	p = (struct node *)malloc(sizeof(struct node));
	p->data = item;
	p->link = top;
	top = p;
	cnt++;
	return true;
	//���� ���� ����� top�� ������ üũ�� �ʿ䰡 ���� ���� �ִ���... ��������
}

char Pop(){
	struct node *p = top;
	char data; //�غ�
	if (cnt == 0){
		printf("Stack Underflow!\n");
		return '\0';
	}
	data = p->data; //top�� �������
	top = top->link;
	free(p);
	cnt--;
	return data;
}

int main(){
	struct node *p;
	char ch;
	Push('A');
	Push('B');
	Push('C');
	if ((ch = Pop()) != '/0') //=�� �켱������ �� �ʱ� ������ ()!!
		printf("%c\n", ch); //������� ���� ���� �ִ� ��� �����~
	printf("\n<��ȿ������>\n");
	while (top != NULL){//p�� ���� �ƴϸ� �ݺ������� ���� ������
		ch = top->data;
		printf("%c\n", ch);
		p = top;
		top = top->link;
		free(p);
	}
	return 0;
	//������ ��� �� �����ָ� ���α׷�? ���μ���? ������� �޸𸮸� ��� ���� �ٸ� ���μ������� �� ��
}