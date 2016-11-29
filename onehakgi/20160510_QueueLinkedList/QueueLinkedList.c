#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node{
	int data;
	struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;
int cnt = 0;
enum bool{ false, true };

enum bool Add(int data){
	if (cnt >= MAX){
		printf("Queue is Full!!\n");
		return false;
	}
	if (rear == NULL){ //if(cnt==0)
		rear = (struct node*)malloc(sizeof(struct node));
		front = rear;
	}
	else{
		rear->link = (struct node*)malloc (sizeof(struct node));
		rear = rear->link;
	}
	rear->data = data;
	rear->link = NULL;
	cnt++;
	return true;
}

int Delete(){
	struct node *del;
	int value;
	if (cnt == 0){ //if(front==NULL)
		printf("Queue is Empty!!\n");
		return -1;
	}
	value = front->data;
	del = front;
	if (front == rear){ //if(cnt==1)
		front = NULL;
		rear = NULL;
	}
	else{
		front = front->link;
	}
	free(del);
	cnt--;
	return value;
}

int main(){
	Add(10); Add(20); Add(30);
	printf("%d\n", Delete());
	printf("%d\n", Delete());
	Add(80); Add(90);
	return 0;
}