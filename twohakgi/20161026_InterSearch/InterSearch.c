#include <stdio.h>

int interpolagtionSearch(int a[], int n, int key){
	int left = 0, right = n - 1, pos;

	while (left <= right){
		if (a[left] < a[right]){
			pos = left + (right - left)*(key - a[left]) / (a[right] / a[left]);
			if (pos > right) pos = right;
			if (pos < left) pos = left;
		}
		else pos = left;

		if (key == a[pos]) return pos;
		else if (key > a[pos])left = pos + 1;
		else right = pos - 1;
	}
	return -1; //����
}

int main(){
	int i, key, index, n;
	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	n = sizeof(a) / sizeof(int);
	printf("ã�� ��� : ");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\nã�� �� : ");
	scanf_s("%d", &key);
	index = interpolagtionSearch(a, n, key);
	if (index < 0)
		printf("\nã���� �ϴ� ���� ����!\n");
	else
		printf("\n%d��(��) %d���� ã�Ҵ�!\n", key, index);

	return 0;
}