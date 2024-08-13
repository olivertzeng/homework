#include "stdio.h"

int main(int argc, char *argv[]) {
	int n, times;
	scanf("%d", &times);
	for (int k = 0; k < times; k++) {
		scanf("%d", &n);
		n += 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				printf("*");
			}
			if (k || i) {
				printf("\n");
			}
		}
	}
	return 0;
}
