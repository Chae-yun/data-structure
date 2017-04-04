#include <stdio.h>

struct apex {
	double x;
	double y;
};

int lineCross(struct apex p1, struct apex p2, struct apex p3) {
	double top, bottom;
	double cross_x;
	//������ �� �Ʒ� ���� ����
	if (p1.y < p2.y) {
		top = p1.y;
		bottom = p2.y;
	}
	else {
		top = p2.y;
		bottom = p1.y;
	}
	//y���� ���� ������ �������� ����
	//������ : top,top�� 2, bottom,bottom�� 0, top,bottom �Ǵ� bottom,top�� 1�� ����
	if (p3.y < top || p3.y >= bottom)return 0;

	if (p1.x == p2.x) cross_x = p1.x; //�������̸�
	else {
		double gradient = (p2.x - p1.x) / (p2.y - p1.y);
		cross_x = (p3.y - p1.y)*gradient + p1.x;
	}
	//���� ���а� ���������� �����̸� �������� ����, �������̸� ����
	if (cross_x < p3.x)return 0;
	else return 1;
}

int apexIn(struct apex* polygon, int apex_num, struct apex point) {
	int cross = 0;

	//�ٰ����� ���а� ������ �� ���
	for (int i = 0; i<apex_num; ++i) {
		int j = i + 1;
		if (j >= apex_num)j = 0;
		if (lineCross(polygon[i], polygon[j], point))++cross;
	}
	//�����ϴ� ���� ¦���̸� ��, Ȧ���̸� ��
	if ((cross % 2) == 0)return 0;
	else return 1;
}

void main(void) {
	int n, inside;
	struct apex polygon[7] = { { 1, 5 }, { 8, 20 }, { 12, 14 }, { 15, 17 }, { 20, 15 }, { 17, 2 }, { 10, 7 } };
	struct apex point = { 8.2, 17 };
	n = sizeof(polygon) / sizeof(struct apex);
	inside = apexIn(polygon, n, point);
	if (inside == 1)printf("�־��� ��(%.2lf, %.2lf)�� �ٰ��� ���ο� �ֽ��ϴ�.\n", point.x, point.y);
	else printf("�־��� ��(%.2lf, %.2lf)�� �ٰ��� �ܺο� �ֽ��ϴ�.\n", point.x, point.y);
}