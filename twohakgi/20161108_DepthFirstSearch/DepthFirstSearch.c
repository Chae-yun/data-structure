#include <stdio.h>
#define MAX 7

int stack[MAX] = { 0, };
int top = -1;

void push(int value){
	if (top >= MAX - 1){
		printf("Overflow!\n");
		return;
	}
	stack[++top] = value;
}

int pop(){
	if (top == -1){
		//printf("\nUnderflow!\n");
		return -1;
	}
	return stack[top--];
}

void DepthFirstSearch(char v[], int a[][MAX]){
	int searchOk[MAX] = { 0, };
	int i, j;
	char ch;

	printf("\n시작 정점(A~G 중 입력) : ");
	scanf_s("%c", &ch, 1);
	for (i = 0; i < MAX; i++){
		if (ch == v[i])
			break;
	}
	printf("\n깊이우선탐색 순서 : %c", v[i]);
	searchOk[i] = 1;
	do{
		for (j = 0; j < MAX; j++){
			if (a[i][j] == 1 && searchOk[j] == 0){
				printf(" -> %c", v[j]);
				push(i);
				searchOk[j] = 1;
				i = j;
				break;
			}
		}
		if (j >= MAX)i = pop();
	} while (i >= 0);
	printf("\n\n");
}

int main(void){
	int i, j;
	char v[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	int a[MAX][MAX] = { { 0, 1, 1, 1, 0, 0, 0 }, { 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 1, 1 }, { 0, 0, 0, 0, 1, 0, 1 }, { 0, 0, 0, 0, 1, 1, 0 } };
	printf("\n\t\t인접 정점\n");
	for (i = 0; i < MAX; i++){
		for (j = 0; j < MAX; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	DepthFirstSearch(v, a);
	return 0;
}