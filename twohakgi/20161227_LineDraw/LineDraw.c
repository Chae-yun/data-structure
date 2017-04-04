#include <stdio.h>
#include <math.h>
#define M 50
#define N 50

void swap(int *a, int *b) {
	int temp = *a;

	*a = *b;
	*b = temp;
}

int main(void) {
	int canvas[M][N] = { 0 };
	int x1, y1, x2, y2;
	int dx, dy, sdx = 0, sdy = 0;
	int x, y, i, j;

	printf("시작점: ");
	scanf_s("%d %d", &x1, &y1);
	printf("끝점: ");
	scanf_s("%d %d", &x2, &y2);

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) >= abs(dy) && x1 > x2) {
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	if (abs(dx) <= abs(dy) && y1 > y2) {
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	dx = x2 - x1;
	dy = y2 - y1;
	x = x1; y = y1;

	canvas[y][x] = 1;

	if (abs(dx) > abs(dy)) {
		while (x < x2) {
			x++;
			sdy += abs(dy);
			if (sdy >= dx) {
				y = (dx > 0 && dy > 0) ? ++y : --y;
				sdy -= dx;
			}
			canvas[y][x] = 1;
		}
	}
	else {
		while (y < y2) {
			y++;
			sdx += abs(dx);
			if (sdx >= dy) {
				x = (dx > 0 && dy > 0) ? ++x : --x;
				sdx -= dy;
			}
			canvas[y][x] = 1;
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (canvas[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}