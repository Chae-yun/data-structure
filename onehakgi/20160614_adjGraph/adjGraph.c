#include <stdio.h>
#define SIZE 5
int main(){
	int graph[SIZE][SIZE] = { 0 };
	int i, j, vertex, edge, e1, e2;
	char d;
	printf("\n ���� ���� : ");
	scanf_s("%d", &vertex);
	printf("\n ���� ���� : ");
	scanf_s("%d", &edge);
	for (i = 0; i < edge; i++){
		printf("\n ���� ���� ��ȣ : ");
		scanf_s("%d", &e1);
		printf("\n ���� �� ��ȣ : ");
		scanf_s("%d", &e2);
		fflush(stdin); //�̳� ���⼺ �Է¹��� �� �տ� ���� �� ĭ �ΰ� %c��� �ϸ� ��
		//�ܼ��̴� ���ϱ� ǥ�������?? ��ư �̷� �� ������ �ؾ� ��
		printf("\n ���⼺? (Y/N) : ");
		scanf_s("%c", &d);
		if (d == 'y' || d == 'Y'){
			graph[e1][e2] = 1;
		} else if (d == 'n' || d == 'N'){
			graph[e1][e2] = 1;
			graph[e2][e1] = 1;
		}
	}
	printf("\n\n ���� ���\n");
	for (i = 0; i < vertex; i++){
		for (j = 0; j < vertex; j++)
			printf("%5d", graph[i][j]);
		printf("\n");
	}
}