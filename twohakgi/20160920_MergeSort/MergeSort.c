#include <stdio.h>
#include <stdlib.h>

int n;

void Merge(int a[], int left, int mid, int right){
	int *b = (int *)malloc(sizeof(int)*(right - left + 1));
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right){
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	if (i <= mid){
		while (i <= mid)
			b[k++] = a[i++];
	}
	else{
		while (j <= mid)
			b[k++] = a[j++];
	}
	k = 0;
	for(i = left; i <= right; i++)
		a[i] = b[k++];
	free(b);
}

void Division(int a[], int left, int right){
	int mid;

	if (left < right){
		mid = (left + right) / 2;
		Division(a, left, mid);
		Division(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

int main(){
	int a[] = { 5, 33, 27, 12, 41, 25, 10, 56, 35, 18, 7 };
	int i;
	n = sizeof(a) / sizeof(int);
	Division(a, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");

	return 0;
}