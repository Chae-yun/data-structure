#include <stdio.h>
#include <limits.h>

int fibo_srch(int a[], int n, int key){
	int index = 0, pos, k = 0;
	static int fib[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 }; //시간 많으면 INT_MAX까지

	while (fib[k] < n)k++;
	while (k > 0){
		pos = index + fib[--k];
		if ((pos >= n) || (key < a[pos]));
		else if (key > a[pos]){
			index = pos; //비교위치 오른쪽에서 찾아야 되는 경우 index를 바꿔줌
			k--;
		}
		else
			return pos; //찾았다
	}
	return -1;
}

int main(){
	int a[] = { 5, 12, 17, 20, 25, 33, 38, 41, 59, 65, 68, 70, 75, 87, 92, 95, 99 };
	int n, search_data, i, pos;
	n = sizeof(a) / sizeof(int);
	printf("찾을 대상 : ");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n찾을 값 : ");
	scanf_s("%d", &search_data);
	pos = fibo_srch(a, n, search_data);
	if (pos < 0)
		printf("\n찾고자 하는 값이 없다!\n");
	else
		printf("\n%d을(를) %d에서 찾았다!\n", search_data, pos);

	return 0;
}