#include <stdio.h>

void BubbleSort(int a[], int n){
	int i = 0, j, temp, flag = 1;
	while (flag == 1){
		flag = 0;
		i++;
		for (j = 0; j < n - i; j++){
			if (a[j]>a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

int main(){
	int a[] = { 17, 8, 20, 11, 5, 12, 15, 7 };
	int i, n = sizeof(a) / sizeof(int);

	printf("정렬 전 : ");
	for (i = 0; i < n; i++)
		printf("%d   ", a[i]);
	BubbleSort(a, n);
	printf("\n버블 정렬 후 : ");
	for (i = 0; i < n; i++)
		printf("%d   ", a[i]);

	return 0;
}