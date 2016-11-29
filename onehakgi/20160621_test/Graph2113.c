#include <stdio.h>

int main(){
	int vertex[9] = { 'A', 'B', 'C', 'D,', 'E', 'F', 'G', 'H', 'I' };
	int graph[9][9] = {
		{ 0, 18, 10, 0, 0, 0, 0, 0, 0 },
		{ 18, 0, 0, 7, 3, 0, 0, 0, 0 },
		{ 10, 0, 0, 0, 11, 0, 0, 0, 0 },
		{ 0, 7, 0, 0, 30, 37, 0, 0, 0 },
		{ 0, 3, 11, 30, 0, 0, 8, 0, 0 },
		{ 0, 0, 0, 37, 0, 0, 25, 0, 17 },
		{ 0, 0, 0, 0, 8, 25, 0, 27, 0 },
		{ 0, 0, 0, 0, 0, 0, 27, 0, 55 },
		{ 0, 0, 0, 0, 0, 17, 0, 55, 0 } };
	int ver = 9, i, j, index, count = 0;
	char data;


	printf("\n출력 가:\n");
	printf("\n            < 인접 행렬 >\n");
	for (i = 0; i < ver; i++){
		for (j = 0; j < ver; j++)
			printf("%4d", graph[i][j]);
		printf("\n");
	}

	printf("\n정점 Index: ");
	scanf_s("%5d", &index);
	for (i = 0; i < ver; i++){
		if (graph[index][i] != 0)
			count++;
	}
	printf("정점 Index %d의 차수: %d", index, count);
	fflush(stdin);

	printf("\n\n정점 데이터: ");
	scanf_s("%c", &data);
	for (i = 0; i < ver; i++){
		if (vertex[i] == data){
			printf("정점 데이터 %c가 사용하는 Index: %d\n\n", data, i);
			break;
		}
	}

	return 0;
}