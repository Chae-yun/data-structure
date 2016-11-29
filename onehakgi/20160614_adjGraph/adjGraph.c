#include <stdio.h>
#define SIZE 5
int main(){
	int graph[SIZE][SIZE] = { 0 };
	int i, j, vertex, edge, e1, e2;
	char d;
	printf("\n 정점 개수 : ");
	scanf_s("%d", &vertex);
	printf("\n 간선 개수 : ");
	scanf_s("%d", &edge);
	for (i = 0; i < edge; i++){
		printf("\n 간선 시작 번호 : ");
		scanf_s("%d", &e1);
		printf("\n 간선 끝 번호 : ");
		scanf_s("%d", &e2);
		fflush(stdin); //이나 방향성 입력받을 때 앞에 공백 한 칸 두고 %c라고 하면 됨
		//콘솔이다 보니까 표준입출력?? 암튼 이런 거 때문에 해야 해
		printf("\n 방향성? (Y/N) : ");
		scanf_s("%c", &d);
		if (d == 'y' || d == 'Y'){
			graph[e1][e2] = 1;
		} else if (d == 'n' || d == 'N'){
			graph[e1][e2] = 1;
			graph[e2][e1] = 1;
		}
	}
	printf("\n\n 인접 행렬\n");
	for (i = 0; i < vertex; i++){
		for (j = 0; j < vertex; j++)
			printf("%5d", graph[i][j]);
		printf("\n");
	}
}