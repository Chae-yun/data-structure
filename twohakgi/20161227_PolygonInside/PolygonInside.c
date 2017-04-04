#include <stdio.h>

struct apex {
	double x;
	double y;
};

int lineCross(struct apex p1, struct apex p2, struct apex p3) {
	double top, bottom;
	double cross_x;
	//꼭지점 위 아래 범위 결정
	if (p1.y < p2.y) {
		top = p1.y;
		bottom = p2.y;
	}
	else {
		top = p2.y;
		bottom = p1.y;
	}
	//y범위 내에 없으면 교차하지 않음
	//꼭지점 : top,top은 2, bottom,bottom은 0, top,bottom 또는 bottom,top은 1로 계산됨
	if (p3.y < top || p3.y >= bottom)return 0;

	if (p1.x == p2.x) cross_x = p1.x; //수직선이면
	else {
		double gradient = (p2.x - p1.x) / (p2.y - p1.y);
		cross_x = (p3.y - p1.y)*gradient + p1.x;
	}
	//점이 선분과 교차점보다 왼쪽이면 교차하지 않음, 오른쪽이면 교차
	if (cross_x < p3.x)return 0;
	else return 1;
}

int apexIn(struct apex* polygon, int apex_num, struct apex point) {
	int cross = 0;

	//다각형의 선분과 교차점 수 계산
	for (int i = 0; i<apex_num; ++i) {
		int j = i + 1;
		if (j >= apex_num)j = 0;
		if (lineCross(polygon[i], polygon[j], point))++cross;
	}
	//교차하는 수가 짝수이면 밖, 홀수이면 안
	if ((cross % 2) == 0)return 0;
	else return 1;
}

void main(void) {
	int n, inside;
	struct apex polygon[7] = { { 1, 5 }, { 8, 20 }, { 12, 14 }, { 15, 17 }, { 20, 15 }, { 17, 2 }, { 10, 7 } };
	struct apex point = { 8.2, 17 };
	n = sizeof(polygon) / sizeof(struct apex);
	inside = apexIn(polygon, n, point);
	if (inside == 1)printf("주어진 점(%.2lf, %.2lf)은 다각형 내부에 있습니다.\n", point.x, point.y);
	else printf("주어진 점(%.2lf, %.2lf)은 다각형 외부에 있습니다.\n", point.x, point.y);
}