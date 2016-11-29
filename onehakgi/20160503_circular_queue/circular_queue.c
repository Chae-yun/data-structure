#include<stdio.h>
#define MAX 8
int rear = -1, front = 0, cnt = 0;
int cqueue[MAX] = { 0, };
enum bool{ false, true };

enum bool ADD(int data){
	if (cnt == MAX){
		printf("Circular Queue is Full!\n");
		return false;
	}
	rear = ++rear%MAX;
	cqueue[rear] = data;
	cnt++;
	return true;
}

int DELETE(){
	int value;
	if (cnt == 0){
		printf("Circular Queue is Empty!\n");
		return -1;
	}
	value = cqueue[front];
	front = ++front%MAX;
	cnt--;
	return value;
}

int main(){
	ADD(10); ADD(20); ADD(30); ADD(40); ADD(50); ADD(60); ADD(70); ADD(80); ADD(90);
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	printf("%d\n", DELETE());
	ADD(100); ADD(110); ADD(120);
	return 0;
}