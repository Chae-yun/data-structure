#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000000 //동적할당하면 훨씬 크다
int main(){
	int *a;
	a = (int *)malloc(sizeof(int)*SIZE);//앞에 (int *)같은 거 안써주면 void로 리턴이 되기 때문에 써줘야 함
	//4를 쓰지 않는 이유는 컴마다 int의 사이즈가 다르므로
	//999999방까지 잡힘
	*(a + 0) = 5; //a[0] = 5;
	*(a + 1) = 10; //a[1] = 10;
	a[999999] = 999999;
	printf("%d %d %d\n", a[0], a[1], a[999999]);
	return 0; //힙영역은 크게 허용해준다
}