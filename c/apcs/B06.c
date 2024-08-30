#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	long double n;
	float tmp = 0;
	int grade = 0;
	scanf("%Lf", &n);
	if (n) {
		grade = 15;
		for (int i = 0; i < 16; i++) {
			if (n < tmp) {
				grade = i;
				break;
			}
			tmp += 5.29;
		}
	}
	printf("%d\n", grade);

	return EXIT_SUCCESS;
}
