#include <stdio.h>
#define SIZE 120000 //이 사이즈는 컴마다 다르다 컴안에서도 달라진다
int main(){
	int a[SIZE] = { 0, };
	int b[SIZE] = { 0, };
	printf("%d  %d\n", a[0], b[0]);
	return 0; //전체 데이터 크기가 1메가 넘으면 안됨??? 스택영역은 크게 허용하지 않음
	//보조기억장치로 하나하나
	//주기억장치로 모두 부름 -> 이게 바로 동적할당
}