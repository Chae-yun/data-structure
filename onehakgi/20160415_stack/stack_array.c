#include <stdio.h>
#define MAX 7

char stack[MAX]; //�̰� �� �� �Ŵϱ� ����!
int top = -1; //�ٸ� �������� �� �Ŵϱ� ����!

//������ ���� �ִ� �� �ƴ϶� ����� ��
int Push(char item){ //0 or -1
	if (top == MAX - 1){
		printf("Stack Overflow!\n");
		return - 1;
	}
	stack[++top] = item; //else �ᵵ ������ ����
	return 0;
}

int Pop(){
	if (top == -1){
		printf("Stack Underflow!\n");
		return -1;
	}
	return stack[top--];
}

int main(){
	Push('A');
	Push('B');
	printf("%c\n",Pop());
	printf("%c\n", Pop());
	printf("%c\n", Pop()); //����÷ο�
	return 0;
}