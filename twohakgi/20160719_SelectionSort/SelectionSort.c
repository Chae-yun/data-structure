#include<stdio.h>

void SelectionSort(int a[], int n){
	int i, j, min, index;

	for (i = 0; i < n - 1; i++){
		min = a[i];
		index = i;
		for (j = i + 1; j < n; j++)
		if (min > a[j]){
			min = a[j];
			index = j;
		}
		a[index] = a[i];
		a[i] = min;

	}
}

int main()
{
	int a[] = { 10, 7, 12, 4, 5, 8, 34, 17, 65, 23 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 :");
	for (i = 0; i < n; i++)printf("%d   ", a[i]);
	SelectionSort(a, n);
	printf("\n선택 정렬 후 : ");
	for (i = 0; i < n; i++)printf("%d   ", a[i]);
	return 0;
}