#include <stdio.h>
#include <limits.h>

int fibo_srch(int a[], int n, int key){
	int index = 0, pos, k = 0;
	static int fib[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21 }; //�ð� ������ INT_MAX����

	while (fib[k] < n)k++;
	while (k > 0){
		pos = index + fib[--k];
		if ((pos >= n) || (key < a[pos]));
		else if (key > a[pos]){
			index = pos; //����ġ �����ʿ��� ã�ƾ� �Ǵ� ��� index�� �ٲ���
			k--;
		}
		else
			return pos; //ã�Ҵ�
	}
	return -1;
}

int main(){
	int a[] = { 5, 12, 17, 20, 25, 33, 38, 41, 59, 65, 68, 70, 75, 87, 92, 95, 99 };
	int n, search_data, i, pos;
	n = sizeof(a) / sizeof(int);
	printf("ã�� ��� : ");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\nã�� �� : ");
	scanf_s("%d", &search_data);
	pos = fibo_srch(a, n, search_data);
	if (pos < 0)
		printf("\nã���� �ϴ� ���� ����!\n");
	else
		printf("\n%d��(��) %d���� ã�Ҵ�!\n", search_data, pos);

	return 0;
}