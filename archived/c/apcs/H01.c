#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a = 0, b = 0;
	for (int i = 0; i < 2; i++) {
		int num, x = 0, y = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &num);
			x += num;
		}
		for (int i = 0; i < 4; i++) {
			scanf("%d", &num);
			y += num;
		}
		a += (x > y);
		b += (x < y);
		printf("%d:%d\n", x, y);
	}
	if (a > b)
		printf("Win\n");
	else if (a < b)
		printf("Lose\n");
	else
		printf("Tie\n");
	return EXIT_SUCCESS;
}
