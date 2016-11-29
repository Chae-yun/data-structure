#include <stdio.h>
int n;

void PreOrder(char a[], int num){
	if (num < n&&a[num] != NULL){
		printf("%c   ", a[num]);
		PreOrder(a, num * 2);
		PreOrder(a, num * 2 + 1);
	}
}

void InOrder(char a[], int num){
	if (num < n&&a[num] != NULL){
		PreOrder(a, num * 2);
		printf("%c   ", a[num]);
		PreOrder(a, num * 2 + 1);
	}
}

void PostOrder(char a[], int num){
	if (num < n&&a[num] != NULL){
		PreOrder(a, num * 2);
		PreOrder(a, num * 2 + 1);
		printf("%c   ", a[num]);
	}
}

int main(){
	char a[] = { NULL, 'A', 'B', 'C', 'D', 'E', NULL, 'F', NULL, NULL, 'G', NULL, NULL, NULL, 'H', 'I', NULL, NULL, NULL, NULL, NULL, 'J' };

	n = sizeof(a) / sizeof(char);

	printf("���� ���� (PreOrder) : ");
	PreOrder(a, 1);
	printf("\n");

	printf("���� ���� (InOrder) : ");
	InOrder(a, 1);
	printf("\n");

	printf("���� ���� (PostOrder) : ");
	PostOrder(a, 1);
	printf("\n");

	return 0;

}