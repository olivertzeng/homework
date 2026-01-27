#include "stdio.h"

void pf(int i, int n) {
	for (int j = 0; j < n - (i - 1) / 2 - 2; j++) {
		printf(" ");
	}
	for (int j = 0; j < i; j++) {
		printf("*");
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n, times;
	scanf("%d", &times);
	for (int k = 0; k < times; k++) {
		scanf("%d", &n);
		n += 1;
		for (int i = 1; i < 2 * n - 1; i += 2) {
			pf(i, n);
		}
		for (int i = 2 * n - 5; i > 0; i -= 2) {
			pf(i, n);
		}
		printf("\n");
	}
	return 0;
}
