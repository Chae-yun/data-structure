#include <stdio.h>

void ShellSort(int a[], int n){
	int i, j, t, key;
	for (t = n / 2; t >= 1; t /= 2){
		for (i = t; i < n; i++){
			key = a[i];
			for (j = i - t; j >= 0; j-=t){
				if (key >= a[j]) break; //반대로 하면 내림차순
				a[j + t] = a[j];
			}
			a[j + t] = key;
		}
	}
}

int main(){
	int a[] = { 17, 8, 20, 11, 5, 12, 15, 7 };
	int n = sizeof(a) / sizeof(int);
	int i;
	printf("정렬 전 : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]);
	ShellSort(a, n);
	printf("\n쉘 정렬 후 : ");
	for (i = 0; i < n; i++) printf("%5d", a[i]);

	return 0;
}