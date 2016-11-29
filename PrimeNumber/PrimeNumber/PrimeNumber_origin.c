#include <stdio.h>
#include <math.h>
#include <time.h>

void main(void){
	int i, j, k = 0, d;
	int a = 100, b = 1000;
	clock_t t1, t2;

	t1 = clock();
	for (i = a; i <= b; i++){
		d = i / 2;
		for (j = 2; j <= d; j++){
			if (i%j == 0){
				k = 1;
				break;
			}
		}
		if (k == 0)printf("%d, ", i);
		k = 0;
	}
	t2 = clock();
	printf("\n%.3lf초 소요\n\n", (double)(t2 - t1) / 1000);

	t1 = clock();
	k = 0;
	for (i = a; i <= b; i++){
		if (i % 2 == 0)continue;
		d = (int)sqrt((double)i);
		for (j = 2; j <= d; j++){
			if (i%j == 0){
				k = 1;
				break;
			}
		}
		if (k == 0)printf("%d, ", i);
		k = 0;
	}
	t2 = clock();

	printf("\n%.3lf초 소요\n\n", (double)(t2 - t1) / 1000);
}