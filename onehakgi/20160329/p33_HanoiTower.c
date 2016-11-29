#include <stdio.h>

void HanoiTower(int n, char a, char b, char c){

	if (n == 1) printf("원판 %d, %c -> %c\n", n, a, c);

	else{
		HanoiTower(n - 1, a, c, b); //n-1 개를 A->B로 (B)
		printf("원판 %d, %c -> %c\n", n, a, c); //(M)
		HanoiTower(n - 1, b, a, c); //n-1 개를 B->C로 (C)

	}
}

int main(){

	int n = 4;
	HanoiTower(n, 'A', 'B', 'C'); //A는 출발지, C는 목적지
	return 0;

}