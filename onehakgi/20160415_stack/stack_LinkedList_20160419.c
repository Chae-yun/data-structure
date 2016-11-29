#include <stdio.h>
#include <stdlib.h>
#define MAX 5 //이걸 주지 않으면 힙 영역에 자리가 있는 한 계속 만들어지기 때문에 이걸 만들어서 오버플로우도!
 
int cnt = 0; //오버플로우 체크
struct node{
	char data;
	struct node *link;
};
struct node *top = NULL; //처음은 널

enum bool{ false, true }; //이뉴머레이션을 쓰면 자동으로 처음이 0, 다음이 1
//c언어는 불타입이 없기 때문에 이런 것을 씀

enum bool Push(char item){ //item 받아서 노드생성하고 리스트끼리 연결하고 탑도 연결
	struct node *p; //지역변수니까 p는 푸쉬끝나면 소멸
	if (cnt >= MAX){
		printf("Stack Overflow!\n");
		return false;
	}
	//엘스 써도 안 써도 ok
	p = (struct node *)malloc(sizeof(struct node));
	p->data = item;
	p->link = top;
	top = p;
	cnt++;
	return true;
	//굳이 힙을 사용해 top이 널인지 체크할 필요가 없는 것이 왜더라... 딴생각함
}

char Pop(){
	struct node *p = top;
	char data; //준비
	if (cnt == 0){
		printf("Stack Underflow!\n");
		return '\0';
	}
	data = p->data; //top도 상관없다
	top = top->link;
	free(p);
	cnt--;
	return data;
}

int main(){
	struct node *p;
	char ch;
	Push('A');
	Push('B');
	Push('C');
	if ((ch = Pop()) != '/0') //=의 우선순위가 더 늦기 때문에 ()!!
		printf("%c\n", ch); //출력전에 가장 위에 있던 노드 사라짐~
	printf("\n<유효데이터>\n");
	while (top != NULL){//p가 널이 아니면 반복적으로 프리 해주자
		ch = top->data;
		printf("%c\n", ch);
		p = top;
		top = top->link;
		free(p);
	}
	return 0;
	//나머지 노드 안 없애주면 프로그램? 프로세스? 종료까지 메모리를 잡고 있음 다른 프로세스들이 못 씀
}