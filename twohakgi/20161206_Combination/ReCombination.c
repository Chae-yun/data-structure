#include <stdio.h>
#define R 3

int b[R] = { 0, }, cnt = 0;

void PrintReCom(){
	int i;
	cnt++;
	for (i = 0; i < R; i++)
		printf("%d  ", b[i]);
	printf("\n");
}

void ReCombination(int a[], int n, int r, int ii){
	int i;
	if (r >= R)PrintReCom();
	else{
		for (i = 0; i < n; i++){
			if (ii > i)
				continue;
			b[r] = a[i];
			ReCombination(a, n, r + 1, i);
		}
	}
}

int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	ReCombination(a, n, 0, -1);
	printf("조합 개수 : %d\n", cnt);

	return 0;
}