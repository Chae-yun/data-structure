#include <stdio.h>
#define R 3

int b[R] = { 0, }, cnt = 0;

void PrintCom(){
	int i;
	cnt++;
	for (i = 0; i < R; i++)
		printf("%d  ", b[i]);
	printf("\n");
}

void Combination(int a[], int n, int r, int ii){
	int i;
	if (r >= R)PrintCom();
	else{
		for (i = r; i < n; i++){
			if (ii >= i)
				continue;
			b[r] = a[i];
			Combination(a, n, r + 1, i);
		}
	}
}

int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Combination(a, n, 0, -1);
	printf("조합 개수 : %d\n", cnt);

	return 0;
}