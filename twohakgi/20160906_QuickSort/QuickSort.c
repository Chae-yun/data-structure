#include <stdio.h>

void QuickSort(int *a, int left, int right){
	int i, j, key, temp;
	if (left < right){
		key = a[left];
		i = left;
		j = right;
		while (i < j){
			while (i < right && a[i] <= key)i++;
			while (j > left && a[j] >= key)j--;
			if (i < j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		a[left] = a[j];
		a[j] = key;

		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}

int main(){
	int a[] = { 15, 7, 2, 20, 33, 17, 26, 5, 21, 30, 27, 29, 11, 10, 3 };
	int n = sizeof(a) / sizeof(int);
	int i;
	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);
	QuickSort(a, 0, n - 1);
	printf("\n퀵 정렬 후 : ");
	for (i = 0; i < n; i++) printf("%4d", a[i]);

	return 0;
}