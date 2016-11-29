#include<stdio.h>

int main(){
	int i = 0, s;
	short a[16] = { 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 };

	printf("숫자를 0~16으로 하나 입력하시오 : ");
	scanf_s("%d", &s);

	while (i < 16){
		if (i < 16 - s)
			a[i] = a[i + s];
		else
			a[i] = 0;
		i = i + 1;
	}

	printf("결과 : ");
	for (i = 0; i < 16; i++)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}