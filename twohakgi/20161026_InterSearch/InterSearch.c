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
	return -1; //없다
}

int main(){
	int i, key, index, n;
	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	n = sizeof(a) / sizeof(int);
	printf("찾을 대상 : ");
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n찾을 값 : ");
	scanf_s("%d", &key);
	index = interpolagtionSearch(a, n, key);
	if (index < 0)
		printf("\n찾고자 하는 값이 없다!\n");
	else
		printf("\n%d을(를) %d에서 찾았다!\n", key, index);

	return 0;
}