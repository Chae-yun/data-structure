#include<stdio.h>

int main(){
	int i = 0, s;
	short a[16] = { 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 };

	printf("���ڸ� 0~16���� �ϳ� �Է��Ͻÿ� : ");
	scanf_s("%d", &s);

	while (i < 16){
		if (i < 16 - s)
			a[i] = a[i + s];
		else
			a[i] = 0;
		i = i + 1;
	}

	printf("��� : ");
	for (i = 0; i < 16; i++)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}