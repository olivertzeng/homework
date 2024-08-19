#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double n;
	scanf("%lf", &n);
	if (!n || n != (long long)n) {
		printf("X\n");
	} else if ((long long)n % 2) {
		printf("Odd\n");
	} else {
		printf("Even\n");
	}
	return EXIT_SUCCESS;
}
