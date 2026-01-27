#include "stdio.h"

int main(int argc, char *argv[]) {
	int n, times;
	scanf("%d", &times);
	for (int l = 0; l < times; l++) {
		scanf("%d", &n);
		n++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (i > 0) {
					printf(" ");
				}
			}
			for (int k = 0; k < i; k++) {
				printf("*");
			}
			if (l || i) {
				printf("\n");
			}
		}
	}
	return 0;
}
