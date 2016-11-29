#include <stdio.h>
#define MAX 7

char stack[MAX]; //이건 다 쓸 거니까 전역!
int top = -1; //다른 데에서도 쓸 거니까 전역!

//스택은 따로 있는 게 아니라 만드는 것
int Push(char item){ //0 or -1
	if (top == MAX - 1){
		printf("Stack Overflow!\n");
		return - 1;
	}
	stack[++top] = item; //else 써도 되지만 귀찮
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
	printf("%c\n", Pop()); //언더플로우
	return 0;
}