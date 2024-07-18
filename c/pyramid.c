#include "stdio.h"

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	n += 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
