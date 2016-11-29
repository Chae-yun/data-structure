#include <stdio.h>

void HanoiTower(int n, char a, char b, char c){

	if (n == 1) printf("���� %d, %c -> %c\n", n, a, c);

	else{
		HanoiTower(n - 1, a, c, b); //n-1 ���� A->B�� (B)
		printf("���� %d, %c -> %c\n", n, a, c); //(M)
		HanoiTower(n - 1, b, a, c); //n-1 ���� B->C�� (C)

	}
}

int main(){

	int n = 4;
	HanoiTower(n, 'A', 'B', 'C'); //A�� �����, C�� ������
	return 0;

}