#include "stdio.h"

int main(int argc, char *argv[]) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
